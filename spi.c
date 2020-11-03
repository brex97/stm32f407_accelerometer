#include <spi.h>
void spi_init(void) {
	SPI_InitTypeDef SPI_InitStruct;
	
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_High;
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStruct.SPI_CRCPolynomial = 0;
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
	SPI_Init(SPI1, &SPI_InitStruct);
	
	//GPIO_SetBits(GPIOE, GPIO_Pin_3);
	SPI_Cmd(SPI1, ENABLE);
	//GPIO_ResetBits(GPIOE, GPIO_Pin_3);
}

uint8_t SPI_Write(uint8_t data){

	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET);
	SPI_I2S_SendData(SPI1, data);
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET);
	return SPI_I2S_ReceiveData(SPI1);
}

void SPI_setReg(uint8_t address, uint8_t data) {
	GPIO_ResetBits(GPIOE, GPIO_Pin_3);
	SPI_Write(address);
	SPI_Write(data);
	GPIO_SetBits(GPIOE, GPIO_Pin_3);
}

uint8_t SPI_getReg(uint8_t address) {
	uint8_t data=0;
	GPIO_ResetBits(GPIOE, GPIO_Pin_3);
	SPI_Write(address);
	data = SPI_Write(0x00);
	GPIO_SetBits(GPIOE, GPIO_Pin_3);
	return data;
}