# Week 1: Performance and Parallelism

## Overview

This tests the performance differences between **C and Python** using external timing (Linux `time` command) and internal timing. This is to understand how execution time varies across different operations and programming languages.

---
## Instructions

Organise all C programs using `gcc`:

gcc hello_world.c -o bin/hello_world
gcc repeat_adder.c -o bin/repeat_adder
gcc time_print.c -o bin/time_print
gcc triangular.c -o bin/triangular
gcc file_write.c -o bin/file_write
gcc file_read.c -o bin/file_read

Run the programs:

Hello World Benchmark
time python3 hello_world.py
time ./bin/hello_world


Repeat adder benchmark:
time ./bin/repeat_adder 1000000 5
time python3 repeat_adder.py 1000000 5


File Tests:
./bin/file_write 10000
python3 file_write.py 10000

./bin/file_read
python3 file_read.py

---
## Results
Task	       Input	C Time (s)	Python Time (s)
Repeat Adder	1e6	    0.009	0.072
File Write	1e4	    0.0015	0.0026
File Read	-	    0.0017	0.0006

---

## Analysis
Changing the repeat adder shows that C has significantly better results than Python for computational workloads due to compilation into machine code. Initial tests with small inputs produced results that wheren't as consitent. Increasing input sizes produced more reliable and meaningful results. Other results show smaller performance differences between C and Python, as both are limited by access speed rather than CPU performance. In some tests Python performed slightly better due to efficient file handling. From this the conclusion drawn is:
C is faster for CPU heavy tasks and python is slower due to the fact it requires more computational resources and memory. File read or write reduces performance differences between languages.
Small benchmarks are unreliable, larger inputs are required for accurate results, this shows that system factors can affect timing results.

