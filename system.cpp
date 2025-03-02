#include "system.h"
#include "qubit.h"
#include <cmath>

void printBinary(int i, int n) {
    for (int j = 0; j < n; j++) { // LSB-first (Qiskit convention)
        cout << ((i >> j) & 1);
    }
}

System::System(int num_qubits) : n(num_qubits) {
    s.resize(pow(2, n));
    s.setZero();
    s(0) = 1;
    for (int i = 0; i < n; i++) {
        qubits.emplace_back(this, i);
    }
}

void System::PrintDiracNotation(int u) {
    bool first = true;
    cout << " \u03A8" << u <<" = ";
    for(int i=0; i<pow(2,n); i++){
        if(s(i,0).real()==0 && s(i,0).imag()==0) continue;
        if(s(i,0).imag()==0){
            double x = round(s(i,0).real()/0.001)*0.001;
            if(x>=0 && !first) cout << "+ ";
            if(x<0 && !first) cout << "- ";
            cout << abs(x) << "|";
            if(first) first=false;
        }
        else {
            double x = round(s(i,0).real()/0.001)*0.001;
            double y= round(s(i,0).imag()/0.001)*0.001;
            if(x>=0 && !first) cout << "+ ";
            if(x<0 && !first) cout << "- ";
            cout << "( "<< abs(x) << " + " << abs(y) << "i )|";
            if(first) first=false;
        }
        printBinary(i,n);
        cout <<"⟩ ";
    }
    cout << endl;
}
void System::SingleQubitGate(int target, Matrix<CD,2,2> M){
    Matrix<CD, Dynamic, Dynamic> gate = Matrix<CD, 1, 1>::Identity();
    for (int i = 0; i < n; i++) {
        if (i == target) gate = kroneckerProduct(gate, M).eval();
        else gate = kroneckerProduct(gate, Matrix<CD, 2, 2>::Identity()).eval();
    }
    s = gate * s;
}

void System::HGate(int target) {
    Matrix<CD, 2, 2> H;
    H << inv_sqrt2, inv_sqrt2,
            inv_sqrt2, -inv_sqrt2;
    SingleQubitGate(target, H);
}
void System::XGate(int target){
    Matrix<double,2,2> X;
    X << 0,1,
        1,0;
    SingleQubitGate(target, X);
}
void System::YGate(int target){
    Matrix<CD,2,2> Y;
    Y << 0,-i,
        i,0;
    SingleQubitGate(target, Y);
}
void System::ZGate(int target){
    Matrix<CD,2,2> Z;
    Z << 1,0,
        0,-1;
    SingleQubitGate(target, Z);
}
void System::SGate(int target){
    Matrix<CD,2,2> S;
    S << 1,0,
        0, i;
    SingleQubitGate(target, S);
}
void System::SDaggerGate(int target){
    Matrix<CD,2,2> SD;
    SD << 1,0,
        0,-i;
    SingleQubitGate(target, SD);
}
void System::TGate(int target){
    Matrix<CD,2,2> T;
    T << 1,0,
        0, exp(i * M_PI / 4.0);
    SingleQubitGate(target, T);
}
void System::TDaggerGate(int target){
    Matrix<CD,2,2> TD;
    TD << 1,0,
        0, exp(-i * M_PI / 4.0);
    SingleQubitGate(target, TD);
}

void System::CNOT(int control, int target) {
    int num_states = s.size();
    for (int i = 0; i < num_states; i++) {
        // Check if control qubit is |1⟩
        if ((i >> (n - 1 - control)) & 1) {
            int toggled = i ^ (1 << (n - 1 - target)); // Flip target qubit
            if (i < toggled) {
                swap(s(i), s(toggled));
            }
        }
    }
}

void System::SWAP(int q0, int q1) {

}
