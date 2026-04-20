# PHY1090 - HPQC - Individual Practical Portfolio

The first half of the individual portfolio is based on the HPC elements of the course, while the second half is based on the QC parts of the course. You must complete all practical assignments in Week 1-9 and present the code you developed in a GitHub repository.
---
## Submission:
Use the link provided to submit a link to a GitHub repository in which you present your
practical work. The repository must be public and kept accessible until graduation.

## Assessment criteria:
The two elements that will be considered when marking this portfolio are the code and
its associated documentation. Each will be considered under the following categories:

### Functionality 30%:
This is primarily assessed through the code: does the code compile and run, does it
produce the outputs that are required, can it be rerun easily for evaluation etc.
Documentation plays a part in this criterion in that the instructions provided in the
documentation should be sufficient for a reader to run the code.

### Accessibility 20%:
This is primarily assessed through the documentation. Is the documentation clear on
how the code is to be used, what it’s for, what outputs can be expected and so on. Code
can contribute to this element by ensuring that inputs and outputs are clearly labelled
and by giving feedback to the user if they provide incorrect inputs.

### Maintainability 20%:
Both code and documentation contribute heavily to this factor. Your code should be wellstructured, using functions or classes where appropriate. This ensures that a later
developer or code maintainer can update or expand the functionality without needing to
parse many complex elements of the code. Good naming conventions for functions,
variables and programs helps. Use of comments and/or docstrings is appropriate here.
Meanwhile, developer-level documentation should describe what the code is supposed to
do. The use of natural language and/or pseudocode descriptions is required, while the
use of block diagrams, flowcharts etc are encouraged.

### Reporting 30%:
This is assessed solely through the reporting. In your exercises, you have been asked to
assess the performance of code in a variety of ways and environments. This includes
comparing various algorithms and languages on runtime, communications etc. Here,
you’ll be assessed on the completeness, clarity and reproducibility of your results. Use of
tables, graphs and so on is strongly encouraged.

---

## Performance and Parallelism 
This activity will compare the performance of C and Python by timing different programs using both the Linux time command and internal timing methods. It will investigate how execution time changes for CPU-heavy tasks and file input/output, and how performance scales with increasing input sizes.

## Introduction to MPI
This activity introduces MPI. This is done by exploring how programs can run across multiple processes. It involves writing and running an MPI “ Hello World” program, comparing execution with different numbers of processes, and using timing tools to observe performance changes. It also includes analysing an existing MPI program, understanding how processes communicate, and developing a parallel version of a vector addition program to compare against a serial  implementation.


## MPI Communications
This activity explores MPI communication methods by implementing and testing point-to-point and collective communication routines. It involves modifying and restructuring MPI programs to improv eclarity, experimenting with different send types, and measuring communication performance using internal timing functions. It also includes developing a ping-pong program to estimate latency and bandwidth, and comparing different collective communication strategies such as broadcast, scatter, gather, and reduce to understand their efficiency and behaviour.


## Communications and Topologies 
This activity explores how a oscillating string can be simulated in C and then extended into a parallel MPI version. It involves improving a serial wave model by removing hard-coded values, implementing a more realistic physical model, and parallelising the computation using MPI by dividing the string across processes and communicating boundary values. It also includes comparing serial and parallel performance to understand when parallelisation becomes beneficial depending on problem size.











