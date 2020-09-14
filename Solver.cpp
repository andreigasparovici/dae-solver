//
// Created by andrei on 14.09.2020.
//

#include "Solver.h"

Vector<double, SIZE> Solver::solveAt(DAEModel &model, double t1) {
    double t0 = model.t0;
    auto x0 = model.x0;

    double t = t0;

    while (t < t1) {
        model.setA(t);
        model.setB(t);
        model.setC(t);

        x = (model.B * step + model.A).partialPivLu().solve(model.A * x0 - step * model.C);

        x0 = x;
        t += step;
    }

    return x;
}