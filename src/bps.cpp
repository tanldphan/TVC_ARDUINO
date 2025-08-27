// Adafruit BMP388

#include "bps.h"

namespace BPSmodule
{
	Adafruit_BMP3XX bps;

	bool init()
	{
		if (!bps.begin_SPI(CS, SCK, SDO, SDA, 4000000)) return false;

		bps.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
		bps.setPressureOversampling(BMP3_OVERSAMPLING_8X);
		bps.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_15);
		bps.setOutputDataRate(BMP3_ODR_50_HZ);

		for (int i = 0; i < 10; i++) // scrap
		{
			bps.performReading();
			delay(250);
		}
		p0 = bps.pressure;
		return true;
	}

	void read()
	{
		bps.performReading();
		p = bps.pressure;
		temp = bps.temperature;
		alt_r = convert(p, p0);
		Serial.printf("Temp: %.2f | Pres: %.2f | alt_r: %.2f | ", temp, p, alt_r);
	}

	float convert(float pressure_mmhg, float pressure0_mmhg)
	{
		return 44330.0f * (1.0f - powf(pressure_mmhg/ pressure0_mmhg, 0.1903f));
	}
}