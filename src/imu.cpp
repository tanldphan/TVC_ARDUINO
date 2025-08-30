// Bosch BMI088 Shuttle Board 3.0

#include "imu.h"

namespace imu_spi
{
    Bmi088 imu(SPI, CS_ACCEL, CS_GYRO);

    float a_x;
    float a_y;
    float a_z;

    float g_x;
    float g_y;
    float g_z;

    uint8_t readAccelWHOAMI()
    {
        digitalWrite(CS_ACCEL, LOW);
        SPI.transfer(0x80);             // read reg 0x00
        uint8_t val = SPI.transfer(0x00);
        digitalWrite(CS_ACCEL, HIGH);
        return val;
    }

    uint8_t readGyroWHOAMI()
    {
        digitalWrite(CS_GYRO, LOW);
        SPI.transfer(0x80);             // read reg 0x00
        uint8_t val = SPI.transfer(0x00);
        digitalWrite(CS_GYRO, HIGH);
        return val;
    }

    bool init()
    {
        pinMode(CS_ACCEL, OUTPUT); digitalWrite(CS_ACCEL, HIGH);
        pinMode(CS_GYRO, OUTPUT); digitalWrite(CS_GYRO, HIGH);
        delay(10);
        //if (imu.begin() != 0) return false; // SPI specific

        SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
        uint8_t accel_id = readAccelWHOAMI();
        uint8_t gyro_id  = readGyroWHOAMI();
        SPI.endTransaction();

        Serial.printf("Accel WHO_AM_I = 0x%02X (expect 0x1E)\n", accel_id);
        Serial.printf("Gyro  WHO_AM_I = 0x%02X (expect 0x0F)\n", gyro_id);


        int status = imu.begin();  // returns diagnostic code
        if (status != 1) {
        Serial.printf("imu.begin() failed with code %d\n", status);
        return false;
        }
        
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