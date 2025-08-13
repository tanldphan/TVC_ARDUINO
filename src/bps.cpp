// Adafruit BMP388

#include "bps.h"

SPIClass *theSPI = &SPI;

Adafruit_BMP3XX bmp;

void bps_init()
{
    Serial.begin(115200);
    while (!Serial) {} // Wait for USB serial on Teensy

    // Init BMP388 over SPI
    if (!bmp.begin_SPI(BPS_CS, BPS_SCL, BPS_SDO, BPS_SDA, 4000000))
    {
        Serial.println("BMP388 not found, check wiring!");
        while (1) {}
    }

	// Configure oversampling / filtering
	bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
	bmp.setPressureOversampling(BMP3_OVERSAMPLING_8X);
	bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
	bmp.setOutputDataRate(BMP3_ODR_50_HZ);

	Serial.println("BMP388 initialized!");
}

void bps_read(void)
{
	bmp.performReading();
	Serial.printf("Temp: %.2f, Pres: %.2f",
	bmp.temperature, bmp.pressure);
}
