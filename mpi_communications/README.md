# Week 4: MPI Communications

## Overview

This program investigates MPI communication patterns, including point-to-point communication, latency measurement, bandwidth estimation, and collective operations.

---

## MPI Communication Test

The program comm_test_mpi.c was compiled and executed using different numbers of processes:


mpicc comm_test_mpi.c -o bin/comm_test_mpi
mpirun -np 4 bin/comm_test_mpi


### Observations
Output order varies between executions while communication remains correct regardless of ordering and MPI execution is non-deterministic in scheduling

---
## Refactoring

The original single-function program was split into:

root_task()
client_task()
check_args()
check_uni_size()
check_task()

This improved readability and overall flexibility of the function.

---
## Send Types Tested
MPI_Send
MPI_Ssend
MPI_Bsend
MPI_Rsend
MPI_Isend

### Observations
- MPI_Send = is most stable
- MPI_Ssend = blocks execution
- MPI_Bsend = requires buffering
- MPI_Rsend = is unsafe without guarantees
- MPI_Isend = requires synchronization
---

## Analysis

MPI communication timing was measured using MPI_Wtime.

### Observation
Communication time is extremely small with a high variance between runs this is because single measurements are unreliable.

---

## Ping Pong Benchmark

A two-process ping-pong program was used to measure latency.

### Observations
Increasing number of pings improves stability and the latency converges for large iteration counts

---
## Bandwidth Test

The program was extended to transmit arrays of varying sizes.

### Observations
Small messages = latency dominated
Large messages = bandwidth dominated
The linear model can be used to estimate latency and bandwidth
---

## Collective Communication

The following MPI operations were tested:

MPI_Bcast
MPI_Scatter
MPI_Gather
MPI_Reduce


### Observations
MPI_Scatter = is efficient for distributed workloads
MPI_Reduce =  is optimal for aggregation
Manual communication is least efficient

---
## Conclusion

MPI performance depends strongly on communication pattern, message size, and number of processes. Collective operations provide significant performance advantages over manual point-to-point communication in structured workloads.
