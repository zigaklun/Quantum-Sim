#include "system.h"
#include "qubit.h"
#include <cmath>
#include <random>

void printBinary(int i, int n) {
    for (int j = 0; j < n; j++) cout << ((i >> j) & 1);
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
            if(x<0) cout << "- ";
            cout << abs(x) << "|";
            if(first) first=false;
        }
        else if(s(i,0).real()==0){
            double y= round(s(i,0).imag()/0.001)*0.001;
            if(y>=0 && !first) cout << "+ ";
            if(y<0) cout << "- ";
            cout << abs(y) << "i |";
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
        if ((i >> (n - 1 - control)) & 1) {
            int toggled = i ^ (1 << (n - 1 - target)); // Flip target qubit
            if (i < toggled) swap(s(i), s(toggled));
        }
    }
}

void System::SWAP(int q0, int q1) {
    CNOT(q0,q1);
    CNOT(q1,q0);
    CNOT(q0,q1);
}

void System::CCNOT(int control1, int control2, int target){
    int num_states = s.size();
    for (int i = 0; i < num_states; i++) {
        if (((i >> (n - 1 - control1)) & 1) && ((i >> (n - 1 - control2)) & 1)) {
            int toggled = i ^ (1 << (n - 1 - target)); // Flip target qubit
            if (i < toggled) swap(s(i), s(toggled));
        }
    }
}

int System::measureQubit(int qubit) {

    int num_states = s.size();
    double probs_of_one = 0.0;
    for (int i = 0; i < num_states; i++) {
        // z^2 = (a^2 - b^2)+2ab for complex numbers
        if ((i >> (n - 1 - qubit)) & 1){
            probs_of_one += norm(s(i));
        }
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0,1.0);

    double r = dist(gen);
    int measurment;
    if(r>=1-probs_of_one) measurment=1;
    else measurment=0;

    double sum;
    for (int i = 0; i < num_states; i++) {
        if(((i >> (n - 1 - qubit)) & 1)==measurment)
            sum += norm(s(i));
        else s(i)=CD(0,0);
    }

    double constA = 1.0 / sqrt(sum);
    for (int i = 0; i < num_states; i++) {
        s(i) *= constA;
    }

    return measurment;
}
void System::measureAll() {

    int num_states = s.size();
    vector<double> probs;
    for (int i=0; i<num_states-1; i++) {
        if(i==0) probs.push_back(norm(s(i)));
        else probs.push_back(norm(s(i))+probs[i-1]);
    }
    probs.push_back(1);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0,1.0);

    double r = dist(gen);

    for (int i=0; i<num_states; i++) {
        if(r<=probs[i]){
            s(i)=1;
            r=2;
        }
        else s(i)=0;
    }
    return;
}
