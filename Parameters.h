//
// Created by andrei on 14.09.2020.
//

#ifndef DAE_SOLVER_PARAMETERS_H
#define DAE_SOLVER_PARAMETERS_H

#include "ElastanceDenormalizer.h"

class Parameters {
private:
    AnalyticalElastanceDenormalizer Elast_LA{0.207666, 0.083718, 0.3434, 0.714479};
    AnalyticalElastanceDenormalizer Elast_RA{0.04, 0.02, 0.3434, 0.85};
    ExperimentalElastanceDenormalizer Elast_LV{6.277778, 0.02, 0.351842};
    ExperimentalElastanceDenormalizer Elast_RV{0.8, 0.02, 0.3419};

public:
    double E_LA(double t) {
        return Elast_LA.at(t);
    }

    double E_LV(double t) {
        return Elast_LV.at(t);
    }

    double E_RA(double t) {
        return Elast_RA.at(t);
    }

    double E_RV(double t) {
        return Elast_RV.at(t);
    }

    double V_0_LA{3};
    double V_0_RA{3};
    double V_0_LV{84.171607};
    double V_0_RV{33.000748};
    double R_s_LA{0};
    double R_s_RA{0};
    double R_s_LV{0};
    double R_s_RV{0};
    double R_S_p{119.8};
    double R_S_d{2587.7};
    double R_MV{52};
    double R_AV{10};
    double R_TV{10};
    double R_PV{10};
    double L_MV{.5};
    double L_AV{.5};
    double L_TV{.5};
    double L_PV{.5};
    double R_P_p{52.29};
    double R_P_d{528.7};
    double R_S_V{299.5};
    double R_P_V{64.56};
    double C_sys{1321.38e-6};
    double C_pulm{2832.71e-6};
    double C_sysVein{19500e-6};
    double C_pulmVein{16500e-6};

    Parameters(){
        Elast_LA.denormalize();
        Elast_LA.precomputeValues();

        Elast_LV.denormalize();
        Elast_LV.precomputeValues();

        Elast_RA.denormalize();
        Elast_RA.precomputeValues();

        Elast_RV.denormalize();
        Elast_RV.precomputeValues();
    }
};


#endif //DAE_SOLVER_PARAMETERS_H
