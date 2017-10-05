/*
 * I2C.c
 *
 * Created: 10/1/2017 1:50:18 PM
 *  Author: daniel
 */ 
 #include <I2C.h>


<<<<<<< HEAD
void configure_i2c_master(void)
{
	/* Initialize config structure and software module. */
	struct i2c_master_config config_i2c_master;
	i2c_master_get_config_defaults(&config_i2c_master);
	/* Change buffer timeout to something longer. */
	config_i2c_master.buffer_timeout = 10000;
	/* Initialize and enable device with config. */
	i2c_master_init(&i2c_master_instance, SERCOM2, &config_i2c_master);
	i2c_master_enable(&i2c_master_instance);
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
=======
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
>>>>>>> b8941d34e5c6e8f03dc5e2e2f76475a92e83f7a6
 }