# Week 3: Introduction to MPI


## MPI Hello World Benchmark

## Compilation
mpicc hello_mpi.c -o bin/hello_mpi

## Exicution
mpirun -np 1 bin/hello_mpi
mpirun -np 2 bin/hello_mpi

note: could only handle 2 maximum, this is true for all future tests

---

## Observations

- Increasing the number of MPI processes increases CPU utilisation.
- Wall clock time does not scale linearly due to communication overhead betwee>
- Total CPU time increases because multiple processes execute simultaneously.

---
## MPI structure


MPI allows programs to run across multiple processes simultaneously. Each process is assigned a unique rank, and all processes execute the same program but behave differently depending on that rank.

### Program Flow

- MPI_Init() = starts the MPI environment  
- MPI_Comm_rank() = gets rank  
- MPI_Comm_size() = gets total number of processes  
- MPI_Finalize() = ends MPI execution

Each process runs code based on rank  

### Process Roles

- Rank 0 (root process): coordinates execution and collects results  
- Rank > 0 (worker processes): perform computation and sends results to root  

### Communication Model

MPI uses a fan-in pattern where multiple workers send results to a single root process using MPI_Send and MPI_Recv.


---

The goal of MPI vector addition is to benchmark a serial implementation of vector addition before introducing MPI parallelism.

### Vector Modification

The vector was made more significant using:

vector[i] = i * 2 + 3


## Compilation
gcc vector_serial.c -o bin/vector_serial

## Exicution 
time ./bin/vector_serial 1000000
time ./bin/vector_serial 10000000

---

## Analysis
Execution time increases linearly with input size and is the program runs on a single CPU core without parallelism being used

---

## Conclusion
Serial programs execute continuously on a single core. Where MPI allows multiple processes to be used. Performance improvements depend on the size and communication overhead between processes.

