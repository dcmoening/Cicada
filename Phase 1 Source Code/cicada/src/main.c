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
#include <I2C.h>
#include <BMP280 Driver/bmp280.h>
#include <stdio.h>

/* Timeout counter. */
uint16_t timeout = 0;

int main (void)
{

	uint8_t *ptr = read_buffer;
	struct bmp280_t *ptSens;
	u32 v_pressure_u32; 
	s32 v_temperature_s32;
	system_init();
	system_clock_init();
	arch_ioport_init();

	initI2CStruct();

	configure_i2c_master();
	ptSens->chip_id = 0x58;
	ptSens->dev_addr = 0X76;
	bmp280_read_pressure_temperature(v_temperature_s32,v_pressure_u32);

	///*Initialize the module with the set configurations.*/
	//i2c_master_init(&i2c_master_instance, SERCOM2, &config_i2c_master);

	///*Enable the module.*/
	//i2c_master_enable(&i2c_master_instance);



	/************************************************************************/
	/* Create timer to toggle Pin 13 LED                                                                      */
	/************************************************************************/
	//xTimerStart(Timer_id, 0);
	//vTaskStartScheduler();
	//while(1);
}
