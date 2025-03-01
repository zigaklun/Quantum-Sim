#include <bits/stdc++.h>
#include <cstdlib>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <cmath>
#include <unistd.h>
#include <complex>

using namespace std;
using namespace Eigen;
typedef  complex<double> CD;
typedef Matrix<CD,Dynamic,Dynamic> MCD;

void printMatrix(const MCD& matrix);

vector<int> toBinary (int i, int n) {
    vector<int> v;
    for (int j = n - 1; j >= 0; j--) {
        v.push_back(((i >> j) & 1));
    }
    return v;
}
int binaryVectorToInt(const std::vector<int>& binaryVector) {
    int result = 0;
    int size = binaryVector.size();
    for (int i = 0; i < size; ++i) {
        result += binaryVector[i] * std::pow(2, size - 1 - i);
    }
    return result;
}

MCD createCNOTMatrix(int n, int control, int target) {
    int dim = 1 << n;
    MCD cnotmatrika(dim,dim);
    for(int i =0; i<dim; i++){
        for(int j=0; j<dim; j++){
            cnotmatrika(i,j).imag(0);
            if(i==j) cnotmatrika(i,j).real(1);
            else cnotmatrika(i,j).real(0);
        }
    }
    for (int i = 0; i < dim; ++i) {
        vector<int> vi = toBinary(i,n);
        if(vi[control]==1){
            cnotmatrika(i,i).real(0);
            if(vi[target]==1) vi[target]=0;
            else vi[target]=1;
            int bin = binaryVectorToInt(vi);
            cnotmatrika(bin,i).real(1);
        }
    }
   return cnotmatrika;
}

void printMatrix(const MCD& matrix) {
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            cout << matrix(i, j).real() << "\t";
        }
        cout << endl;
    }
}

int n;
Matrix<CD,8,1> s;

void CNOT(int control, int target) {
    //swap(control,target);
    int numOfStates = 1 << n;
    for (int i = 0; i < numOfStates; i++) {
        if ((i >> control) & 1) {
            int j = i ^ (1 << target);
            if (j > i) {
                cout << "i=" << i << " j=" << j << endl;
                swap(s(i), s(j));
            }
        }
    }
}



int main() {
    n=3;
    s(0,0)={1,0}; //000  0
    s(1,0)={2,0}; //001  1
    s(2,0)={3,0}; //010  2
    s(3,0)={4,0}; //011  3
    s(4,0)={5,0}; //100  4
    s(5,0)={6,0}; //101  5
    s(6,0)={7,0}; //110  6
    s(7,0)={8,0}; //111  7

    printMatrix(s);
    cout << endl;
    //CNOT(1,0);  //2-6, 3-7
    CNOT(0,1);   //4-6, 5-7
    printMatrix(s);


    return 0;
}
