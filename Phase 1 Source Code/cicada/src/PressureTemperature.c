/*
 * PressureTemperature.c
 *
 * Created: 12/3/2018 5:26:03 PM
 *  Author: daniel
 */ 
 
#include "PressureTemperature.h"

void InitBMP280(void)
{	
	int8_t rslt;
		
	/* Sensor interface over I2C with primary slave address  */
	bmp.dev_id = BMP280_I2C_ADDR_PRIM;
	bmp.intf = BMP280_I2C_INTF;
	bmp.read = BMP_280_Read;
	bmp.write = BMP_280_Write;
	bmp.delay_ms = BMP_Delay_MS;

	rslt = bmp280_init(&bmp);
	
}

void BMP_Delay_MS(uint32_t delay)
{
	delay_ms(delay);
}


uint8_t BMP_280_Read(uint8_t addr, uint8_t startRegister, uint8_t *data, uint8_t cnt)
{
	uint8_t rslt;

	//send register to read from
	rslt = I2C_Write(addr, startRegister, &startRegister, 1);

	//Begin reading the information that is sent back from the device
	rslt = I2C_Read(addr,startRegister,data,cnt);

	return rslt;
}

uint8_t BMP_280_Write(uint8_t addr, uint8_t startRegister, uint8_t *data, uint8_t cnt)
{
	uint8_t rslt;
	rslt = I2C_Write(addr, startRegister, data, cnt);
	
	return rslt;
}


void ConfigureBMP280()
{
	struct bmp280_config conf;
	int8_t rslt;

	/* Always read the current settings before writing, especially when
	 * all the configuration is not modified 
	 */
	rslt = bmp280_get_config(&conf, &bmp);
	/* Check if rslt == BMP280_OK, if not, then handle accordingly */

	/* Overwrite the desired settings */
	conf.filter = BMP280_FILTER_COEFF_2;
	conf.os_pres = BMP280_OS_16X;
	conf.os_temp = BMP280_OS_4X;
	conf.odr = BMP280_ODR_1000_MS;
	

	rslt = bmp280_set_config(&conf, &bmp);
	/* Check if rslt == BMP280_OK, if not, then handle accordingly */

	rslt = bmp280_get_config(&conf, &bmp);

	/* Always set the power mode after setting the configuration */

	rslt = bmp280_set_power_mode(BMP280_NORMAL_MODE, &bmp);
	/* Check if rslt == BMP280_OK, if not, then handle accordingly */

	rslt = bmp280_get_config(&conf, &bmp);
}

void BMP280_ReadCompPresTemp(double *compTemperature, double *compPressure)
{
	struct bmp280_uncomp_data ucomp_data;
	int8_t rslt;

	uint8_t meas_dur = bmp280_compute_meas_time(&bmp);

	rslt = bmp280_get_uncomp_data(&ucomp_data, &bmp);

	int32_t temp32 = bmp280_comp_temp_32bit(ucomp_data.uncomp_temp, &bmp);
	uint32_t pres32 = bmp280_comp_pres_32bit(ucomp_data.uncomp_press, &bmp);
	uint32_t pres64 = bmp280_comp_pres_64bit(ucomp_data.uncomp_press, &bmp);
	double temp = bmp280_comp_temp_double(ucomp_data.uncomp_temp, &bmp);
	double pres = bmp280_comp_pres_double(ucomp_data.uncomp_press, &bmp);

	*compPressure = pres;
	*compTemperature = temp;
	delay_ms(meas_dur);
}