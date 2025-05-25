#ifndef PIDController_h
#define PIDController_h

#include <Arduino.h>

class PIDController{
  public:
    PIDController(float kp, float ki, float kd);
    void setTunings(float kp, float ki, float kd);
    void setOutputLimits(float min, float max);
    void setSampleTime(unsigned long newSampleTime);
    
    float hitung(float setpoint, float input);

    void reset();
    
  private:
    float _kp;
    float _ki;
    float _kd;

    float _integral;
    float _previousError;
    float _outputMin;
    float _outputMax;

    unsigned long _lastTime;
    unsigned long _sampleTime;
};

#endif