#ifndef SYSTEM_H
#define SYSTEM_H
#include "qubit.h"
#include <eigen3/unsupported/Eigen/KroneckerProduct>

class System {
public:
    int n;
    Matrix<CD, Dynamic, 1> s;
    vector<Qubit> qubits;

    System(int num_qubits);
    void PrintDiracNotation(int u = 0);

    void SingleQubitGate(int target, Matrix<CD,2,2> m);
    void HGate(int target);
    void XGate(int target);
    void YGate(int target);
    void ZGate(int target);
    void SGate(int target);
    void SDaggerGate(int target);
    void TGate(int target);
    void TDaggerGate(int target);


    void CNOT(int control, int target);
    void SWAP(int q0, int q1);
};

#endif
