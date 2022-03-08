#pragma once 
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <array>
#include <memory>

class Planning
{
public:
    Planning();
    ~Planning();
    void update(float tx, float ty, float tz, float x1, float y1, float z1, float x2, float y2, float z2, float dTD, float dDD);
    std::array<float, 8UL> compute();
    

private:
    const float eps = 1;
    std::array<float, 3UL> targetPoint, d1Point, d2Point, oldD2Goalpoint = {-10000, -10000, -10000};
    float dTD_, dDD_;

    std::array<float, 5UL> getCircleIntersection(float x1, float y1, float r1, float x2, float y2, float r2);
    std::array<float, 4UL> getNewPosition(float tx, float ty, float tz, float x1, float y1, float z1, float d);


};


