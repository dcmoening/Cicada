/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

 /*
 helpful site for Segger RTT
 https://www.segger.com/products/debug-probes/j-link/tools/rtt-viewer/
 */

#include <asf.h>
#include "PressureTemperature.h"
#include "SeggerRTT/SEGGER_RTT.h"
#include "BMP280 Driver/bmp280.h"
//#include "avr/dtostrf.h"
#include <stdio.h>

char *gcvt(double number, int ndigit, char *buf);

//////////////////////////////////////////////////////////////////////////
//Main Function Where The Magic Happens!
//////////////////////////////////////////////////////////////////////////
int main (void)
{	
	int8_t result = 0;

	double temperature = 0;
	double pressure = 0;		

	//Initialize I2C settings
	configure_i2c_master();
	
	//Initialize delay settings
	delay_init();

	//Init BMP280 Data structure
	result = InitBMP280();

	if(result == BMP280_OK)
	{
		//Configure settings for BMP280
		result = ConfigureBMP280();
	}		

	char tempStr[5];
	char presStr[5]; 
	
	while(result == BMP280_OK)
	{
		//Get Temperature and Pressure
		BMP280_ReadCompPresTemp(&temperature, &pressure);
		
		//Convert temperature to Fahrenheit
		float ftemperature = temperature * 1.8f + 32;
		//dtostrf(ftemperature,3,2,tempStr);
		gcvt(ftemperature,4,tempStr);
		

		//Convert Pressure to inHg
		float fpressure = pressure * .0002953f;
		//sprintf(presStr,"%f",fpressure);
		gcvt(fpressure,4,presStr);

		SEGGER_RTT_printf(0,"Temperature is: %s F\r\nPressure is: %s inHg\r\n",tempStr,presStr);

		delay_ms(5000);
	}
	
	SEGGER_RTT_printf(0, "Error has occured!");
			

	return 0;
}

