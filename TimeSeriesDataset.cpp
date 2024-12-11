#include "TimeSeriesDataset.h"

#include <stdexcept>
#include <iostream>

std::vector<double> TimeSeriesDataset::zNormalize(const std::vector<double>& series) {
    double mean = std::accumulate(series.begin(), series.end(), 0.0) / series.size();
    double variance = 0.0;
    for (double val : series) {
        variance += (val - mean) * (val - mean);
    }
    double stddev = std::sqrt(variance / series.size());

    std::vector<double> normalized(series.size());
    for (size_t i = 0; i < series.size(); ++i) {
        normalized[i] = (series[i] - mean) / stddev;
    }
    return normalized;
}

TimeSeriesDataset::TimeSeriesDataset(bool znorm, bool train)
    : znormalize(znorm), isTrain(train), maxLength(0), numberOfSamples(0) {}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    std::vector<double> processedSeries = znormalize ? zNormalize(series) : series;
    data.push_back(processedSeries);
    labels.push_back(label);
    maxLength = std::max(maxLength, (int)processedSeries.size());
    numberOfSamples++;
}

const std::vector<std::vector<double>>& TimeSeriesDataset::getData() const {
    return data;
}

const std::vector<int>& TimeSeriesDataset::getLabels() const {
    return labels;
}

int TimeSeriesDataset::getMaxLength() const {
    return maxLength;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}

double euclideanDistance(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("Time series must have the same length");
    }
    double distance = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        distance += (x[i] - y[i]) * (x[i] - y[i]);
    }
    return std::sqrt(distance);
}

double dynamicTimeWarping(const std::vector<double>& x, const std::vector<double>& y) {
    size_t lenX = x.size();
    size_t lenY = y.size();
    std::vector<std::vector<double>> D(lenX + 1, std::vector<double>(lenY + 1, std::numeric_limits<double>::infinity()));
    D[0][0] = 0;

    for (size_t i = 1; i <= lenX; ++i) {
        for (size_t j = 1; j <= lenY; ++j) {
            double cost = (x[i - 1] - y[j - 1]) * (x[i - 1] - y[j - 1]);
            D[i][j] = cost + std::min({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]});
        }
    }

    return std::sqrt(D[lenX][lenY]);
}