#include "planning.h"

Planning::Planning(){}

Planning::~Planning(){}

std::array<float, 5UL> Planning::getCircleIntersection(float x1, float y1, float r1, float x2, float y2, float r2)
{
    std::array<float, 5UL> result;
    // std::cout<<"input:"<<x1<<" "<<y1<<" "<<r1<<" "<<x2<<" "<<y2<<" "<<r2<<std::endl;
    float d = sqrtf32((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    // std::cout<<"d:"<<d<<std::endl;
    if(d > (r1+r2))
    {
        // std::cout<<"no inter section, one circle outside the other.."<<std::endl;
        result[0] = -1;
        return result;
    }
    if(d == (r1 + r2))
    {
        // std::cout<<"one inter section, one circle outside the other.."<<std::endl;
        result[0] = 1;
        return result;
    }
    if((d < (r1+r2)) && (d > fabs(r1 - r2)))
    {
        // std::cout<<"two inter section."<<std::endl;
        
        float d2 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        float a = r1*(x1-x2)*2;
        float b = r1*(y1-y2)*2;
        float c = r2*r2-r1*r1-d2;
        float p = a*a+b*b;
        float q = -a*c*2;
        float r = c*c-b*b;
        float cosa, cosb, sina, sinb;
        float delta = sqrtf32(q*q-4*p*r);
        cosa = (-q+delta)/2/p;
        cosb = (-q-delta)/2/p;
        sina = sqrtf32(1-cosa*cosa);
        sinb = sqrtf32(1-cosb*cosb);
        float x11 = x1 + r1*cosa;
        float y11 = y1 + r1*sina;
        if(sqrtf32((x11-x2)*(x11-x2) + (y11-y2)*(y11-y2)) - r2 > eps)
        {
            y11 = y1 - r1*sina;
        }
        float x22 = x1 + r1*cosb;
        float y22 = y1 + r1*sinb;
        // std::cout<<"x11:"<<x11<<" "<<y11<<std::endl;
        if(fabs(sqrtf32((x22-x2)*(x22-x2) + (y22-y2)*(y22-y2)) - r2) > eps)
        {
            y22 = y1 - r1*sina;
        }
        // std::cout<<"x22:"/<<x22<<" "<<y22<<std::endl;
        result[0] = 2;
        result[1] = x11;
        result[2] = y11;
        result[3] = x22;
        result[4] = y22;
        return result;
    }
    if(d == fabs(r1 - r2))
    {
        // std::cout<<"one inter section, one circle inside the other.."<<std::endl;
        result[0] = 1;
        return result;
    }
    if(d < fabs(r1 - r2))
    {
        // std::cout<<"no inter section, one circle inside the other.."<<std::endl;
        result[0] = -1;
        return result;
    }
}

std::array<float, 4UL> Planning::getNewPosition(float tx, float ty, float tz, float x1, float y1, float z1, float d)
{
    std::array<float, 4UL> result;
    result[3] = atan2f32(ty-y1, tx-x1);
    float l = sqrtf32((tx-x1)*(tx-x1)+(ty-y1)*(ty-y1));
    result[0] = tx - (tx-x1)*d/l;
    result[1] = ty - (ty-y1)*d/l;
    result[2] = tz;
    return result;
}

void Planning::update(float tx, float ty, float tz, float x1, float y1, float z1, float x2, float y2, float z2, float dTD, float dDD)
{
    targetPoint[0] = tx;
    targetPoint[1] = ty;
    targetPoint[2] = tz;
    d1Point[0] = x1;
    d1Point[1] = y1;
    d1Point[2] = z1;
    d2Point[0] = x2;
    d2Point[1] = y2;
    d2Point[2] = z2;
    dTD_ = dTD;
    dDD_ = dDD;
}

std::array<float, 8UL> Planning::compute()
{
    std::array<float, 8UL> result;
    auto goalPosition1 =  getNewPosition(targetPoint[0], targetPoint[1], targetPoint[2], d1Point[0], d1Point[1], d1Point[2], dTD_);
    auto tmp1 = getCircleIntersection(targetPoint[0], targetPoint[1], dTD_, goalPosition1[0], goalPosition1[1], dDD_);
    // std::cout<<"1 :"<<goalPosition1[0]<<" "<<goalPosition1[1]<<" "<<goalPosition1[2]<<" "<<goalPosition1[3]<<std::endl;
    // std::cout<<"2 :"<<tmp1[0]<<" "<<tmp1[1]<<" "<<tmp1[2]<<" "<<tmp1[3]<<" "<<tmp1[4]<<" "<<std::endl;
    // std::cout<<"d2point: "<<d2Point[0]<<" "<<d2Point[1]<<" "<<d2Point[2]<<std::endl;
    // std::cout<<"d:"<<dTD_<<" "<<dDD_;
    memcpy(result.data(), goalPosition1.data(), 16);
    float theta1 = atan2f32(-goalPosition1[1]+tmp1[2], -goalPosition1[0]+tmp1[1]);
    float theta2 = atan2f32(-goalPosition1[1]+tmp1[4], -goalPosition1[0]+tmp1[3]);
    // float d1, d2;
    // if(fabs(theta1 - d2Point[2]) < fabs(theta2 - d2Point[2]))
    // {
    //     result[4] = tmp1[1];
    //     result[5] = tmp1[2];
    //     result[6] = targetPoint[2];
    //     result[7] = theta1;
    // }else
    // {
    //     result[4] = tmp1[3];
    //     result[5] = tmp1[4];
    //     result[6] = targetPoint[2];
    //     result[7] = theta2;
    // }
    // if(oldD2Goalpoint[0] == -10000)
    // {
    //     d1 = (d2Point[0]-tmp1[1])*(d2Point[0]-tmp1[1]) + (d2Point[1]-tmp1[2])*(d2Point[1]-tmp1[2]) + (d2Point[2]-theta1)*(d2Point[2]-theta1);
    //     d2 = (d2Point[0]-tmp1[3])*(d2Point[0]-tmp1[3]) + (d2Point[1]-tmp1[4])*(d2Point[1]-tmp1[4]) + (d2Point[2]-theta2)*(d2Point[2]-theta2);
    // }
    // else
    // {
    //     d1 = (oldD2Goalpoint[0]-tmp1[1])*(oldD2Goalpoint[0]-tmp1[1]) + (oldD2Goalpoint[1]-tmp1[2])*(oldD2Goalpoint[1]-tmp1[2]) + (oldD2Goalpoint[2]-theta1)*(oldD2Goalpoint[2]-theta1);
    //     d2 = (oldD2Goalpoint[0]-tmp1[3])*(oldD2Goalpoint[0]-tmp1[3]) + (oldD2Goalpoint[1]-tmp1[4])*(oldD2Goalpoint[1]-tmp1[4]) + (oldD2Goalpoint[2]-theta2)*(oldD2Goalpoint[2]-theta2);
    // }
    if(theta1 < theta2)
    {
        result[4] = tmp1[1];
        result[5] = tmp1[2];
        result[6] = targetPoint[2];
        result[7] = atan2f32(targetPoint[1]-tmp1[2], targetPoint[0]-tmp1[1]);
    }else
    {
        result[4] = tmp1[3];
        result[5] = tmp1[4];
        result[6] = targetPoint[2];
        result[7] = atan2f32(targetPoint[1]-tmp1[4], targetPoint[0]-tmp1[3]);
    }
    // oldD2Goalpoint[0] = result[4];
    // oldD2Goalpoint[1] = result[5];
    // oldD2Goalpoint[2] = result[7];
    return result;
}