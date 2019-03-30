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
#include <asf.h>
#include "PressureTemperature.h"

//////////////////////////////////////////////////////////////////////////
//Main Function Where The Magic Happens!
//////////////////////////////////////////////////////////////////////////
int main (void)
{	
	double temperature = 0;
	double pressure = 0;

	double debug_temp = 0;
	double debug_pres = 0;

	static double final_temp = 0;
	static double final_pres = 0;

	//Initialize I2C settings
	configure_i2c_master();

	//Initialize delay settings
	delay_init();

	//Init BMP280 Data structure
	InitBMP280();

	//Configure settings for BMP280
	ConfigureBMP280();
	
	//Get Temperature and Pressure
	BMP280_ReadCompPresTemp(&temperature, &pressure);

	debug_temp = temperature;
	debug_pres = pressure;	

	BMP280_ReadCompPresTemp(&temperature, &pressure);

	debug_temp = temperature;
	debug_pres = pressure;
	
	BMP280_ReadCompPresTemp(&temperature, &pressure);

	debug_temp = temperature;
	debug_pres = pressure;
	
	BMP280_ReadCompPresTemp(&temperature, &pressure);

	debug_temp = temperature;
	debug_pres = pressure;		

	return 0;
}
