#ifndef SPI_H
#define SPI_H

#include <stm32f4xx.h> // common stuff
#include <stm32f4xx_gpio.h> // gpio control
#include <stm32f4xx_rcc.h> // reset anc clocking
#include <stm32f4xx_spi.h>
#include <gpio.h>

void spi_init(void);
uint8_t SPI_Write(uint8_t data);
void SPI_setReg(uint8_t address, uint8_t data);
uint8_t SPI_getReg(uint8_t address);
#endif