# PIDController

Ini adalah library PID sederhana untuk Arduino, dibuat oleh Ridho (K.157.25.17) programmer KRAI 2025.

## Cara Penggunaan

```cpp
#include "PIDController.h"

PIDController pid(1.5, 0.2, 0.1);
float output = pid.hitung(setpoint, input);