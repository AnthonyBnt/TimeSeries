#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <cmath>

class SinWaveGenerator : public TimeSeriesGenerator {
    double amplitude;
    double frequency;
    double phase;

public:
    SinWaveGenerator(double a = 1.0, double f = 1.0, double p = 0.0);
    std::vector<double> generateTimeSeries(int size) override;
};

#endif // SINWAVEGENERATOR_H
