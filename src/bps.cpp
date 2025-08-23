// Adafruit BMP388

#include "bps.h"

namespace BPS
{
	Adafruit_BMP3XX bps;
	float p_start = 0.0f;
	bool init()
	{
		if (!bps.begin_SPI(BPS_CS, BPS_SCK, BPS_SDO, BPS_SDA, 4000000)) return false;

		bps.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
		bps.setPressureOversampling(BMP3_OVERSAMPLING_8X);
		bps.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_15);
		bps.setOutputDataRate(BMP3_ODR_50_HZ);

		for (int i = 0; i < 10; i++)
		{
			bps.performReading();
			delay(50);
		}
		p_start = bps.pressure;
		return true;
	}

	void read()
	{
		bps.performReading();
		float r_alt = 44330.0f * (1.0f - powf(bps.pressure/p_start, 0.1903f));
		Serial.printf("Temp: %.2f | Pres: %.2f | r_alt: %.2f | ", bps.temperature, bps.pressure, r_alt);
	}
}