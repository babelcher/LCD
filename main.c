#include <msp430.h> 
#include "lcd.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD; //stops watchdog timer
	
	char * bestClassMessage = "ECE382 is my favorite class!";
	char *myPersonalMessage = "Not so sure right now though.";
    initSPI();
    LCDinit();
    LCDclear();
    scrollString(bestClassMessage, myPersonalMessage);

	return 0;
}
