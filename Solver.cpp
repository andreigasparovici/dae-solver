//
// Created by andrei on 14.09.2020.
//

#include "Solver.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>

void Solver::solve(DAEModel &model, double t1) {
    values.clear();
    double t = t0;
    Vector<double, SIZE> x;

    values.push_back(x0);

    while (t < t1) {
        model.setA(x0, t);
        model.setB(x0, t);
        model.setC(x0, t);

        x = ((model.B + model.A / step).partialPivLu().solve(model.A * x0 / step - model.C));

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

    const char *columns[] = {
            "Q_{LA-in}", "P_{LA}", "V_{LA}", "Q_{LA-LV}", "P_{LV}", "V_{LV}", "Q_{Ao}", "P_{Ao}", "P_{Sart}",
            "Q_{Csys}", "Q_{RA-in}", "P_{RA}", "V_{RA}", "Q_{RA-RV}", "P_{RV}", "V_{RV}", "Q_{PAo}", "P_{PAo}",
            "P_{Part}", "Q_{Cpulm}", "P_{SystCap}", "Q_{SystCap}", "Q_{CSystVein}", "P_{PulmCap}", "Q_{PulmCap}",
            "Q_{CPulmVein}"
    };


    f << columns[0];
    for (int i = 1; i < SIZE; ++i)
        f << ',' << columns[i];

    f << '\n';

    for (auto x: values) {
        f << std::setprecision(5) << x(0);
        for (int i = 1; i < x.size(); i++)
            f << ',' << std::setprecision(5) << x(i);
        f << '\n';
    }

    f.close();
}