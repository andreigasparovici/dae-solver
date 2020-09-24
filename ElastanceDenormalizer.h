//
// Created by andrei on 14.09.2020.
//

#ifndef DAE_SOLVER_ELASTANCEDENORMALIZER_H
#define DAE_SOLVER_ELASTANCEDENORMALIZER_H

#include <vector>
#include "ElastanceData.h"


class ElastanceDenormalizer {
protected:
    double elastanceMax, elastanceMin, timeMax;
    double step{};

    double timeDenorm[ELASTANCE_SIZE]{};
    double valueDenorm[ELASTANCE_SIZE]{};

    std::vector<double> valuePrep{};

public:
    explicit ElastanceDenormalizer(double elastanceMax, double elastanceMin, double timeMax, double step = 0.001);

    virtual void denormalize() = 0;

    void precomputeValues();

    double at(double t);

    void exportCsv(const char* filename);
};

class ExperimentalElastanceDenormalizer : public ElastanceDenormalizer {
public:
    explicit ExperimentalElastanceDenormalizer(
            double elastanceMax, double elastanceMin, double timeMax,
            double step = 0.001) : ElastanceDenormalizer(elastanceMax, elastanceMin, timeMax, step) {}

    void denormalize() override;
};

class AnalyticalElastanceDenormalizer : public ElastanceDenormalizer {
public:
    explicit AnalyticalElastanceDenormalizer(
            double elastanceMax, double elastanceMin, double timeMax, double heartCyclePeriod,
            double step = 0.001) : ElastanceDenormalizer(elastanceMax, elastanceMin, timeMax, step) {
        this->heartCyclePeriod = heartCyclePeriod;
    }

    void denormalize() override;

private:
    double heartCyclePeriod;
};

#endif //DAE_SOLVER_ELASTANCEDENORMALIZER_H
