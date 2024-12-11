#include "GaussianGenerator.h"

GaussianGenerator::GaussianGenerator(double _mean, double _stddev) :
mean(_mean), stddev(_stddev) {}

std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(mean, stddev);

    series.reserve(size);
    for (int i = 0; i < size; ++i) {
        series.push_back(d(gen));
    }
    return series;
}
