import numpy as np

workspace = np.array([[1.0]])
namestack = []

def pushQubit(name, weights):
    global workspace, namestack
    
    if workspace.shape == (1,1):
        namestack = []
    
    namestack.append(name)
    
    weights = np.array(weights, dtype=workspace.dtype)
    weights = weights / np.linalg.norm(weights)
    
    workspace = np.reshape(workspace, (1, -1))
    workspace = np.kron(workspace, weights)

def tosQubit(name):
    global workspace, namestack
    
    k = len(namestack) - namestack.index(name)
    
    if k > 1:
        namestack.append(namestack.pop(-k))
        workspace = np.reshape(workspace, (-1, 2, 2**(k-1)))
        workspace = np.swapaxes(workspace, -2, -1)

def applyGate(gate, *names):
    global workspace
    
    for name in names:
        tosQubit(name)
    
    workspace = np.reshape(workspace, (-1, gate.shape[0]))
    np.matmul(workspace, gate.T, out=workspace)

def probQubit(name):
    global workspace
    
    tosQubit(name)
    workspace = np.reshape(workspace, (-1, 2))
    
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

CNOT_gate = np.array([
    [1,0,0,0],
    [0,1,0,0],
    [0,0,0,1],
    [0,0,1,0]
])


# Test run
if __name__ == "__main__":
    workspace = np.array([[1.0]])

    pushQubit("Q1", [1,0])
    applyGate(H_gate, "Q1")

    print("Probabilities:", probQubit("Q1"))
    print("Measurement:", measureQubit("Q1"))
