# Quantum Computer Simulator – Part 3 (GPU Acceleration)

This part extends the quantum computer simulator by introducing GPU acceleration using PyTorch.

## Overview

Part 3 improves performance by moving the quantum state (workspace) to GPU memory using PyTorch tensors. This allows faster simulation of larger quantum systems compared to the NumPy-based implementation.

## Key Features

- GPU-accelerated quantum state simulation (CUDA support if available)
- PyTorch tensor-based state vector operations
- Optimized quantum gate application
- Compatible CPU fallback if GPU is not available

## Requirements
- Python 3
- PyTorch
- NumPy

## Install dependencies:
pip install torch numpy

## Files
gpu_grover.py – GPU-enabled Grover’s search implementation

python3 gpu_grover.py


This automatically uses GPU if available if not it runs on the CPU, this demonstrates Grover’s search with improved performance over CPU only simulation.
