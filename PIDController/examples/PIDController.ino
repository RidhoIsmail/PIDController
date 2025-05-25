/* 
  Library ini dibuat oleh Ridho (K.157.25.17) programmer robot KRAI 2025
  dengan tujuan untuk memudahkan komputasi algoritma PID, dan berikut merupakan contoh implementasi penggunaannya
  kalo masih ada error harap maklum hehe
*/

#include "PIDController.h"

PIDController pid(2.0, 0.5, 1.0);

int motorPin = 9;
float setpoint = 100.0;
float sensorValue = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  pid.setOutputLimits(0, 255);
}

void loop() {
  sensorValue = analogRead(A0); // misal sensor kecepatan motor
  float output = pid.compute(setpoint, sensorValue);
  
  if (output >= 0) {
    analogWrite(motorPin, output);
    Serial.print("Output PID: ");
    Serial.println(output);
  }

  delay(10);
}
