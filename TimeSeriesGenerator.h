#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <iostream>
#include <vector>

using namespace std;

class TimeSeriesGenerator {
protected:
    int seed;

public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int);

    virtual vector<double> generateTimeSeries(int) = 0;
    void printTimeSeries(const vector<double> &);

    virtual ~TimeSeriesGenerator();
};



#endif //TIMESERIESGENERATOR_H
