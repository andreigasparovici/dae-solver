//
// Created by andrei on 14.09.2020.
//

#ifndef DAE_SOLVER_SOLVER_H
#define DAE_SOLVER_SOLVER_H

#include "DAEModel.h"

class Solver {
private:
    std::vector<Vector<double, SIZE>> values;
    double step{.001};

    double t0;
    Vector<double, SIZE> x0;
public:
    Solver(double t0, Vector<double, SIZE> x0) : t0(t0), x0(x0) {}
    void solve(DAEModel &model, double t1);

    std::vector<Vector<double, SIZE>> getValues();
};


#endif //DAE_SOLVER_SOLVER_H
