/*
 * LCD.c
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Brandon.Belcher
 */

#define RS_MASK 0x40

void LCDinit() {
	writeCommandNibble(0x03);

	writeCommandNibble(0x03);

	writeCommandNibble(0x03);

	writeCommandNibble(0x02);

	writeCommandByte(0x28);

	writeCommandByte(0x0C);

	writeCommandByte(0x01);

	writeCommandByte(0x06);

	writeCommandByte(0x01);

	writeCommandByte(0x02);

	SPI_send(0);
	delayMicro();
}

void writeCommandNibble(char commandNibble) {
	LCDCON &= ~RS_MASK;
	LCD_write_4(commandNibble);
	delayMilli();
}

void writeCommandByte(char commandByte) {
	LCDCON &= ~RS_MASK;
	LCD_write_8(commandByte);
	delayMilli();
}

void writeDataByte(char dataByte) {
	LCDCON |= RS_MASK;
	LCD_write_8(dataByte);
	delayMilli();
}

void LCD_write_8(char byteToSend) {
	unsigned char sendByte = byteToSend;

	sendByte &= 0xF0;

	sendByte = sendByte >> 4;               // rotate to the right 4 times

	LCD_write_4(sendByte);

	sendByte = byteToSend;

	sendByte &= 0x0F;

	LCD_write_4(sendByte);
}

void SPI_send(char byteToSend) {
	char readByte;

	set_SS_lo();

	UCB0TXBUF = byteToSend;

	while (!(UCB0RXIFG & IFG2)) {
		// wait until you've received a byte
	}

	readByte = UCB0RXBUF;

	set_SS_hi();
}

void initSPI(){
	UCB0CTL1 |= UCSWRST;
	UCB0CTL0 |= UCCKPH|UCMSB|UCMST|UCSYNC;
	UCB0CTL1 |= UCSSEL1;

	P1SEL |= BIT5;
	P1SEL2 |= BIT5;
	P1SEL |= BIT7;
	P1SEL2 |= BIT7;
	P1SEL |= BIT6;
	P1SEL2 |= BIT6;

	UCB0CTL1 &= UCSWRST;
}

void set_SS_hi(){
	P1OUT |= BIT0;
}

void set_SS_lo(){
	P1OUT &= BIT0;
}

//implements a delay of ~41 us
void delayMicro(){
	_delay_cycles(41);
}

//implements a delay of ~1.645 ms
void delayMilli(){
	_delay_cycles(1645);
}

void LCD_write_4(unsigned char sendByte){

}
