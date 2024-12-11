#include "StepGenerator.h"
#include "KNN.h"
#include "TimeSeriesDataset.h"
#include "SinWaveGenerator.h"
#include "GaussianGenerator.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialisation des datasets
    TimeSeriesDataset trainData(false, true), testData(false, false);

    // Générateurs de séries temporelles
    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;

    // Ajout des séries temporelles au dataset d'entraînement
    vector<double> gaussian1 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian1, 0);

    vector<double> gaussian2 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian2, 0);

    vector<double> sin1 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin1, 1);

    vector<double> sin2 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin2, 1);

    vector<double> step1 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step1, 2);

    vector<double> step2 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step2, 2);

    // Ajout des séries temporelles au dataset de test
    vector<int> ground_truth;

    testData.addTimeSeries(gsg.generateTimeSeries(11));
    ground_truth.push_back(0);

    testData.addTimeSeries(swg.generateTimeSeries(11));
    ground_truth.push_back(1);

    testData.addTimeSeries(stg.generateTimeSeries(11));
    ground_truth.push_back(2);

    // Évaluation avec KNN
    KNN knn_1(1, "dtw");
    cout << "Accuracy (K=1, DTW): "
         << knn_1.evaluate(ground_truth, knn_1.predict(trainData, testData))
         << endl;

    KNN knn_2(2, "euclidean");
    cout << "Accuracy (K=2, Euclidean): "
         << knn_2.evaluate(ground_truth, knn_2.predict(trainData, testData))
         << endl;

    KNN knn_3(3, "euclidean");
    cout << "Accuracy (K=3, Euclidean): "
         << knn_3.evaluate(ground_truth, knn_3.predict(trainData, testData))
         << endl;

    return 0;
}



