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

#define DATA_LENGTH 10
<<<<<<< HEAD
#define SLAVE_ADDRESS 0x76
=======
#define SLAVE_ADDRESS 0x12
>>>>>>> b8941d34e5c6e8f03dc5e2e2f76475a92e83f7a6
#define TIMEOUT 1000

struct i2c_master_module i2c_master_instance;
struct i2c_master_packet packet;
static uint8_t write_buffer[DATA_LENGTH] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
};
static uint8_t read_buffer[DATA_LENGTH];
<<<<<<< HEAD
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
=======

struct i2c_master_module i2c_master_instance;

struct i2c_master_packet packet;

void initI2CPacket(void);
>>>>>>> b8941d34e5c6e8f03dc5e2e2f76475a92e83f7a6

void configure_i2c_master(void);
#endif /* I2C_H_ */