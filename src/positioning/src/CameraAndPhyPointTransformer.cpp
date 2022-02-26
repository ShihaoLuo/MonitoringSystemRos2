#include "CameraAndPhyPointTransformer.h"

CameraAndPhyPointTransformer::CameraAndPhyPointTransformer(Eigen::Matrix4f inMatrix)
{
    intrinsicMatrix = inMatrix;
    
}

CameraAndPhyPointTransformer::~CameraAndPhyPointTransformer(){}

void CameraAndPhyPointTransformer::setProjectMatrix(Eigen::Matrix4f TCW)
{
    c2wTMatrix = TCW;
    projectMatrix = intrinsicMatrix*c2wTMatrix;
    // std::cout<<"TCW:"<<c2wTMatrix<<std::endl;
    // std::cout<<"intrinsicMatrix"<<intrinsicMatrix<<std::endl;
    // std::cout<<"pMatrix:"<<projectMatrix<<std::endl;
}

Eigen::Matrix<float, 4, 1> CameraAndPhyPointTransformer::getCameraPoint(std::array<float, 4UL> phyLocation)
{
    Eigen::Matrix<float, 4, 1> targetPW_;
    memcpy(targetPW_.data(), phyLocation.data(), 16);
    // std::cout<<"phypoint:"<<targetPW_<<std::endl;
    auto tmp2 = projectMatrix*targetPW_;
    auto tmp = tmp2/tmp2[2];
    // std::cout<<"PixelP:"<<tmp<<std::endl;
    return tmp;
}

Eigen::Matrix3f CameraAndPhyPointTransformer::rotX(float alpha)
{
    Eigen::Matrix3f rX;
    rX << 1, 0, 0, 
            0, cosf32(alpha), -sinf32(alpha),
            0, sinf32(alpha), cosf32(alpha);
    return rX;
}

Eigen::Matrix3f CameraAndPhyPointTransformer::rotY(float beta)
{
    Eigen::Matrix3f rY;
    rY << cosf32(beta), 0, sinf32(beta),
            0, 1, 0,
            -sinf32(beta), 0, cosf32(beta);
    return rY;
}

Eigen::Matrix3f CameraAndPhyPointTransformer::rotZ(float gama)
{
    Eigen::Matrix3f rZ;
    rZ << cosf32(gama), -sinf32(gama),0 ,
            sinf32(gama), cosf32(gama), 0,
            0, 0, 1, 0;
    return rZ;
}
