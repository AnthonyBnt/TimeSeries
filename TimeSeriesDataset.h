#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <numeric>
#include <cmath>
#include <limits>
#include <algorithm>
#include <map>

class TimeSeriesDataset {
    bool znormalize;
    bool isTrain;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    int maxLength;
    int numberOfSamples;

    static std::vector<double> zNormalize(const std::vector<double>& series);

public:
    TimeSeriesDataset(bool znorm = false, bool train = true);

    void addTimeSeries(const std::vector<double>& series, int label);

    const std::vector<std::vector<double>>& getData() const;

    const std::vector<int>& getLabels() const;

    int getMaxLength() const;

    int getNumberOfSamples() const;
};

// Euclidean distance function
double euclideanDistance(const std::vector<double>& x, const std::vector<double>& y);

// Dynamic Time Warping (DTW) function
double dynamicTimeWarping(const std::vector<double>& x, const std::vector<double>& y);

#endif

