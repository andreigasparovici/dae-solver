//
// Created by andrei on 25.08.2020.
//

#include "gtest/gtest.h"

#include <iostream>
#include <fstream>
#include <iomanip>

#include "../DAEModel.h"
#include "../Solver.h"

TEST(Test, Test) {
    double pressure_0 = 5.5396502175 * 1333;
    double volume_0 = 147.6837;

    double Q_LAin_0 = 0;
    double P_LA_0 = pressure_0;
    double V_LA_0 = volume_0;
    double Q_LALV_0 = 0;
    double P_LV_0 = pressure_0;
    double V_LV_0 = volume_0;
    double Q_Ao_0 = 0;
    double P_Ao_0 = 0;
    double P_Sart_0 = 0;
    double Q_Csys_0 = 0;
    double Q_RAin_0 = 0;
    double P_RA_0 = pressure_0;
    double V_RA_0 = volume_0;
    double Q_RARV_0 = 0;
    double P_RV_0 = pressure_0;
    double V_RV_0 = volume_0;
    double Q_PAo_0 = 0;
    double P_PAo_0 = 0;
    double P_Part_0 = 0;
    double Q_Cpulm_0 = 0;
    double P_SystCap_0 = 0;
    double Q_SystCap_0 = 0;
    double Q_CSystVein_0 = 0;
    double P_PulmCap_0 = 0;
    double Q_PulmCap_0 = 0;
    double Q_CPulmVein_0 = 0;

    double t0 = 0;

    Vector<double, SIZE> x0;
    x0
            << Q_LAin_0, P_LA_0, V_LA_0, Q_LALV_0, P_LV_0, V_LV_0, Q_Ao_0, P_Ao_0, P_Sart_0, Q_Csys_0, Q_RAin_0, P_RA_0,
            V_RA_0, Q_RARV_0, P_RV_0, V_RV_0, Q_PAo_0, P_PAo_0, P_Part_0, Q_Cpulm_0, P_SystCap_0, Q_SystCap_0,
            Q_CSystVein_0, P_PulmCap_0, Q_PulmCap_0, Q_CPulmVein_0;

    DAEModel model;

    model.initialize(t0);

    double t = 1;

    std::vector<Vector<double, SIZE>> values;

    for (int i = 1; i <= 5; i++) {

        std::ofstream out;
        out.open("/home/andrei/CLionProjects/dae-solver/solver-" + std::to_string(i)+ ".csv");

        Solver solver(t0, x0);
        solver.solve(model, t);
        values = solver.getValues();

        out << "LV pressure,LV volume\n";

        for (auto x: values) {
            out << std::setprecision(5) << x(4);
            out << ',';
            out << std::setprecision(5) << x(5) ;
            out << '\n';
        }

        x0 = values.back();
        out.close();
    }


}
