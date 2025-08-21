#include <Arduino.h>
#include <string.h>

#include "imu.h"
#include "bps.h"
#include "xyservo.h"

void setup()
{
    Serial.begin(115200);
    while (!Serial && millis() < 3000) {}
    Serial.println("Booting...");
    SPI.begin();

    if (!imu_init())
    {
        Serial.println("IMU failed to start!");
    }
    Serial.println("IMU started!");

    if (!bps_init())
    {
        Serial.println("BPS failed to start!");
    }
    Serial.println("BPS started!");

    if (!ServoControl::init())
    {
        Serial.println("SERVO failed to start!");
    }
    Serial.println("SERVO started!");
    
    Serial.println("Setup complete, entering loop");

}

void loop()
{
    imu_read();
    bps_read();
    ServoControl::servo_x.write(90);
    ServoControl::servo_y.write(90);
    delay(1000);
    ServoControl::servo_x.write(180);
    ServoControl::servo_y.write(180);
    delay(1000);
    ServoControl::servo_x.write(270);
    ServoControl::servo_y.write(270);
    delay(1000);
    ServoControl::servo_x.write(0);
    ServoControl::servo_y.write(0);
}