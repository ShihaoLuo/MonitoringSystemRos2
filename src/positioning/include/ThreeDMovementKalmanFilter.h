#pragma once
#include <eigen3/Eigen/Dense>
#include <iostream>

class ThreeDMovementKalmanFilter
{
public:
    ThreeDMovementKalmanFilter(float samplingTime, 
        int initialLocation[3], 
        int initialuncertainty,
        float accRandVar,
        int measurementErrorStandardDeviation);
    ~ThreeDMovementKalmanFilter();
    Eigen::Matrix<float, 6, 1> predict();
    void update(std::array<int32_t, 3> measuredLocation);

private:
    Eigen::Matrix<float, 6, 1> states0, states1; //states1 = statesTransitionMatrix*states0
    Eigen::Matrix<float, 6, 6> statesTransitionMatrix;
    Eigen::Matrix<float, 6, 6> estimateUncertaintyMatrix0, estimateUncertaintyMatrix1, processNoiseMatrix;
    //estimateUncertaintyMatrix1=statesTransitionMatrix*estimateUncertaintyMatrix0*statesTransitionMatrix.transpose()+processNoiseMatrix
    Eigen::Matrix<float, 3, 1> measurementVector;
    Eigen::Matrix<float, 3, 6> observationMatrix;
    Eigen::Matrix<float, 3, 3> measurementUncertainty;
    Eigen::Matrix<float, 6, 3> kalmanGain;
    Eigen::Matrix<float, 6, 6> identityMatrix;
    
    float samplingTime;


};