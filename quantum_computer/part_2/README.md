# Quantum Computer Simulator – Part 2 (Grover’s Search)

This extends the Part 1 quantum simulator to implement Grover’s Search Algorithm, based on the ENCCS "Quantum Computing for Beginners" tutorial.

---
## Overview

Grover’s algorithm is a quantum search technique that finds a marked item in an unsorted database in **O(√N)** time, offering a faster search over classical search.

This implementation shows the phase oracle construction, amplification, diffusion steps and iterative probability boosting

## Files

grover.py = implements Grover’s search using the quantum simulator

## Requirements
- Python 3  
- NumPy
  
## Running the Code
 python3 grover.py

---
## Example Output
Result: 111101


The algorithm increases the probability of the correct solution over multiple iterations where results may require reruns to improve the overall correctness.
This demonstrates quantum speedup.
