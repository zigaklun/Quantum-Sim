#ifndef QUBIT_H
#define QUBIT_H

#include <iostream>
#include <complex>
#include <vector>
#include <random>
#include <cmath>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

typedef complex<double> CD;
typedef Matrix<CD, Dynamic, Dynamic> MCD;
typedef vector<int> VI;

const CD i(0,1);
const CD _i(0,-1);
const double inv_sqrt2 = 1.0 / sqrt(2.0);

class System;

class Qubit {
public:
    System* system;
    int index;
    Qubit(System* sys, int index);
};

#endif
