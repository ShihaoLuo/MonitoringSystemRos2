#pragma once
#include <eigen3/Eigen/Dense>
#include <iostream>

class TwoDMovementKalmanFilter
{
public:
    TwoDMovementKalmanFilter(float samplingTime, 
        int initialLocation[2], 
        int initialuncertainty,
        float accRandVar,
        int measurementErrorStandardDeviation);
    ~TwoDMovementKalmanFilter();
    Eigen::Matrix<float, 4, 1> predict();
    void update(std::array<int32_t, 2> measuredLocation);

private:
    Eigen::Matrix<float, 4, 1> states0, states1; //states1 = statesTransitionMatrix*states0
    Eigen::Matrix<float, 4, 4> statesTransitionMatrix;
    Eigen::Matrix<float, 4, 4> estimateUncertaintyMatrix0, estimateUncertaintyMatrix1, processNoiseMatrix;
    //estimateUncertaintyMatrix1=statesTransitionMatrix*estimateUncertaintyMatrix0*statesTransitionMatrix.transpose()+processNoiseMatrix
    Eigen::Matrix<float, 2, 1> measurementVector;
    Eigen::Matrix<float, 2, 4> observationMatrix;
    Eigen::Matrix<float, 2, 2> measurementUncertainty;
    Eigen::Matrix<float, 4, 2> kalmanGain;
    Eigen::Matrix<float, 4, 4> identityMatrix;
    
    float samplingTime;


};