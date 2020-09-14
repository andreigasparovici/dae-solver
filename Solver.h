//
// Created by andrei on 14.09.2020.
//

#ifndef DAE_SOLVER_SOLVER_H
#define DAE_SOLVER_SOLVER_H

#include "DAEModel.h"

class Solver {
private:
    Vector<double, SIZE> x;
    double step{.001};
public:
    Vector<double, SIZE> solveAt(DAEModel &model, double t1);
};


#endif //DAE_SOLVER_SOLVER_H
