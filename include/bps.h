// Adafruit BMP388

#pragma once

#include "stdint.h"
#include "Adafruit_BMP3XX.h"

static constexpr uint8_t BPS_SCK = 11;
static constexpr uint8_t BPS_SDO = 12; // MISO
static constexpr uint8_t BPS_SDA = 13; // MOSI
static constexpr uint8_t BPS_CS = 14;

extern Adafruit_BMP3XX bps;

void bps_init(void);
void bps_read(void);