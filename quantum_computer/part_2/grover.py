import numpy as np

# simulator
workspace = np.array([[1.0]])
namestack = []

def pushQubit(name, weights):
    global workspace, namestack
    
    if workspace.shape == (1,1):
        namestack = []
    
    namestack.append(name)
    weights = np.array(weights)
    weights = weights / np.linalg.norm(weights)
    
    workspace = np.reshape(workspace, (1,-1))
    workspace = np.kron(workspace, weights)

def tosQubit(name):
    global workspace, namestack
    
    k = len(namestack) - namestack.index(name)
    
    if k > 1:
        namestack.append(namestack.pop(-k))
        workspace = np.reshape(workspace, (-1,2,2**(k-1)))
        workspace = np.swapaxes(workspace,-2,-1)

def applyGate(gate, *names):
    global workspace
    
    for name in names:
        tosQubit(name)
    
    workspace = np.reshape(workspace, (-1, gate.shape[0]))
    np.matmul(workspace, gate.T, out=workspace)

def probQubit(name):
    global workspace
    
    tosQubit(name)
    workspace = np.reshape(workspace, (-1,2))
    
    prob = np.linalg.norm(workspace, axis=0)**2
    return prob / prob.sum()

def measureQubit(name):
    global workspace, namestack
    
    prob = probQubit(name)
    result = np.random.choice(2, p=prob)
    
    workspace = workspace[:, [result]] / np.sqrt(prob[result])
    namestack.pop()
    
    return result

# Gates
X_gate = np.array([[0,1],
                   [1,0]])

H_gate = np.array([[1,1],
                   [1,-1]]) / np.sqrt(2)

Z_gate = np.array([[1,0],
                   [0,-1]])


# mark state: 111101 (example)
def sample_phaseOracle(qubits):
    applyGate(X_gate, qubits[1])       # flip qubit 1
    applyGate(Z_gate, *namestack)      # phase flip
    applyGate(X_gate, qubits[1])       # restore

# zero-state oracle
def zero_phaseOracle(qubits):
    for q in qubits:
        applyGate(X_gate, q)
    
    applyGate(Z_gate, *namestack)
    
    for q in qubits:
        applyGate(X_gate, q)

# Grovers search
def groverSearch(n):
    global workspace
    
    workspace = np.array([[1.0]])
    
    qubits = list(range(n))
    
    # initialize superposition
    for q in qubits:
        pushQubit(q, [1,1])
    
    iterations = int(np.pi/4 * np.sqrt(2**n))
    
    for _ in range(iterations):
        sample_phaseOracle(qubits)
        
        for q in qubits:
            applyGate(H_gate, q)
        
        zero_phaseOracle(qubits)
        
        for q in qubits:
            applyGate(H_gate, q)
    
    # measure result
    result = ""
    for q in reversed(qubits):
        result += str(measureQubit(q))
    
    print("Result:", result)

if __name__ == "__main__":
    groverSearch(6)
