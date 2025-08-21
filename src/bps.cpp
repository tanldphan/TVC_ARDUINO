// Adafruit BMP388

#include "bps.h"

Adafruit_BMP3XX bps;

float P_START = 0.0f;

bool bps_init()
{
    // Init BMP388 over SPI
      if (!bps.begin_SPI(BPS_CS, BPS_SCK, BPS_SDO, BPS_SDA, 4000000))
	{
        Serial.println("BPS not found, check wiring!");
        return false;
    }

	// Configure oversampling / filtering
	bps.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
	bps.setPressureOversampling(BMP3_OVERSAMPLING_8X);
	bps.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_15);
	bps.setOutputDataRate(BMP3_ODR_50_HZ);

	for (int i = 0; i < 10; i++)
	{
    	bps.performReading();
    	delay(50);   // let sensor settle
	}
	P_START = bps.pressure;  // take stable baseline

	Serial.println("BPS initialized!");
	return true;
}

void bps_read(void)
{
	if (!bps.performReading())
	{
		Serial.printf("BPS reading failed");
		return;
	}
	float R_al = 44330.0f * (1.0f - powf(bps.pressure/P_START, 0.1903f));
	Serial.printf("Temp: %.2f | Pres: %.2f | R_al: %.2f | ", bps.temperature, bps.pressure, R_al);
}
