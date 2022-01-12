#include <iostream>

class PID
{
private:
    float kp, ki, kd, target, actual, e, e_pre, intergral, Maxout, Minout, Maxintergral, Minintergral;
public:
    PID();
    ~PID();
    PID(float p, float i, float d);
    float pid_control(float tar, float act);
    void setLimits(float min, float max);
    void setPID(float p, float i, float d);
    void reset();
};
