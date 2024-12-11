#include "TimeSeriesGenerator.h"

#include <random>

TimeSeriesGenerator::TimeSeriesGenerator() :
seed(0) {}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed) :
seed(_seed) {}

void TimeSeriesGenerator::printTimeSeries(const vector<double> &TimeSeries) {
    for(double value : TimeSeries) {
        cout << value << " ";
    }
    cout << endl;
}






