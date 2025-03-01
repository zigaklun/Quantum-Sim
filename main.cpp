#include "system.h"

void printMatrix(const MCD& matrix) {
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            cout << matrix(i, j).real() << "\t";
        }
        cout << endl;
    }
}

int main() {

    System system(2);
    system.PrintDiracNotation();
    system(0).HGate();
    system.PrintDiracNotation(1);
    system.CNOT(0,1);
    system.PrintDiracNotation(2);
    system.Update();
    system.PrintDiracNotation(3);

    return 0;
}
