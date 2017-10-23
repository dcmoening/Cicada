/*
 * I2C.c
 *
 * Created: 10/1/2017 1:50:18 PM
 *  Author: daniel
 */ 
 #include <I2C.h>



void configure_i2c_master(void)
{
	/* Initialize config structure and software module. */
	struct i2c_master_config config_i2c_master;
	i2c_master_get_config_defaults(&config_i2c_master);
	/* Change buffer timeout to something longer. */
	config_i2c_master.buffer_timeout = 10000;
	/* Initialize and enable device with config. */
	i2c_master_init(&i2c_master_instance, SERCOM5, &config_i2c_master);
	i2c_master_enable(&i2c_master_instance);
}
//u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt
uint8_t I2C_Read(uint8_t addr, uint8_t startRegister, uint8_t *data, uint8_t cnt)
{
	uint8_t retVAl = 0;
	uint8_t timeout;
	struct i2c_master_packet readPacket = {
		.address     = addr,
		.data_length = cnt,
		.data        = data,
		.ten_bit_address = false,
		.high_speed      = false,
		.hs_master_code  = 0x0,
	};

	while (i2c_master_read_packet_wait(&i2c_master_instance, &readPacket) !=
	STATUS_OK) {
		/* Increment timeout counter and check if timed out. */
		if (timeout++ == TIMEOUT) {
			retVAl = -1;
		}
	}
	return retVAl;
}

//u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt
uint8_t I2C_Write(uint8_t addr, uint8_t startRegister, uint8_t *data, uint8_t cnt)
{
	uint8_t retVAl = 0;
	uint8_t timeout;
	struct i2c_master_packet writePacket = {
		.address     = addr,
		.data_length = cnt,
		.data        = data,
		.ten_bit_address = false,
		.high_speed      = false,
		.hs_master_code  = 0x0,
	};

	while (i2c_master_write_packet_wait(&i2c_master_instance, &writePacket) !=
	STATUS_OK) {
		/* Increment timeout counter and check if timed out. */
		if (timeout++ == TIMEOUT) {
			retVAl = -1;
		}
	}
}

void getI2CDataFromSlave(struct i2c_master_packet mypacket)
{
	uint16_t timeout = 0;

	while (i2c_master_write_packet_wait(&i2c_master_instance, &mypacket) !=
	STATUS_OK) {
		/* Increment timeout counter and check if timed out. */
		if (timeout++ == TIMEOUT) {
			break;
		}
	}
	/* Read from slave until success. */
	mypacket.data = read_buffer;
	while (i2c_master_read_packet_wait(&i2c_master_instance, &mypacket) !=
	STATUS_OK) {
		/* Increment timeout counter and check if timed out. */
		if (timeout++ == TIMEOUT) {
			break;
		}
	}
}

 void initI2CStruct(void)
 {
	/* Init i2c packet. */	  
	packet.address = SLAVE_ADDRESS;
	packet.data_length = DATA_LENGTH;
	packet.data = write_buffer;
	packet.ten_bit_address = false;
	packet.high_speed = false;
	packet.hs_master_code = 0x0;
 }
 