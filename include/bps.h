// Adafruit BMP388

#pragma once

#include <stdint.h>
#include "Adafruit_BMP3XX.h"

namespace BPSmodule
{
    static constexpr uint8_t SCK = 36;
    static constexpr uint8_t SDO = 35;
    static constexpr uint8_t SDA = 34;
    static constexpr uint8_t CS = 33;

    extern Adafruit_BMP3XX bps;

    bool init (void);
    void read (void);
}