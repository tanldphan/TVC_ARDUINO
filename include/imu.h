// Bosch BMI088 Shuttle Board 3.0

#pragma once

#include <stdint.h>
#include "BMI088.h"

namespace imu_
{
    // static constexpr uint8_t SCK = 13;
    // static constexpr uint8_t SDO = 12;
    // static constexpr uint8_t SDI = 11;
    static constexpr uint8_t CS = 10;

    extern Bmi088Accel accel;
    extern Bmi088Gyro gyro;

    extern float a_x;
    extern float a_y;
    extern float a_z;

    extern float g_x;
    extern float g_y;
    extern float g_z;

    bool init();
    void read();
}