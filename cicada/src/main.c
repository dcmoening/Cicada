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

	system_init();
	system_clock_init();
	arch_ioport_init();
	initIO();

	/************************************************************************/
	/* Create timer to toggle Pin 13 LED                                                                      */
	/************************************************************************/
	Timer_id = xTimerCreate("Timer",1000, pdTRUE,0,mrBlinky);
	xTimerStart(Timer_id, 0);
	vTaskStartScheduler();
	//while(1);
}
