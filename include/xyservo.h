// TowerPro MG92B

#pragma once

#include <stdint.h>
#include <Servo.h> // Arduino's

namespace servo_pwm
{
    static constexpr uint8_t SERVO_X_GPIO = 5;
    static constexpr uint8_t SERVO_Y_GPIO = 19;

    extern Servo servo_x;
    extern Servo servo_y;

    bool init();
}