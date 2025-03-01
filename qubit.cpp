#include "qubit.h"
#include "system.h"

Qubit::Qubit(System* sys) : system(sys) {
    superposition << 1, 0;
}

/*void Qubit::PrintDiracNotation(){
    cout<< "("<<superposition(0,0).real()<<" + "<< superposition(0,0).imag()
    << "i)|0> + " << "("<<superposition(1,0).real()<<" + "
    << superposition(1,0).imag() << "i)|1>" << endl;
    }*/
void Qubit::MeasureQubit(){

    double prob0 = pow(abs(superposition(0,0)),2);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    double rand_num = dis(gen);

    if(rand_num < prob0) {superposition(0,0) = 1;superposition(1,0) = 0;}
    else { superposition(0,0) = 0; superposition(1,0) = 1;}
}
void Qubit::XGate(){
    Matrix<double,2 ,2 > X_gate {{ 1, 0 },
                                { 0, 1 }};
    superposition=X_gate*superposition;
    system->Update();
}
void Qubit::YGate(){

    Matrix<CD,2 ,2 > Y_gate {{ i, 0 },
                            { 0, i }};
    superposition=Y_gate*superposition;
    system->Update();
}
void Qubit::ZGate(){
    Matrix<double,2 ,2 > Z_gate {{ 1, 0 },
                                { 0, -1 }};
    superposition=Z_gate*superposition;
    system->Update();
}
void Qubit::HGate(){
    Matrix<double,2 ,2 > H_gate {{ inv_sqrt2, inv_sqrt2 },
                                { inv_sqrt2, -inv_sqrt2 }};
    superposition=H_gate*superposition;
    system->Update();
}
void Qubit::SGate(){
    Matrix<CD,2 ,2 > S_gate {{ 1, 0 },
                            { 0, i }};
    superposition=S_gate*superposition;
    system->Update();
}
void Qubit::SDaggerGate(){
    Matrix<CD,2 ,2 > SG_gate {{ 1, 0 },
                            { 0, _i }};
    superposition=SG_gate*superposition;
    system->Update();
}
void Qubit::TGate(){
    CD x(inv_sqrt2,inv_sqrt2);
    Matrix<CD,2 ,2 > T_gate {{ 1, 0 },
                            { 0, x }};
    superposition=T_gate*superposition;
    system->Update();
}
void Qubit::TDaggerGate(){
    CD x(inv_sqrt2,-inv_sqrt2);
    Matrix<CD,2 ,2 > TG_gate {{ 1, 0 },
                            { 0,  x}};
    superposition=TG_gate*superposition;
    system->Update();
}
double Qubit::ProbabilityOfMeasuring(int x) {
    double prob0 = pow(abs(superposition(0,0)),2);
    double prob1 = pow(abs(superposition(1,0)),2);
    if(x==0) return prob0;
    else return prob1;
}
void Qubit::ArbitraryGateCD(Matrix<CD,2,2> m) {
    superposition = m*superposition;
    system->Update();
}
void Qubit::ArbitraryGateDouble(Matrix<double,2,2> m) {
    superposition = m*superposition;
    system->Update();
}
