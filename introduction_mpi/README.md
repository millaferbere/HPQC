# Week 3: Introduction to MPI

## Part 2: Understanding MPI Structure

MPI (Message Passing Interface) allows programs to run across multiple processes simultaneously. Each process is assigned a unique rank, and all processes execute the same program but behave differently depending on that rank.

### Program Flow

- MPI_Init() starts the MPI environment  
- MPI_Comm_rank() gets process ID (rank)  
- MPI_Comm_size() gets total number of processes  
- Each process executes code depending on rank  
- MPI_Finalize() ends MPI execution  

### Process Roles

- Rank 0 (root process): coordinates execution and collects results  
- Rank > 0 (worker processes): perform computation and send results to root  

### Communication Model

MPI uses a fan-in pattern where multiple workers send results to a single root process using MPI_Send and MPI_Recv.


---

## Part 3: Vector Addition (Serial Baseline)

### Objective

The goal is to benchmark a serial implementation of vector addition before introducing MPI parallelism.

### Vector Modification

The vector was made non-trivial using:

```c
vector[i] = i * 2 + 3;


## Compilation 
gcc vector_serial.c -o bin/vector_serial

## Exicution 
time ./bin/vector_serial 1000000
time ./bin/vector_serial 10000000

---

## Analysis
Execution time increases linearly with input size
Program runs on a single CPU core
No parallelism is used

---
## MPI Hello World Benchmark

## Compilation
mpicc hello_mpi.c -o bin/hello_mpi

## Exicution
mpirun -np 1 bin/hello_mpi
mpirun -np 2 bin/hello_mpi

note: could onlu handle 2 maximum 

---

## Observations

- Increasing the number of MPI processes increases CPU utilisation.
- Wall clock time does not scale linearly due to communication overhead between processes.
- Total CPU time increases because multiple processes execute simultaneously.

---

## Conclusion

- Serial programs execute sequentially on a single core.
- MPI enables distributed execution across multiple processes.
- Performance improvements depend on problem size and communication overhead between processes.

