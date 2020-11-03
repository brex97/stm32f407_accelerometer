#include <stm32f4xx.h> // common stuff
#include <stm32f4xx_gpio.h> // gpio control
#include <stm32f4xx_rcc.h> // reset and clocking
#include "main.h"

extern int nacin;

int main(void)
{
volatile uint16_t data_y, data_x, data_z;
gpio_init();
spi_init();

SPI_setReg(0x20, 0x77);

while(1){
	data_y = SPI_getReg(0xAB);
	data_y = data_y << 8;
	data_y = data_y | SPI_getReg(0xAA);
	
	data_x = SPI_getReg(0xA9);
	data_x = data_x << 8;
	data_x = data_x | SPI_getReg(0xA8);
	
	data_z = SPI_getReg(0xAD);
	data_z = data_z << 8;
	data_z = data_z | SPI_getReg(0xAC);
	
	if (49000 < data_x && data_x < 65000 ) 
		gpio_led_state(LED4_GREEN_ID, 1);
	else
		gpio_led_state(LED4_GREEN_ID, 0);
	
	if (0 < data_x && data_x < 17000 ) 
		gpio_led_state(LED5_RED_ID, 1);
	else
		gpio_led_state(LED5_RED_ID, 0);
	
	if (49000 < data_y && data_y < 65000 ) 
		gpio_led_state(LED6_BLUE_ID, 1);
	else
		gpio_led_state(LED6_BLUE_ID, 0);
	
	if (0 < data_y && data_y < 17000 ) 
		gpio_led_state(LED3_ORANGE_ID, 1);
	else
		gpio_led_state(LED3_ORANGE_ID, 0);
}
}