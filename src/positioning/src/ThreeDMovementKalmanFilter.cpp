#include "ThreeDMovementKalmanFilter.h"

ThreeDMovementKalmanFilter::ThreeDMovementKalmanFilter(float samplingTime_, 
    int initialLocation[3], 
    int initialuncertainty,
    float accRandVar,
    int measurementErrorStandardDeviation)
{
    samplingTime = samplingTime_;
    states0 << initialLocation[0], 0, initialLocation[1], 0, initialLocation[2], 0;
    states1 << initialLocation[0], 0, initialLocation[1], 0, initialLocation[2], 0;
    statesTransitionMatrix << 
        1, samplingTime, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0,
        0, 0, 1, samplingTime, 0, 0,
        0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 1, samplingTime,
        0, 0, 0, 0, 0, 1;
    estimateUncertaintyMatrix0 << 
        initialuncertainty, 0, 0, 0,0, 0, 
        0, initialuncertainty, 0, 0, 0, 0,
        0, 0, initialuncertainty, 0, 0, 0, 
        0, 0, 0, initialuncertainty, 0, 0,
        0, 0, 0, 0, initialuncertainty, 0,
        0, 0, 0, 0, 0, initialuncertainty;
    estimateUncertaintyMatrix1 << 
        initialuncertainty, 0, 0, 0,0, 0, 
        0, initialuncertainty, 0, 0, 0, 0,
        0, 0, initialuncertainty, 0, 0, 0, 
        0, 0, 0, initialuncertainty, 0, 0,
        0, 0, 0, 0, initialuncertainty, 0,
        0, 0, 0, 0, 0, initialuncertainty;
    identityMatrix << 
        1, 0, 0, 0, 0, 0,  
        0, 1, 0, 0, 0, 0, 
        0, 0, 1, 0, 0, 0, 
        0, 0, 0, 1, 0, 0, 
        0, 0, 0, 0, 1, 0, 
        0, 0, 0, 0, 0, 1;
    measurementUncertainty << 
        measurementErrorStandardDeviation, 0, 0, 
        0, measurementErrorStandardDeviation, 0,
        0, 0, measurementErrorStandardDeviation;
    processNoiseMatrix << 
        powf(samplingTime, 4.0)/4*accRandVar, powf(samplingTime, 3.0)/2*accRandVar, 0, 0, 0, 0,
        powf(samplingTime, 3.0)/2*accRandVar, powf(samplingTime, 2.0)*accRandVar, 0, 0, 0, 0,
        0, 0, powf(samplingTime, 4.0)/4*accRandVar, powf(samplingTime, 3.0)/2*accRandVar, 0, 0,
        0, 0, powf(samplingTime, 3.0)/2*accRandVar, powf(samplingTime, 2.0)*accRandVar, 0, 0, 
        0, 0, 0, 0, powf(samplingTime, 4.0)/4*accRandVar, powf(samplingTime, 3.0)/2*accRandVar,
        0, 0, 0, 0, powf(samplingTime, 3.0)/2*accRandVar, powf(samplingTime, 2.0)*accRandVar;
    observationMatrix << 
        1, 0, 0, 0, 0, 0, 
        0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 1, 0;
}



ThreeDMovementKalmanFilter::~ThreeDMovementKalmanFilter(){}

Eigen::Matrix<float, 6, 1> ThreeDMovementKalmanFilter::predict()
{
    states1 = statesTransitionMatrix*states0;
    estimateUncertaintyMatrix1 = statesTransitionMatrix*estimateUncertaintyMatrix0*statesTransitionMatrix.transpose()+processNoiseMatrix;
    return states1;
}

void ThreeDMovementKalmanFilter::update(std::array<int32_t, 3> measuredLocation)
{
    measurementVector << measuredLocation[0], measuredLocation[1];
    kalmanGain = estimateUncertaintyMatrix1*observationMatrix.transpose()*
        (observationMatrix*estimateUncertaintyMatrix1*observationMatrix.transpose()+measurementUncertainty).inverse();
    states0 = states1 + kalmanGain*(measurementVector-observationMatrix*states1);
    estimateUncertaintyMatrix0 = (identityMatrix-kalmanGain*observationMatrix)*estimateUncertaintyMatrix1*
        (identityMatrix-kalmanGain*observationMatrix).transpose()+kalmanGain*measurementUncertainty*kalmanGain.transpose();
}
