#include <Arduino.h>
#include <string.h>

#include "imu.h"
#include "bps.h"

void setup()
{
    imu_init();
    bps_init();
}

void loop()
{
    imu_read();
    bps_read();
    delay(1e3); // ms
}
