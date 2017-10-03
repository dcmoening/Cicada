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

/* Timeout counter. */
uint16_t timeout = 0;

 void mrBlinky(xTimerHandle pxtimer)
 {
	ioport_toggle_pin_level(17);		
 }

void initIO()
{
	ioport_enable_pin(17);
	ioport_set_pin_dir(17, IOPORT_DIR_OUTPUT);

}

int main (void)
{
	xTimerHandle Timer_id;
	uint16_t timeout = 0;

	system_init();
	system_clock_init();
	arch_ioport_init();
	initIO();

	/* Configure device and enable. */
	configure_i2c_master();

	/*Create and initialize configuration structure*/
	struct i2c_master_config config_i2c_master;
	i2c_master_get_config_defaults(&config_i2c_master);

	/*Change settings in the configuration*/
	config_i2c_master.buffer_timeout = 10000;

	/*Initialize the module with the set configurations.*/
	i2c_master_init(&i2c_master_instance, SERCOM2, &config_i2c_master);

	/*Enable the module.*/
	i2c_master_enable(&i2c_master_instance);


	/************************************************************************/
	/* Create timer to toggle Pin 13 LED                                                                      */
	/************************************************************************/
	Timer_id = xTimerCreate("Timer",1000, pdTRUE,0,mrBlinky);
	xTimerStart(Timer_id, 0);
	vTaskStartScheduler();
	//while(1);
}
