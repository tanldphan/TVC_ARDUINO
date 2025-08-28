// Bosch BMI088 Shuttle Board 3.0

#include "imu.h"

namespace imu_spi
{
    Bmi088 imu(SPI, CS_ACCEL, CS_GYRO);

    bool init()
    {
        pinMode(CS_ACCEL, OUTPUT); digitalWrite(CS_GYRO, HIGH);
        pinMode(CS_GYRO, OUTPUT); digitalWrite(CS_GYRO, HIGH);
        if (imu.begin() != 0) return false; // SPI specific
        
        imu.setRange(Bmi088::ACCEL_RANGE_12G, Bmi088::GYRO_RANGE_250DPS);
        imu.setOdr(Bmi088::ODR_400HZ);
        return true;
    }

    void read()
    {
        imu.readSensor();
        a_x = imu.getAccelX_mss(); g_x = imu.getGyroX_rads();
        a_y = imu.getAccelY_mss(); g_y = imu.getGyroY_rads();
        a_z = imu.getAccelZ_mss(); g_z = imu.getGyroZ_rads();

        Serial.printf("a: %.2f %.2f %.2f | g: %.2f %.2f %.2f\n",
                        a_x, a_y, a_z, g_x, g_y, g_z);
    }
}