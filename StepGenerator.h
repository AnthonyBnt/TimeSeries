#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <random>

class StepGenerator : public TimeSeriesGenerator {
public:
    std::vector<double> generateTimeSeries(int size) override;
};

#endif // STEPGENERATOR_H
