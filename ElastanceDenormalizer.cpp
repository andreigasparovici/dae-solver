//
// Created by andrei on 14.09.2020.
//

#include "ElastanceDenormalizer.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <cassert>

// Constructor
ElastanceDenormalizer::ElastanceDenormalizer(double elastanceMax, double elastanceMin, double timeMax, double step) {
    this->elastanceMin = elastanceMin;
    this->elastanceMax = elastanceMax;
    this->timeAtMaxElastance = timeMax;
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
void ExperimentalExtendedElastanceDenormalizer::denormalize() {
    const double elastanceMinNorm = *std::min_element(elastanceValue.begin(), elastanceValue.end());
    const double elastanceMaxNorm = *std::max_element(elastanceValue.begin(), elastanceValue.end());;

    const double deltaNorm = elastanceMaxNorm - elastanceMinNorm;
    const double delta = elastanceMax - elastanceMin;
    const double ratio = delta / deltaNorm;

    const double conv = 1333.22;

    const auto atMaxNormalizedElastance = std::max_element(elastanceValue.begin(), elastanceValue.end());
    size_t indexOfMaxElement = std::distance(elastanceValue.begin(), atMaxNormalizedElastance);

    double timeAtMaxElastanceNormalized = 1.0;
    double timeAtEndElastanceNormalized = 3.0;

    
    for (int i = 0; i < ELASTANCE_SIZE; ++i)
    {
        if (i <= indexOfMaxElement)
        {
            timeDenorm[i] = elastanceTime[i] * timeAtMaxElastance;
        }
        else
        {
            timeDenorm[i] = (elastanceTime[i] - *atMaxNormalizedElastance) * (m_endTime - timeAtMaxElastance) / (timeAtEndElastanceNormalized - timeAtMaxElastanceNormalized) + timeAtMaxElastance;
        }
        valueDenorm[i] = ((elastanceValue[i] - elastanceMinNorm) * ratio + elastanceMin) * conv ;
    }
}

// Experimental elastance denormalization
void ExperimentalElastanceDenormalizer::denormalize() {
    const double elastanceMinNorm = *std::min_element(elastanceValue.begin(), elastanceValue.end());
    const double elastanceMaxNorm = *std::max_element(elastanceValue.begin(), elastanceValue.end());;

    const double deltaNorm = elastanceMaxNorm - elastanceMinNorm;
    const double delta = elastanceMax - elastanceMin;
    const double ratio = delta / deltaNorm;

    const double conv = 1333.22;

    const auto atMaxNormalizedElastance = std::max_element(elastanceValue.begin(), elastanceValue.end());
    size_t indexOfMaxElement = std::distance(elastanceValue.begin(), atMaxNormalizedElastance);

    double timeAtMaxElastanceNormalized = 1.0;
    double timeAtEndElastanceNormalized = 3.0;


    for (int i = 0; i < ELASTANCE_SIZE; ++i)
    {
      timeDenorm[i] = elastanceTime[i] * timeAtMaxElastance;
      valueDenorm[i] = ((elastanceValue[i] - elastanceMinNorm) * ratio + elastanceMin) * conv ;
    }
}

// Analytical elastance denormalization
void AnalyticalElastanceDenormalizer::denormalize() {
    double timeAtMaxElastanceNormalized = 1.0;
    double maxElastanceTime = 3.0;
    double cyclePeriod = maxElastanceTime * timeAtMaxElastance / timeAtMaxElastanceNormalized;
    double tau1 = 0.110 * cyclePeriod;
    double tau2 = 0.180 * cyclePeriod;
    double m1 = 1.32;
    double m2 = 13.1;
    double g1 = 0.;
    double g2 = 0.;
    double h1 = 0.;
    double h2 = 0.;
    double maxVal = 0.;
    double k = 0;

    const double conv = 1333.22;

    for (int i = 0; i < ELASTANCE_SIZE; i++) {
        timeDenorm[i] = elastanceTime[i] * timeAtMaxElastance / timeAtMaxElastanceNormalized;

        g1 = pow((timeDenorm[i] / tau1), m1);
        g2 = pow((timeDenorm[i] / tau2), m2);
        h1 = g1 / (1 + g1);
        h2 = 1 / (1 + g2);
        if (h1 > h2)
            maxVal = h1;
        else
            maxVal = h2;
        k = (elastanceMax - elastanceMin) / maxVal;
        valueDenorm[i] = (k * h1 * h2 + elastanceMin) * conv ;
    }
}

// Linear interpolation function
double interpolate(double t0, double t1, double x0, double x1, double t) {
    double factor = (t1 - t) / (t1 - t0);
    double x_interp = x0 * factor + x1 * (1 - factor);
    return x_interp;
}

// Precompute values
void ElastanceDenormalizer::precomputeValues() {
    double t = 0;
    int i = 0;
    double endTime = timeDenorm.back();
    while (t < endTime) {
        double value = interpolate(timeDenorm[i], timeDenorm[i + 1], valueDenorm[i], valueDenorm[i + 1], t);
        valuePrep.push_back(value);

        t += step;
        if (timeDenorm[i + 1] < t) {
            i++;
        }
    }
}

// Constant time retrieval
double ElastanceDenormalizer::at(double t)
{
    double endTime = timeDenorm.back();
    int index = int(t / endTime * valuePrep.size());
    
    index = index % valuePrep.size(); // Periodicity

    return valuePrep[index];
}