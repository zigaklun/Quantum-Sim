#include "system.h"

int main(){

    //compile: g++ -o sdc superdense_coding.cpp test_env.cpp system.cpp qubit.cpp

    string s;
    cout << "Enter two bits (00,01,10,11):" << endl;
    cin >> s;
    //Alice has qubit 1
    //Bob has qubit 0

    System system(2);
    //First we entangle the qubits
    system.HGate(0);
    system.CNOT(0,1);
    cout << "Initial entangled state (Bell's state Φ⁺): " << endl;
    system.PrintDiracNotation();

    if(s[1]=='1'){
        cout << "Alice applies X-gate on her qubit."<< endl;
        system.XGate(1);
    }
    if(s[0]=='1'){
        cout << "Alice applies Z-gate on her qubit."<< endl;
        system.ZGate(1);
    }
    if(s[0]=='0' && s[1]=='0') cout << "Alice didn't apply any gates on her qubit."<< endl;
    system.PrintDiracNotation(1);

    //Alice sends her qubit to Bob
    system.CNOT(1,0);
    system.HGate(1);
    cout << "Bob applies CNOT and Hadamard gate, getting the wanted result:"<< endl;
    system.measureAll();
    system.PrintDiracNotation(2);

    return 0;
}
