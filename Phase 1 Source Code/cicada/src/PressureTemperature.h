/*
 * PressureTemperature.h
 *
 * Created: 12/3/2018 5:26:59 PM
 *  Author: daniel
 */ 


#ifndef PRESSURETEMPERATURE_H_
#define PRESSURETEMPERATURE_H_

#include <asf.h>
#include <bmp280.h>
#include "delay.h"
#include "I2C.h"

struct bmp280_dev bmp;

void InitBMP280(void);
void ConfigureBMP280(void);
void BMP_Delay_MS(uint32_t delay);
uint8_t BMP_280_Read(uint8_t addr, uint8_t startRegister, uint8_t *data, uint8_t cnt);
uint8_t BMP_280_Write(uint8_t addr, uint8_t startRegister, uint8_t *data, uint8_t cnt);
void BMP280_ReadCompPresTemp(double *compTemperatre, double *compPressure);
#endif /* PRESSURETEMPERATURE_H_ */