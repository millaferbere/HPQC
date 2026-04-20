# HPQC Communicators and Topologies

These programs simulate the motion of a vibrating 1D string. The model uses C and includes both a serial and parallel MPI implementation. The output is displayed using a Python code .

The model shows the simulation of wave motion, serial computation in C, parallel computing using MPI and data visualisation using Python, using matplotlib.


---

## Instructions

### Serial

Compile the serial program:

gcc src/string_wave.c -o bin/string_wave -lm

## MPI

Compile the parallel version:

mpicc src/string_wave_mpi.c -o bin/string_wave_mpi -lm

## Running the program and the serial
./bin/string_wave 50 5 25 data/output.csv

Arguments:
- points = number of points on the string
- cycles = number of oscillation cycles
- samples = number of samples per cycle
- output_file = output CSV file path

MPI execution
mpirun -np 2 ./bin/string_wave_mpi 100 5 25 data/output.csv


##Visual display

To generate the gif with the showing the evolution of the vibrating string over time from the output:

python3 src/animate_line_file.py data/output.csv result.gif

---
## Model
### Original Model

The original model  uses a simple propagation rule, where each point copies the value of the previous, the first point is driven by a sine wave function and the motion propagates in one direction only.
This produces a visually smooth motion. This is however not physically realistic, as it does not include restoring forces.

### Improved Model

The improved model replaces the simple repeating behaviour with a finite difference approximation of the wave equation. Where each interior point is updated using its current value as well as the values of the points next to it.

This means the curve updates so if a point is higher than the point next to it, it will decrease and if a point is lower than the point next to it, it should increase.

This model has a few key improvements such as wave-like propagation in both directions and more physically realistic oscillations, which in turn improved stability and realism.

---
## MPI Strategy

The MPI implementation splits the string into sections across processes, each MPI process handles a portion of the string and computation is performed locally per process. Each process is ranked where rank 0 is responsible for the first section of the string and acts as the root process.

Each process communicates with the processes next to it in order to exchange boundary values so that the wave can propagate correctly across process boundaries. This ensures that the interaction between adjacent sections of the string is maintained even when distributed across multiple processes. At the end of each timestep, the results are gathered back to the root process so that the full string can be reconstructed and written to a single output file.

---


## Analysis
From this it can be seen that the serial version performs best for small input sizes while the MPI version introduces communication overhead. This becomes noticeable for large numbers of points and the efficiency improves as the workload per process increases.

For smaller problem sizes the communication cost outweighs the benefits of parallelisation, meaning the serial version performs better. As the number of points increases, the MPI becomes more efficient as the computational workload dominates over costs.

This shows that the benefit of parallelisation depends strongly on the size of the problem, and that there is a threshold, the MPI version then becomes more viable and scalable than the serial version.
---

### Necessary  Python installs:
python3 -m pip install --user numpy matplotlib pandas


## How to Run Full Workflow

### 1. Compile
gcc src/string_wave.c -o bin/string_wave -lm
mpicc src/string_wave_mpi.c -o bin/string_wave_mpi -lm

### 2. Run simulation
./bin/string_wave 50 5 25 data/output.csv

### 3. Run  MPI
mpirun -np 4 ./bin/string_wave_mpi 100 5 25 data/output.csv

### 4. Plot
python3 src/animate_line_file.py data/output.csv result.gif


---
## Conclusion
This activity shows the numerical simulation of wave propagation, how it can transitions from serial to parallel computing with the use of MPI for distributed computation. It also shows an improved physical modelling.
