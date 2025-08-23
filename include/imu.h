// Bosch BMI088 Shuttle Board 3.0 Flyer

#pragma once

#include <stdint.h>
#include "BMI088.h"

namespace IMUmodule
{
    static constexpr uint8_t CS_ACCEL = 10;
    static constexpr uint8_t CS_GYRO  = 9;

    extern Bmi088 imu;

    bool init();
    void read();
}