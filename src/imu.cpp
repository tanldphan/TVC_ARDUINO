// Bosch BMI088 Shuttle Board 3.0 Flyer

#include "imu.h"
Bmi088 imu(SPI, IMU_CS_ACCEL, IMU_CS_GYRO);

bool imu_init()
{
    pinMode(IMU_CS_ACCEL, OUTPUT); digitalWrite(IMU_CS_ACCEL, HIGH);
    pinMode(IMU_CS_GYRO, OUTPUT);  digitalWrite(IMU_CS_GYRO, HIGH);

    if (imu.begin() == 0)
    {
        Serial.println("IMU: initiated successfully!");
        return true;
    }
    else
    {
        Serial.println("IMU: init failed!");
        return false;
    }
    imu.setRange(Bmi088::ACCEL_RANGE_12G, Bmi088::GYRO_RANGE_250DPS);
    imu.setOdr(Bmi088::ODR_400HZ);
}

void imu_read()
{
    imu.readSensor();
    Serial.printf("a: %.2f %.2f %.2f | g: %.2f %.2f %.2f\n",
    imu.getAccelX_mss(), imu.getAccelY_mss(), imu.getAccelZ_mss(),
    imu.getGyroX_rads(), imu.getGyroY_rads(), imu.getGyroZ_rads());
}