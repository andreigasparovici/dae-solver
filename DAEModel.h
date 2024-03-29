//
// Created by andrei on 14.09.2020.
//

#ifndef DAE_SOLVER_DAEMODEL_H
#define DAE_SOLVER_DAEMODEL_H

#include "Parameters.h"
#include <Eigen/Dense>

using Eigen::Matrix;

template <typename Type, int Size>
using Vector = Matrix<Type, Size, 1>;

const size_t SIZE = 26;

// A(t)x' + B(t)x + C(t) = 0, x=x(t)

class DAEModel {
private:
    Parameters p;

public:
    Matrix<double, SIZE, SIZE> A, B;
    Vector<double, SIZE> C;

    void initialize(double t0);

    void setA(const Vector<double, SIZE>& x, double t);

    void setB(const Vector<double, SIZE>& x, double t);

    void setC(const Vector<double, SIZE>& x, double t);
};


#endif //DAE_SOLVER_DAEMODEL_H
