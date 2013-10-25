#include <msp430.h> 
#include "lcd.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD; //stops watchdog timer
	
	char * bestClassMessage = "ECE382 is my favorite class!";
    initSPI();
    LCDinit();
    LCDclear();
    writeString(bestClassMessage);

	return 0;
}
