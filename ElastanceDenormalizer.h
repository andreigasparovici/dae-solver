//
// Created by andrei on 14.09.2020.
//

#ifndef DAE_SOLVER_ELASTANCEDENORMALIZER_H
#define DAE_SOLVER_ELASTANCEDENORMALIZER_H

#include <vector>
#include "ElastanceData.h"


class ElastanceDenormalizer {
protected:
    double elastanceMax, elastanceMin, timeAtMaxElastance;
    double step{};

    std::array<double, ELASTANCE_SIZE> timeDenorm;
    std::array<double, ELASTANCE_SIZE> valueDenorm;
    
    std::vector<double> valuePrep{};

public:
    explicit ElastanceDenormalizer(double elastanceMax, double elastanceMin, double timeAtMaxElastance, double step = 0.001);

    virtual void denormalize() = 0;

    void precomputeValues();

    double at(double t);

    void exportCsv(const char* filename);
};

class ExperimentalExtendedElastanceDenormalizer : public ElastanceDenormalizer {
public:
    explicit ExperimentalExtendedElastanceDenormalizer(
            double elastanceMax, double elastanceMin, double timeAtMaxElastance, double endTime,
            double step = 0.001) : ElastanceDenormalizer(elastanceMax, elastanceMin, timeAtMaxElastance, step) 
    {
        m_endTime = endTime;
    }

    void denormalize() override;
private:
    double m_endTime;
};

class ExperimentalElastanceDenormalizer : public ElastanceDenormalizer {
public:
    explicit ExperimentalElastanceDenormalizer(
        double elastanceMax, double elastanceMin, double timeAtMaxElastance,
        double step = 0.001) : ElastanceDenormalizer(elastanceMax, elastanceMin, timeAtMaxElastance, step){}
    
    

    void denormalize() override;
private:
    double m_endTime;
};

class AnalyticalElastanceDenormalizer : public ElastanceDenormalizer {
public:
    explicit AnalyticalElastanceDenormalizer(
            double elastanceMax, double elastanceMin, double timeAtMaxElastance, double timeOnsetContraction,
            double step = 0.001) : ElastanceDenormalizer(elastanceMax, elastanceMin, timeAtMaxElastance, step) {
        m_timeOnsetContraction = timeOnsetContraction;

    }

    void denormalize() override;

private:
    double m_timeOnsetContraction;
};

#endif //DAE_SOLVER_ELASTANCEDENORMALIZER_H
