#ifndef SYSTEM_H
#define SYSTEM_H
#include "qubit.h"

class System {
public:
    int n = 0;
    Matrix<CD,Dynamic,1> s;
    vector<Qubit*> qubits;
    System(int num_qubits);
    Qubit& operator()(int index);
    //void AddQubit(Qubit &q);
    void PrintDiracNotation(int u = 0);
    //string formatCoefficient(CD c);
    void ProbabilityOfMeasuring(string bin);
    void CNOT(int control, int target);
    void Update();
private:
    Matrix<CD,Dynamic,1> TensorProduct(const Matrix<CD,Dynamic,1> a ,const Matrix<CD,2,1> b );
    void printBinary(int i, int n);
    VI toBinary (int i, int n);
    int binaryVectorToInt(const VI& binaryVector);
};

#endif
