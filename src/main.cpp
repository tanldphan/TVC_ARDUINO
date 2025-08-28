#include <Arduino.h>
#include <TeensyThreads.h>
#include <string.h>

#include "imu.h"
#include "bps.h"
#include "xyservo.h"
#include "utils.h"
#include "kalman.h"

void setup()
{
    Serial.begin(115200);
    while (!Serial && millis() < 3000) {}
    Serial.println("Booting...");
    SPI.begin();
    KalmanFilter::Kalman kf;
    KalmanFilter::init(kf, 0.f,0.f,0.f,0.f,0.f,0.f,0.f);

    initializer("IMU", imu_spi::init);
    initializer("BPS", bps_spi::init);

}

void loop()
{
    servo_pwm::servo_x.write(90);
    servo_pwm::servo_y.write(90);
    delay(1000);
    servo_pwm::servo_x.write(180);
    servo_pwm::servo_y.write(180);
    delay(1000);
    servo_pwm::servo_x.write(270);
    servo_pwm::servo_y.write(270);
    delay(1000);
    servo_pwm::servo_x.write(0);
    servo_pwm::servo_y.write(0);
    //imu_spi::read();

    // bps_spi::alt_r;
    // bps_spi::p;
    // bps_spi::p0;
    // bps_spi::temp;

    // imu_spi::a_x;
}

// void worker()
// {
//     while(1)
//     {
//         imu_spi::read;
//         bps_spi::read;
//         delay(250);
//     }
// }
