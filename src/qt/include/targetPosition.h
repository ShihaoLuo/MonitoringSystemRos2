#pragma
#include "Eigen/Dense"
#include <iostream>

class TargetPosition
{
public:
    TargetPosition(Eigen::Matrix4f intrinsicMatrix_);
    ~TargetPosition();
    void setTransformMatrix(std::array<float, 4UL> location);// pixel to world.
    Eigen::Matrix<float, 4, 1> getPixelCoor(std::array<float, 3UL> targetWorlPosition);
    Eigen::Matrix3f rotX(float alpha);
    Eigen::Matrix3f rotY(float beta);
    Eigen::Matrix3f rotZ(float gama);

private:
    Eigen::Matrix4f intrinsicMatrix, p2wTMatrix;
    Eigen::Matrix4f w2cTMatrix, c2wTMatrix;

};