//
// Created by andrei on 14.09.2020.
//

#include "Solver.h"

void Solver::solve(DAEModel &model, double t1) {
    values.clear();

    double t = t0;
    Vector<double, SIZE> x;

    while (t < t1) {
        model.setA(t);
        model.setB(t);
        model.setC(t);

        x = (model.B * step + model.A).partialPivLu().solve(model.A * x0 - step * model.C);

        values.push_back(x);

        x0 = x;
        t += step;
    }
}

std::vector<Vector<double, SIZE>> Solver::getValues() {
    return values;
}