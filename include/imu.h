// Bosch BMI088 Shuttle Board 3.0 Flyer

#pragma once

#include <stdint.h>
#include "BMI088.h"

namespace IMUmodule
{
    extern Bmi088 imu;

    static constexpr uint8_t CS_ACCEL = 10;
    static constexpr uint8_t CS_GYRO  = 9;

    float a_x;
    float a_y;
    float a_z;

    float g_x;
    float g_y;
    float g_z;

    bool init();
    void read();
}