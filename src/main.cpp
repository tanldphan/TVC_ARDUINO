#include <Arduino.h>
#include <string.h>

#include "BMI088.h"

// BMI088
constexpr uint8_t CS_ACCEL = 10;
constexpr uint8_t CS_GYRO  = 9;

Bmi088 imu(SPI, CS_ACCEL, CS_GYRO);

int myFunction(int, int);

void setup()
{
    Serial.begin(115200);
    SPI.begin();
    pinMode(CS_ACCEL, OUTPUT); digitalWrite(CS_ACCEL, HIGH);
    pinMode(CS_GYRO, OUTPUT);  digitalWrite(CS_GYRO, HIGH);

    if (imu.begin() != 0)
    {
        Serial.println("BMI088: init failed");
        while (1);
    }
    imu.setRange(Bmi088::ACCEL_RANGE_24G, Bmi088::GYRO_RANGE_2000DPS);
    imu.setOdr(Bmi088::ODR_1000HZ);
}

void loop()
{
    imu.readSensor();
    Serial.printf("a: %.2f %.2f %.2f | g: %.2f %.2f %.2f\n",
    imu.getAccelX_mss(), imu.getAccelY_mss(), imu.getAccelZ_mss(),
    imu.getGyroX_rads(),  imu.getGyroY_rads(),  imu.getGyroZ_rads());
    delay(5);
}
