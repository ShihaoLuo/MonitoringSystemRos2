#include "pid.hpp"

PID::PID():kp(0.f), ki(0.f), kd(0.f), target(0.f), actual(0.f), intergral(0.f), Minintergral(-4000.f), Maxintergral(4000.f)
{
   e = target - actual;
   e_pre = e;
}

PID::PID(float p, float i, float d):kp(p), ki(i), kd(d), target(0.f), actual(0.f), intergral(0.f), Minintergral(-4000.f), Maxintergral(4000.f)
{
   e = target - actual;
   e_pre = e;
}

PID::~PID(){}

void PID::reset()
{
   intergral = 0.f;
   e = 0.f;
   e_pre = e;
}

float PID::pid_control(float tar, float act)
{
   float u;
   target = tar;
   actual = act;
   e = target - actual;
   intergral += e;
   if(intergral > Maxintergral) intergral = Maxintergral;
   if(intergral < Minintergral) intergral = Minintergral;
   u = kp*e+ki*intergral+kd*(e-e_pre);
   if(u > Maxout) 
      u = Maxout;
   if(u < Minout) 
      u = Minout;
   e_pre = e;
   // std::cout<<"intergral:"<<intergral<<std::endl;
   return u;
}

void PID::setLimits(float min, float max)
{
   Minout = min;
   Maxout = max;
}

void PID::setPID(float p, float i, float d)
{
   kp = p;
   ki = i;
   kd = d;
}

void PID::setIntergralLimits(float min, float max)
{
   Maxintergral = max;
   Minintergral = min;
}