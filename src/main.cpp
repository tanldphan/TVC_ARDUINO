#include <Arduino.h>
#include <string.h>

#include "imu.h"

void setup()
{
    imu_init();
}

void loop()
{
    imu_read();
}
