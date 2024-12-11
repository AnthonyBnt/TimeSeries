#include "KNN.h"
#include <stdexcept>
#include <cmath>
#include <numeric>
#include <limits>

KNN::KNN(int neighbors, const std::string& measure)
    : k(neighbors), similarityMeasure(measure) {}

int KNN::getMostFrequentLabel(const std::vector<int>& neighbors) const {
    std::map<int, int> labelCount;
    for (int label : neighbors) {
        labelCount[label]++;
    }
    return std::max_element(labelCount.begin(), labelCount.end(),
                            [](const auto& a, const auto& b) {
                                return a.second < b.second;
                            })->first;
}

std::vector<int> KNN::predict(const TimeSeriesDataset& trainSet, const TimeSeriesDataset& testSet) {
    const auto& trainData = trainSet.getData();
    const auto& trainLabels = trainSet.getLabels();
    const auto& testData = testSet.getData();

    std::vector<int> predictions;

    for (const auto& testSeries : testData) {
        std::vector<std::pair<double, int>> distances;

        for (size_t i = 0; i < trainData.size(); ++i) {
            double distance = 0.0;
            if (similarityMeasure == "euclidean") {
                distance = euclideanDistance(testSeries, trainData[i]);
            } else if (similarityMeasure == "dtw") {
                distance = dynamicTimeWarping(testSeries, trainData[i]);
            } else {
                throw std::invalid_argument("Unsupported similarity measure");
            }
            distances.emplace_back(distance, trainLabels[i]);
        }

        std::sort(distances.begin(), distances.end());
        std::vector<int> nearestLabels;
        for (int i = 0; i < k && i < (int)distances.size(); ++i) {
            nearestLabels.push_back(distances[i].second);
        }

        predictions.push_back(getMostFrequentLabel(nearestLabels));
    }

    return predictions;
}

double KNN::evaluate(const std::vector<int>& yTest, const std::vector<int>& yPred) const {
    if (yTest.size() != yPred.size()) {
        throw std::invalid_argument("Test labels and predictions must have the same length");
    }

    int correct = 0;
    for (size_t i = 0; i < yTest.size(); ++i) {
        if (yTest[i] == yPred[i]) {
            correct++;
        }
    }
    return static_cast<double>(correct) / yTest.size();
}
