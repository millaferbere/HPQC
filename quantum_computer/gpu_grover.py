import torch as pt
import numpy as np
import time

pt.autograd.set_grad_enabled(False)

device = pt.device("cuda" if pt.cuda.is_available() else "cpu")
print("Using device:", device)

workspace = pt.tensor([[1.0]], device=device)
namestack = []

def pushQubit(name, weights):
    global workspace, namestack
    
    if workspace.shape == (1,1):
        namestack = []
    
    namestack.append(name)
    
    weights = np.array(weights)
    weights = weights / np.linalg.norm(weights)
    
    weights = pt.tensor(weights, device=device, dtype=workspace.dtype)
    
    workspace = pt.reshape(workspace, (1, -1))
    workspace = pt.kron(workspace, weights)

def tosQubit(name):
    global workspace, namestack
    
    k = len(namestack) - namestack.index(name)
    
    if k > 1:
        namestack.append(namestack.pop(-k))
        workspace = pt.reshape(workspace, (-1, 2, 2**(k-1)))
        workspace = pt.swapaxes(workspace, -2, -1)

def applyGate(gate, *names):
    global workspace
    
    for name in names:
        tosQubit(name)
    
    workspace = pt.reshape(workspace, (-1, gate.shape[0]))
    
    gate = pt.tensor(gate.T, device=device, dtype=workspace.dtype)
    
    sub = workspace[:,-gate.shape[0]:]
    
    if device.type == "cuda":
        pt.matmul(sub, gate, out=sub)
    else:
        sub[:] = pt.matmul(sub, gate)

def probQubit(name):
    global workspace
    
    tosQubit(name)
    workspace = pt.reshape(workspace, (-1, 2))
    
    prob = pt.linalg.norm(workspace, axis=0)**2
    prob = prob.cpu().numpy()
    
    return prob / prob.sum()

def measureQubit(name):
    global workspace, namestack
    
    prob = probQubit(name)
    result = np.random.choice(2, p=prob)
    
    workspace = workspace[:, [result]] / np.sqrt(prob[result])
    namestack.pop()
    
    return str(result)

X_gate = np.array([[0,1],[1,0]])
H_gate = np.array([[1,1],[1,-1]]) / np.sqrt(2)
Z_gate = np.array([[1,0],[0,-1]])


def zero_phaseOracle(qubits):
    for q in qubits:
        applyGate(X_gate, q)
    
    applyGate(Z_gate, *namestack)
    
    for q in qubits:
        applyGate(X_gate, q)

def sample_phaseOracle(qubits):
    applyGate(X_gate, qubits[1])
    applyGate(Z_gate, *namestack)
    applyGate(X_gate, qubits[1])


def groverSearch(n, printProb=True):
    global workspace
    
    qubits = list(range(n))
    
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
        
        if printProb:
            print(probQubit(qubits[0]))
    
    result = "".join(measureQubit(q) for q in reversed(qubits))
    print("Result:", result)

if __name__ == "__main__":
    t = time.time()
    
    groverSearch(16, printProb=False)
    
    print("Time:", time.time() - t, "s")
    print("Device used:", device)
