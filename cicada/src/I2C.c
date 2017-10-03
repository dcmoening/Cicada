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
	 i2c_master_init(&i2c_master_instance, SERCOM2, &config_i2c_master);
	 i2c_master_enable(&i2c_master_instance);	 
 }

 void getI2CDataFromSlave(i2c_master_instance masterInstance, i2c_master_packet masterPacket)
 {
	 while (i2c_master_write_packet_wait(masterInstance, masterPacket) !=
	 STATUS_OK) {
		 /* Increment timeout counter and check if timed out. */
		 if (timeout++ == TIMEOUT) {
			 break;
		 }
	 }
	 /* Read from slave until success. */
	 masterPacket.data = read_buffer;
	 while (i2c_master_read_packet_wait(&i2c_master_instance, &masterPacket) !=
	 STATUS_OK) {
		 /* Increment timeout counter and check if timed out. */
		 if (timeout++ == TIMEOUT) {
			 break;
		 }
	 }
 }