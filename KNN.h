#ifndef KNN_H
#define KNN_H

#include "TimeSeriesDataset.h"
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class KNN {
    int k;
    std::string similarityMeasure;

    int getMostFrequentLabel(const std::vector<int>& neighbors) const;

public:
    KNN(int neighbors = 1, const std::string& measure = "euclidean");

    std::vector<int> predict(const TimeSeriesDataset& trainSet, const TimeSeriesDataset& testSet);
    double evaluate(const std::vector<int>& yTest, const std::vector<int>& yPred) const;
};

#endif // KNN_H
