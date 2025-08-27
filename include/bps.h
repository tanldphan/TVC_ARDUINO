// Adafruit BMP388

#pragma once

#include <stdint.h>
#include "Adafruit_BMP3XX.h"

namespace BPSmodule
{
    extern Adafruit_BMP3XX bps;

    static constexpr uint8_t SCK = 36;
    static constexpr uint8_t SDO = 35;
    static constexpr uint8_t SDA = 34;
    static constexpr uint8_t CS = 33;

    float p0;
    float p;
    float alt_r;
    float temp;

    bool init (void);
    void read (void);
    float convert(float pressure_mmhg, float pressure0_mmhg);
}