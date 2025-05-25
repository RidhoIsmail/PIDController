# PIDController Library

Library sederhana untuk mengimplementasikan kontrol PID pada motor menggunakan Arduino atau mikrokontroler lainnya. Dibuat oleh Ridho Programmer KRAI 2025.

## Fitur
- PID controller (Proportional, Integral, Derivative)
- Dapat digunakan untuk kontrol kecepatan dan posisi
- Dapat diintegrasikan dengan sistem motor dan sensor

## Cara Penggunaan

```cpp
PIDController pid(2.0, 0.5, 1.0);
float output = pid.compute(setpoint, input);
