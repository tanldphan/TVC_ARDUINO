// Bosch BMI088 Shuttle Board 3.0

#include "imu.h"

namespace imu_
{
    Bmi088Accel accel(Wire, 0x18);
    Bmi088Gyro gyro(SPI, CS);
    float a_x;
    float a_y;
    float a_z;

    float g_x;
    float g_y;
    float g_z;

    bool init()
    {
        Wire.begin();
        SPI.begin();
        delay(50);

        pinMode(CS, OUTPUT);
        digitalWrite(CS, HIGH);

        // debug
        SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
        digitalWrite(CS, LOW);
        SPI.transfer(0x80); // reg 0x00 | read
        uint8_t id = SPI.transfer(0x00);
        digitalWrite(CS, HIGH);
        SPI.endTransaction();
        Serial.printf("Gyro expecting 0x0F WHO_AM_I = 0x%02X\n", id);

        if (accel.begin() != 0 || gyro.begin() != 0) return false;

        accel.setRange(Bmi088Accel::RANGE_12G);
        accel.setOdr(Bmi088Accel::ODR_400HZ_BW_40HZ);
        gyro.setRange(Bmi088Gyro::RANGE_250DPS);
        gyro.setOdr(Bmi088Gyro::ODR_400HZ_BW_47HZ);

        return true;
    }

    void read()
    {
        accel.readSensor();
        gyro.readSensor();

        a_x = accel.getAccelX_mss(); g_x = gyro.getGyroX_rads();
        a_y = accel.getAccelY_mss(); g_y = gyro.getGyroY_rads();
        a_z = accel.getAccelZ_mss(); g_z = gyro.getGyroZ_rads();

        Serial.printf("a: %.2f %.2f %.2f | g: %.2f %.2f %.2f\n",
            a_x, a_y, a_z, g_x, g_y, g_z);
    }
}