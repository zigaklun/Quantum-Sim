#include "test_env.h"

void printB(int i, int n) {
    for (int j = 0; j < n; j++) cout << ((i >> j) & 1);
}

int main() {

    System system(2);
    system.HGate(0);
    system.CNOT(0,1);
    system.PrintDiracNotation(0);

    Test_env te(system.s);
    VI v = te.measureOne(0,100, 2);
    cout << "0:" << v[0] << " 1:" << v[1] << endl;

    VI ve = te.measureAll(100);
    for (int i=0; i<ve.size(); i++) {
        printB(i,2);
        cout <<": " << ve[i] << endl;
    }

  return 0;
}
