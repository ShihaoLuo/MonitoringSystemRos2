#include "2DMovementKalmanFilter.h"

TwoDMovementKalmanFilter::TwoDMovementKalmanFilter(float samplingTime_, 
    int initialLocation[2], 
    int initialuncertainty,
    int measurementErrorStandardDeviation)
{
    samplingTime = samplingTime_;
    states0 << initialLocation[0], 0, initialLocation[1], 0;
    states1 << initialLocation[0], 0, initialLocation[1], 0;
    estimateUncertaintyMatrix0 << initialuncertainty, 0, 0, 0,
        0, initialuncertainty, 0, 0,
        0, 0, initialuncertainty, 0,
        0, 0, 0, initialuncertainty;
    estimateUncertaintyMatrix1 << initialuncertainty, 0, 0, 0,
        0, initialuncertainty, 0, 0,
        0, 0, initialuncertainty, 0,
        0, 0, 0, initialuncertainty;
    identityMatrix << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
    measurementUncertainty << measurementErrorStandardDeviation*measurementErrorStandardDeviation,0 , measurementErrorStandardDeviation*measurementErrorStandardDeviation, 0;
}

TwoDMovementKalmanFilter::~TwoDMovementKalmanFilter(){}

void TwoDMovementKalmanFilter::predict()
{
    states1 = statesTransitionMatrix*states0;
    estimateUncertaintyMatrix1 = statesTransitionMatrix*estimateUncertaintyMatrix0*statesTransitionMatrix.transpose()+processNoiseMatrix;
}

void TwoDMovementKalmanFilter::update(int measuredLocation[2])
{
    measurementVector << measuredLocation[0], measuredLocation[1];
    kalmanGain = estimateUncertaintyMatrix1*observationMatrix.transpose()*
        (observationMatrix*estimateUncertaintyMatrix1*observationMatrix.transpose()+measurementUncertainty).inverse();
    states0 = states1 + kalmanGain*(measurementVector-observationMatrix*states1);
    estimateUncertaintyMatrix0 = (identityMatrix-kalmanGain*observationMatrix)*estimateUncertaintyMatrix1*
        (identityMatrix-kalmanGain*observationMatrix).transpose()+kalmanGain*measurementUncertainty*kalmanGain.transpose();
}