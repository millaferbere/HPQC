# Performance and Parallelism Assignment

## Overview
This assignment compares execution time in C and Python using:
- time command
- scaling experiments
- file I/O
- MPI parallelism

---

## Part 3: File I/O Benchmarking

File write and read operations were measured using both Python and C.

### Observations:
- Writing to file is slower than reading  
- Runtime increases with file size  
- C performs faster due to lower overhead and direct system calls  
- File I/O dominates performance compared to computation  
