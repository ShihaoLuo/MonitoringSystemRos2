#include "targetPosition.h"

TargetPosition::TargetPosition(Eigen::Matrix4f inMatrix)
{
    intrinsicMatrix = inMatrix;
    
}

TargetPosition::~TargetPosition(){}

void TargetPosition::setTransformMatrix(std::array<float, 4UL> location)
{
    float theta = -location[3];
    Eigen::Matrix3f w2bRMatrix, b2cRMatrix;
    Eigen::Matrix4f w2cTMatrix, w2bTMatrix, b2cTMatrix;
    w2bRMatrix=rotX(-1.5708f)*rotY(1.5708f)*rotZ(0.f);//内旋静态
    b2cRMatrix=rotZ(-1.5f/180.0f*3.1416f)*rotY(-location[3])*rotX(-14.5f/180.0f*3.1416f);//外旋静态
    w2bTMatrix<<w2bRMatrix(0,0), w2bRMatrix(0,1), w2bRMatrix(0,2), location[0],
                w2bRMatrix(1,0), w2bRMatrix(1,1), w2bRMatrix(1,2), location[1],
                w2bRMatrix(2,0), w2bRMatrix(2,1), w2bRMatrix(2,2), location[2],
                0, 0, 0, 1;
    b2cTMatrix<<b2cRMatrix(0,0), b2cRMatrix(0,1), b2cRMatrix(0,2), 0,
                b2cRMatrix(1,0), b2cRMatrix(1,1), b2cRMatrix(1,2), 0,
                b2cRMatrix(2,0), b2cRMatrix(2,1), b2cRMatrix(2,2), 0,
                0, 0, 0, 1;
    w2cTMatrix=w2bTMatrix*b2cTMatrix;
    c2wTMatrix = w2cTMatrix.inverse();
    std::cout<<"w2c:"<<w2cTMatrix<<std::endl;
    std::cout<<"c2w:"<<c2wTMatrix<<std::endl;
    std::cout<<"intrinsic:"<<intrinsicMatrix<<std::endl;
    p2wTMatrix = intrinsicMatrix*c2wTMatrix;
}

Eigen::Matrix<float, 4, 1> TargetPosition::getPixelCoor(std::array<float, 3UL> targetPW)
{
    Eigen::Matrix<float, 4, 1> targetPW_;
    targetPW_<<targetPW[0], targetPW[1], targetPW[2], 1;
    auto tmp1 =  c2wTMatrix*targetPW_;
    auto tmp2 = intrinsicMatrix*tmp1;
    auto tmp = tmp2/tmp2[2];
    std::cout<<"P:"<<targetPW_<<std::endl;
    std::cout<<"PC:"<<tmp1<<std::endl;
    std::cout<<"PP:"<<tmp<<std::endl;
    return tmp;
}

Eigen::Matrix3f TargetPosition::rotX(float alpha)
{
    Eigen::Matrix3f rX;
    rX << 1, 0, 0, 
            0, cosf32(alpha), -sinf32(alpha),
            0, sinf32(alpha), cosf32(alpha);
    return rX;
}

Eigen::Matrix3f TargetPosition::rotY(float beta)
{
    Eigen::Matrix3f rY;
    rY << cosf32(beta), 0, sinf32(beta),
            0, 1, 0,
            -sinf32(beta), 0, cosf32(beta);
    return rY;
}

Eigen::Matrix3f TargetPosition::rotZ(float gama)
{
    Eigen::Matrix3f rZ;
    rZ << cosf32(gama), -sinf32(gama),0 ,
            sinf32(gama), cosf32(gama), 0,
            0, 0, 1, 0;
    return rZ;
}
