# Quantum Computer Simulator – Part 1

This implements a simple quantum computer simulator in Python, based on the ENCCS "Quantum Computing for Beginners" tutorial (Part 1).

## Overview

The simulator models a quantum computer using a state vector and supports basic quantum operations like:

- pushQubit – add a qubit to the system
- applyGate – apply quantum gates (matrix operations)
- tosQubit – reorder qubits
- measureQubit – measure and collapse a qubit

The implementation uses NumPy for vector and matrix operations.

## Files
simulator.py – main implementation of the simulator
.gitignore – ignores Python cache files

## Requirements
- Python 3
- NumPy

## Running the Code
python3 simulator.py

## Example output:

Probabilities: [0.5 0.5]
Measurement: 1

The simulator demonstrates basic quantum concepts such as superposition and measurement. Results will vary due to randomness in measurement.
