#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"

#include <random>

class GaussianGenerator : public TimeSeriesGenerator {
    double mean;
    double stddev;

public:
    GaussianGenerator(double m = 0.0, double s = 1.0);
    std::vector<double> generateTimeSeries(int size) override;
};

#endif // GAUSSIANGENERATOR_H
