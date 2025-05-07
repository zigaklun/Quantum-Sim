# QubitSim

QubitSim is a simple quantum computing simulator written in C++ that allows you to simulate quantum gates, measure qubits, and experiment with quantum algorithms. It uses the Eigen library for matrix operations and provides a framework for building and testing quantum circuits.

---

## Features
- Simulate single-qubit and multi-qubit gates (X, Y, Z, H, S, T, CNOT, SWAP, Toffoli, etc.).
- Measure individual qubits or the entire quantum state.
- Visualize quantum states in Dirac notation.
- Build and test quantum algorithms in `main.cpp`.

---

## Installation

### Prerequisites
1. **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., `g++`).
2. **Eigen Library**: The project uses the Eigen library for matrix operations.

### Installing Eigen
You can install Eigen by downloading it from the official website or using a package manager.
```bash
  sudo apt-get install libeigen3-dev
```

### Compilation
To compile the project run the following command:
```bash
g++ -o main main.cpp system.cpp qubit.cpp test_env.cpp -I /usr/include/eigen3
```
If its not working replace the path to eigen with your path.

### Run the program
```bash
./main
```

### Project Structure

- **`system.cpp` and `system.h`**: Define the `System` class for simulating quantum gates and states.
- **`qubit.cpp` and `qubit.h`**: Define the `Qubit` class for individual qubits.
- **`test_env.cpp` and `test_env.h`**: Define the `Test_env` class for simulating measurements.
- **`main.cpp`**: Entry point for the program. Use this file to build and test quantum algorithms.


### References

- [Eigen Library Documentation](https://eigen.tuxfamily.org/dox/GettingStarted.html)
- Quantum Computing Basics (included in `Learn Quantum/Quantum Computing Basics.md`)
- Nielsen & Chuang: Quantum Computation and Quantum Information
- Online resources like Quantum Inspire and Medium articles on quantum computing.
