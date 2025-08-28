// Adafruit BMP388

#pragma once

#include <stdint.h>
#include "Adafruit_BMP3XX.h"

namespace bps_spi
{
    extern Adafruit_BMP3XX bps;

    static constexpr uint8_t SCK = 32;
    static constexpr uint8_t SDO = 31;
    static constexpr uint8_t SDI = 30;
    static constexpr uint8_t CS = 29;

    extern float p0;
    extern float p;
    extern float alt_r;
    extern float temp;

    bool init (void);
    void read (void);
    float convert(float hpa, float hpa0);
}