/*
 * I2C.h
 *
 * Created: 10/1/2017 1:59:51 PM
 *  Author: daniel
 */ 



#ifndef I2C_H_
#define I2C_H_


#include <asf.h>
#include <stdio.h>

#define DATA_LENGTH 1

#define SLAVE_ADDRESS 0x76

#define TIMEOUT 1000

struct i2c_master_module i2c_master_instance;
struct i2c_master_packet packet;

static uint8_t read_buffer[DATA_LENGTH];

//struct i2c_master_packet {
	//address = SLAVE_ADDRESS;
	//data_length = DATA_LENGTH;
	//data = write_buffer;
	//ten_bit_address = false;
	//high_speed = false;
	//hs_master_code = 0x0;
//};

void configure_i2c_master(void);
void getI2CDataFromSlave(struct i2c_master_packet mypacket); 
void initI2CStruct(void);
void initI2CPacket(void);
uint8_t I2C_Write(uint8_t addr, uint8_t startRegister, uint8_t *data, uint8_t cnt);
uint8_t I2C_Read(uint8_t addr, uint8_t startRegister, uint8_t *data, uint8_t cnt);

#endif /* I2C_H_ */