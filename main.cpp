#include "system.h"

int main() {

    System system(3);
    system.PrintDiracNotation();
    system.HGate(0);
    system.TGate(2);
    system.YGate(1);
    system.SDaggerGate(0);
    system.CNOT(1, 0);
    system.TDaggerGate(1);
    system.PrintDiracNotation(1);

    return 0;
}
