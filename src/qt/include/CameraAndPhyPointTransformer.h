#pragma
#include "Eigen/Dense"
#include <iostream>

class CameraAndPhyPointTransformer
{
public:
    CameraAndPhyPointTransformer(Eigen::Matrix4f intrinsicMatrix_);
    ~CameraAndPhyPointTransformer();
    void setProjectMatrix(Eigen::Matrix4f TCW);// pixel to world.
    Eigen::Matrix<float, 4, 1> getCameraPoint(std::array<float, 4UL> phyLocation);
    Eigen::Matrix3f rotX(float alpha);
    Eigen::Matrix3f rotY(float beta);
    Eigen::Matrix3f rotZ(float gama);

private:
    Eigen::Matrix4f intrinsicMatrix, projectMatrix;
    Eigen::Matrix4f w2cTMatrix, c2wTMatrix;

};