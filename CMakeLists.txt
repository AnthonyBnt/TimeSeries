cmake_minimum_required(VERSION 3.29)
project(TimeSeries)

set(CMAKE_CXX_STANDARD 20)

add_executable(TimeSeries main.cpp
        TimeSeriesGenerator.h
        TimeSeriesGenerator.cpp
        GaussianGenerator.cpp
        StepGenerator.h
        StepGenerator.cpp
        SinWaveGenerator.h
        SinWaveGenerator.cpp
        TimeSeriesDataset.h
        TimeSeriesDataset.cpp
        KNN.cpp
        KNN.h)
