#include "system.h"

int main() {

    System system(3);
    system.PrintDiracNotation();
    system.XGate(0);
    system.XGate(1);
    system.PrintDiracNotation(1);
    system.CCNOT(0,1,2);
    system.PrintDiracNotation(2);

    return 0;
}
