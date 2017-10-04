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
 }
 
 void initI2CPacket(void)
 {
   configure_i2c_master();
   
   packet.address = SLAVE_ADDRESS;
   packet.data_length = DATA_LENGTH;
   packet.data = write_buffer;
   packet.ten_bit_address = false;
   packet.high_speed = false;
   packet.hs_master_code = 0x0;
 }