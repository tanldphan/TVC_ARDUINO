// Bosch BMI088 Shuttle Board 3.0 Flyer

#pragma once

#include <stdint.h>
#include "BMI088.h"

namespace imu_spi
{
    // static constexpr uint8_t SCK = 33;
    // static constexpr uint8_t SDO = 34;
    // static constexpr uint8_t SDI = 35;
    static constexpr uint8_t CS_ACCEL = 36;
    static constexpr uint8_t CS_GYRO  = 37;

    extern Bmi088 imu;

    extern float a_x;
    extern float a_y;
    extern float a_z;

    extern float g_x;
    extern float g_y;
    extern float g_z;

    bool init();
    void read();
}