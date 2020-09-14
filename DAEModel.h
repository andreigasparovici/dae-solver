//
// Created by andrei on 14.09.2020.
//

#ifndef DAE_SOLVER_DAEMODEL_H
#define DAE_SOLVER_DAEMODEL_H

#include "Parameters.h"
#include <Eigen/Dense>

using Eigen::Matrix;
using Eigen::Vector;

// A(t)x' + B(t)x + C(t) = 0, x=x(t)

const size_t SIZE = 26;

class DAEModel {
private:
    Parameters p;

    void initA();
    void initB();
    void initC();

public:
    double t0{};
    Vector<double, SIZE> x0{};

    Matrix<double, SIZE, SIZE> A, B;
    Vector<double, SIZE> C;

    DAEModel(double t0, Vector<double, SIZE> x0);

    void setA(double t);

    void setB(double t);

    void setC(double t);
};


#endif //DAE_SOLVER_DAEMODEL_H
