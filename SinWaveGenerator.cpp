#include "SinWaveGenerator.h"

SinWaveGenerator::SinWaveGenerator(double a, double f, double p) :
amplitude(a), frequency(f), phase(p) {}

std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> series(size);
    for (int i = 0; i < size; ++i) {
        series[i] = amplitude * sin(frequency * i + phase);
    }
    return series;
}
