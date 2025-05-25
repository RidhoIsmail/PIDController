#include "PIDController.h"
#include <Arduino.h>

PIDController::PIDController(float kp, float ki, float kd) {
  setTunings(kp, ki, kd);
  _outputMin = 0;
  _outputMax = 255;
  _integral = 0;
  _previousError = 0;
  _sampleTime = 100;
  _lastTime = millis();
}

void PIDController::setTunings(float kp, float ki, float kd) {
  _kp = kp;
  _ki = ki;
  _kd = kd;
}

void PIDController::setOutputLimits(float min, float max) {
  _outputMin = min;
  _outputMax = max;
}

void PIDController::setSampleTime(unsigned long newSampleTime) {
  _sampleTime = newSampleTime;
}

float PIDController::hitung(float setpoint, float input) {
  unsigned long now = millis();
  unsigned long timeChange = now - _lastTime;

  if (timeChange >= _sampleTime) {
    float error = setpoint - input;
    _integral += error * (_sampleTime / 1000.0);
    float derivative = (error - _previousError) / (_sampleTime / 1000.0);

    float output = _kp * error + _ki * _integral + _kd * derivative;

    // Clamp output
    if (output > _outputMax) output = _outputMax;
    else if (output < _outputMin) output = _outputMin;

    _previousError = error;
    _lastTime = now;

    return output;
  }

  return -1; // indicates no update
}

void PIDController::reset() {
  _integral = 0;
  _previousError = 0;
  _lastTime = millis();
}
