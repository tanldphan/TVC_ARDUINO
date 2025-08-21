// Adafruit BMP388

#pragma once

#include <stdint.h>
#include "Adafruit_BMP3XX.h"

static constexpr uint8_t BPS_SCK = 36;
static constexpr uint8_t BPS_SDO = 35;
static constexpr uint8_t BPS_SDA = 34;
static constexpr uint8_t BPS_CS = 33;

extern Adafruit_BMP3XX bps;

bool bps_init(void);
void bps_read(void);