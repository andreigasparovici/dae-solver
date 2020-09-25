//
// Created by andrei on 14.09.2020.
//

#include "Solver.h"

#include <iostream>
#include <fstream>
#include <iomanip>

void Solver::solve(DAEModel &model, double t1) {
    values.clear();
    double t = t0;
    Vector<double, SIZE> x;

    values.push_back(x0);

    while (t < t1) {
        model.setA(x0, t);
        model.setB(x0, t);
        model.setC(x0, t);

        x = (model.B * step + model.A).partialPivLu().solve(model.A * x0 - step * model.C);

        values.push_back(x);

        x0 = x;
        t += step;
    }
}

std::vector<Vector<double, SIZE>> Solver::getValues() {
    return values;
}

void Solver::exportCsv(const char *filename) {
    std::ofstream f(filename);

    f << "LV pressure,LV volume\n";

    for (auto x: values) {
        f << std::setprecision(5) << x(4);
        f << ',';
        f << std::setprecision(5) << x(5) ;
        f << '\n';
    }

    f.close();
}