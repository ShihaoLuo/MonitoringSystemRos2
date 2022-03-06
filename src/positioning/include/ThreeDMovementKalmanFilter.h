#pragma once
#include <eigen3/Eigen/Dense>
#include <iostream>

class ThreeDMovementKalmanFilter
{
public:
    ThreeDMovementKalmanFilter();
    ~ThreeDMovementKalmanFilter();
    Eigen::Matrix<float, 6, 1> predict();
    void update(std::array<float, 3> measuredLocation);
    void initial(
        float samplingTime, 
        std::array<float, 3UL> initialLocation, 
        float initialuncertainty,
        float accRandVar,
        float measurementErrorStandardDeviation);

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