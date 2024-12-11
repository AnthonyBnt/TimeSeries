#include "StepGenerator.h"

std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> series(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);
    std::bernoulli_distribution stay(0.5);

    series[0] = 0;
    for (int i = 1; i < size; ++i) {
        series[i] = stay(gen) ? series[i - 1] : dist(gen);
    }
    return series;
}
