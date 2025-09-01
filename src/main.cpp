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
    while (!Serial && millis() < 3000)
    {
        // wait
    }
    Serial.println("Booting...");
    //SPI.begin();
    KalmanFilter::Kalman kf;
    KalmanFilter::init(kf, 0.f,0.f,0.f,0.f,0.f,0.f,0.f);

    initializer("IMU", imu_::init);
    initializer("BPS", bps_::init);
}

void loop()
{
    // servo_pwm::servo_x.write(180);
    // servo_pwm::servo_y.write(180);
    // delay(1000);
    // servo_pwm::servo_x.write(0);
    // servo_pwm::servo_y.write(0);
    imu_::read();
    bps_::read();
    delay(250);
}

// void worker()
// {
//     while(1)
//     {
//         imu_::read;
//         bps_::read;
//         delay(250);
//     }
// }
