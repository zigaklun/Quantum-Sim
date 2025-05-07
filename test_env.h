#include "system.h"
#include "qubit.h"

class Test_env {

public:
    Matrix<CD, Dynamic, 1> s;
    Test_env(Matrix<CD, Dynamic, 1> s);
    VI measureOne(int qubit, int number_of_times, int num_of_qubits);
    VI measureAll(int number_of_times);

    //dodej noise opcije
};
