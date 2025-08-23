// Bosch BMI088 Shuttle Board 3.0 Flyer

#pragma once

#include <stdint.h>
#include "BMI088.h"

namespace IMU
{
    static constexpr uint8_t IMU_CS_ACCEL = 10;
    static constexpr uint8_t IMU_CS_GYRO  = 9;

    extern Bmi088 imu;
    
    bool init();
    void read();
}