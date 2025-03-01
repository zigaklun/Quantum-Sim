#include "system.h"
#include "qubit.h"

Matrix<CD,Dynamic,1> System::TensorProduct(const Matrix<CD,Dynamic,1> a ,const Matrix<CD,2,1> b ){
    int size = a.rows()*b.rows();
    Matrix<CD,Dynamic,1> result;
    result.resize(size);
    for (int i = 0; i < a.rows(); i++) {
        for (int j = 0; j < b.rows(); j++) {
            result(i * b.rows() + j) = a(i) * b(j);
        }
    }
    return result;
}

void System::printBinary(int i, int n) {
    for (int j = n - 1; j >= 0; j--) {
        cout << ((i >> j) & 1);
    }
}

VI System::toBinary (int i, int n) {
    vector<int> v;
    for (int j = n - 1; j >= 0; j--) {
        v.push_back(((i >> j) & 1));
    }
    return v;
}

int System::binaryVectorToInt(const VI& binaryVector) {
    int result = 0;
    int size = binaryVector.size();
    for (int i = 0; i < size; ++i) {
        result += binaryVector[i] * std::pow(2, size - 1 - i);
    }
    return result;
}
System:: System(int num_qubits):n(num_qubits) {
    s.resize(pow(2,n));
    s.setZero();
    s(0)=1;
    qubits.reserve(n);
    for(int i=0; i<n; i++) qubits.push_back(new Qubit(this));
}

Qubit& System::operator()(int index) {
        return *qubits.at(index);
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
            cout << x << "|";
            if(first) first=false;
        }
        else {
            double x = round(s(i,0).real()/0.001)*0.001;
            double y= round(s(i,0).imag()/0.001)*0.001;
            if(x>=0 && !first) cout << "+ ";
            if(x<0 && !first) cout << "- ";
            cout << "( "<< x << " + " << y << "i )|";
            if(first) first=false;
        }
        printBinary(i,n);
        cout <<"⟩ ";
    }
    cout << endl;
}

//useless funkcija k ubistvu nebi semela obstajat!!!
void System::ProbabilityOfMeasuring(string bin) {
    int x = stoi(bin,nullptr,2);
    if(x>pow(2,n)) cout << "Error invalid input" << endl;
    else cout << "Probability Of Measuring |"<<bin <<"> : " << pow(abs(s(x,0)),2) << endl;
}

void System::Update(){
    Matrix<CD,Dynamic,1> newsys;
    newsys.resize(2);
    int count = 1;
    for(auto q : qubits) {
        if(count==1){
            newsys(0,0)=q->superposition(0,0);
            newsys(1,0)=q->superposition(1,0);
        }
        else newsys=TensorProduct(newsys,q->superposition);
        count++;
    }
    s=newsys;
}

void System::CNOT(int control, int target){
    int numOfStates = 1 << n;
    for (int i = 0; i < numOfStates; i++) {
        vector<int> vi = toBinary(i,n);
        if (vi[control]) {
            if(vi[target]) vi[target]=0;
            else vi[target]=1;
            int t = binaryVectorToInt(vi);
            if(i<t) swap(s(i), s(t));
        }
    }
}
