#include <Arduino.h>
#include <string.h>

#include "imu.h"
#include "bps.h"
#include "xyservo.h"
#include "utils.h"

void setup()
{
    Serial.begin(115200);
    while (!Serial && millis() < 3000) {}
    Serial.println("Booting...");
    SPI.begin();

    initializer("IMU", IMU::init);
    initializer("BPS", BPS::init);
}

void loop()
{
    IMU::read();
    BPS::read();
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