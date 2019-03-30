# Project Description #
Cicada is the name for this project that will record temperature, barometric pressure, and GPS data in order to accurately track a hike, run, or other outdoor activity with longer battery life and a smaller form factor than a smart phone. The inspiration for this project came after trying to log a backpacking trip and my phone battery quickly depleted before the end of the trip.

This project will be conducted in three phases. The first phase will be to construct a prototype using breakout boards and connecting them together on a breadboard.   Most of the software will be developed using these breakout boards to test various tracking algorithms.  In the second phase I will be designing a printed circuit board, in Multisim, comprised of the individual components that are on the breakout boards. Finally, the objective of the third phase is to fine tune the software developed in phase one function on the PCB that was developed in phase two.  
 
# Hardware (Phase 1) #
- [Adafruit Ultimate GPS Breakout](https://www.adafruit.com/product/746?gclid=Cj0KCQjw5arMBRDzARIsAAqmJewALG1dQekojggsRzns4Ux1qxPu-yFRM9Kns_N_SPRtXcY6n1gRZxEaApyHEALw_wcB)

- [Bosch Sensortec (Breakout Board)](https://www.amazon.com/Pressure-Replace-Precision-Atmospheric-Arduino/dp/B01N5EU9VD/ref=sr_1_15?ie=UTF8&qid=1501114695&sr=8-15&keywords=barometric+pressure+breakout)

- [Adafruit Feather M0 Adalogger](https://www.adafruit.com/product/2796)

- [Segger J-Link EDU Debugger/Programmer](https://www.adafruit.com/product/1369)
- Bread Board

# Hardware (Phase 3) #
TBD
	
# Software #



- Atmel Studio 7


- [Bosch BMP280 Driver](https://github.com/BoschSensortec/BMP280_driver "Bosch BMP280 Driver")


- FreeRTOS (Configured using Atmel Studio 7)

