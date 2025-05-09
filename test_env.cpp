#include "test_env.h"

Test_env::Test_env(Matrix<CD, Dynamic, 1> sa){
    s=sa;
}

VI Test_env::measureOne(int qubit, int n, int num_of_qubits){

    int num_states = s.size();
    VI res(2,0);
    double probs_of_one = 0.0;

    for (int i = 0; i < num_states; i++) {
        if ((i >> (num_of_qubits - 1 - qubit)) & 1){
            probs_of_one += norm(s(i));
        }
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0,1.0);


    for (int i=0; i<n; i++) {
        double r = dist(gen);
        if(r>=1-probs_of_one) res[1]++;
        else res[0]++;
    }
    return res;
}

VI Test_env::measureAll(int n) {

    int num_states = s.size();
    vector<double> probs;
    VI res(num_states,0);

    for (int i=0; i<num_states-1; i++) {
        if(i==0) probs.push_back(norm(s(i)));
        else probs.push_back(norm(s(i))+probs[i-1]);
    }
    probs.push_back(1);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0,1.0);

    for (int i=0; i<n; i++) {
        double r = dist(gen);
        for (int j=0; j<num_states; j++) {
            if(r<=probs[j]){
                res[j]++;
                break;
            }
        }
    }
    return res;
}
