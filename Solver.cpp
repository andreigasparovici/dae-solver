//
// Created by andrei on 14.09.2020.
//

#include "Solver.h"

#include <iostream>
#include <fstream>

void Solver::solve(DAEModel &model, double t1) {
    values.clear();
    double t = t0;
    Vector<double, SIZE> x;

    values.push_back(x0);

    while (t < t1) {
        model.setA(x0, t);
        model.setB(x0, t);
        model.setC(x0, t);

//        auto eigenvalues = (model.B * step + model.A).eigenvalues();
//        auto c = eigenvalues(0);
//        std::cout << eigenvalues << std::endl;

        x = (model.B * step + model.A).partialPivLu().solve(model.A * x0 - step * model.C);

        values.push_back(x);

        x0 = x;
        t += step;
    }
}

std::vector<Vector<double, SIZE>> Solver::getValues() {
    return values;
}