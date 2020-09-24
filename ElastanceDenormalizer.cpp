//
// Created by andrei on 14.09.2020.
//

#include "ElastanceDenormalizer.h"

#include <algorithm>
#include <cmath>
#include <fstream>

// Constructor
ElastanceDenormalizer::ElastanceDenormalizer(double elastanceMax, double elastanceMin, double timeMax, double step) {
    this->elastanceMin = elastanceMin;
    this->elastanceMax = elastanceMax;
    this->timeMax = timeMax;
    this->step = step;
}

void ElastanceDenormalizer::exportCsv(const char *filename) {
    std::ofstream f(filename);

    f << "Time,Value,DenormTime,DenormValue\n";

    for (int i = 0; i < ELASTANCE_SIZE; i++)
        f << elastanceTime[i] << ',' << elastanceValue[i] << ',' << timeDenorm[i] << ',' << valueDenorm[i] << '\n';

    f.close();
}

// Experimental elastance denormalization
void ExperimentalElastanceDenormalizer::denormalize() {
    const double elastanceMinNorm = *std::min_element(elastanceValue, elastanceValue + ELASTANCE_SIZE);
    const double elastanceMaxNorm = 1;

    const double deltaNorm = elastanceMaxNorm - elastanceMinNorm;
    const double delta = elastanceMax - elastanceMin;
    const double ratio = delta / deltaNorm;

    const double conv = 1333.22;
    const double elastanceChar = 105;

    double maxElastanceTime = *std::max_element(elastanceTime, elastanceTime + ELASTANCE_SIZE);

    for (int i = 0; i < ELASTANCE_SIZE; ++i) {
        timeDenorm[i] = elastanceTime[i] * timeMax / maxElastanceTime;
        valueDenorm[i] = ((elastanceValue[i] - elastanceMinNorm) * ratio + elastanceMin) * conv / elastanceChar;
    }
}

// Analytical elastance denormalization
void AnalyticalElastanceDenormalizer::denormalize() {
    double tau1 = 0.110 * heartCyclePeriod;
    double tau2 = 0.180 * heartCyclePeriod;
    double m1 = 1.32;
    double m2 = 13.1;
    double g1 = 0.;
    double g2 = 0.;
    double h1 = 0.;
    double h2 = 0.;
    double maxVal = 0.;
    double k = 0;

    const double conv = 1333.22;
    const double elastanceChar = 105;

    double maxElastanceTime = *std::max_element(elastanceTime, elastanceTime + ELASTANCE_SIZE);

    for (int i = 0; i < ELASTANCE_SIZE; i++) {
        timeDenorm[i] = elastanceTime[i] * timeMax / maxElastanceTime;

        g1 = pow((timeDenorm[i] / tau1), m1);
        g2 = pow((timeDenorm[i] / tau2), m2);
        h1 = g1 / (1 + g1);
        h2 = 1 / (1 + g2);
        if (h1 > h2)
            maxVal = h1;
        else
            maxVal = h2;
        k = (elastanceMax - elastanceMin) / maxVal;
        valueDenorm[i] = (k * h1 * h2 + elastanceMin) * conv / elastanceChar;
    }
}

// Linear interpolation function
double interpolate(double t0, double t1, double x0, double x1, double t) {
    double factor = (t1 - t) / (t1 - t0);
    double x_interp = x1 * factor + x0 * (1 - factor);
    return x_interp;
}

// Precompute values
void ElastanceDenormalizer::precomputeValues() {
    double t = 0;
    int i = 0;

    while (t < timeMax) {
        double value = interpolate(timeDenorm[i], timeDenorm[i + 1], valueDenorm[i], valueDenorm[i + 1], t);
        valuePrep.push_back(value);

        t += step;
        if (timeDenorm[i + 1] < t) {
            i++;
        }
    }
}

// Constant time retrieval
double ElastanceDenormalizer::at(double t) {
    int index = int(t / timeMax * valuePrep.size());
    return valuePrep[index];
}