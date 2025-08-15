// Adafruit BMP388

#include "bps.h"

SPIClass *theSPI = &SPI;

Adafruit_BMP3XX bps;

void bps_init()
{
    Serial.begin(115200);
    while (!Serial) {} // Wait for USB serial on Teensy

    // Init BMP388 over SPI
    if (!bps.begin_SPI(BPS_CS, BPS_SCK, BPS_SDO, BPS_SDA, 4e6))
    {
        Serial.println("BMP388 not found, check wiring!");
        while (1) {}
    }

	// Configure oversampling / filtering
	bps.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
	bps.setPressureOversampling(BMP3_OVERSAMPLING_8X);
	bps.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
	bps.setOutputDataRate(BMP3_ODR_50_HZ);

	Serial.println("BMP388 initialized!");
}

void bps_read(void)
{
	{
		if (!bps.performReading())
		Serial.printf("BPS reading failed");
		return;
	}
	bps.performReading();
	Serial.printf("Temp: %.2f, Pres: %.2f",
	bps.temperature, bps.pressure);
	delay(5); // ms
}
