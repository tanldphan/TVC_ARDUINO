#pragma once

#include "stdint.h"
#include "BMI088.h"

static constexpr uint8_t CS_ACCEL = 10;
static constexpr uint8_t CS_GYRO  = 9;

extern Bmi088 imu;

void imu_init(void);
void imu_read(void);