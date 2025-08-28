// TowerPro MG92B
#include <Arduino.h>
#include "xyservo.h"

namespace servo_pwm
{
    Servo servo_x;
    Servo servo_y;

    bool init()
    {
        uint8_t ch_x = servo_x.attach(SERVO_X_GPIO);
        uint8_t ch_y = servo_y.attach(SERVO_Y_GPIO);
        Serial.println(ch_x);
        Serial.println(ch_y);
        if (ch_x == 0 || ch_y == 0)
        {
            return false;
        }

        servo_x.write(0);
        servo_y.write(0);
        return true;
    }
}