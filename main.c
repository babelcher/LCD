#include <msp430.h> 
#include "lcd.h"
#include "buttons/button.h"

/*
 *  Created on: Oct 22, 2013
 *      Author: C15Brandon.Belcher
 *      Description: Implements a driver for the LCD in the black box.
 *      It allows the user to select from 3 different messages to display
 *      scrolling across the LCD.
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD; //stops watchdog timer

	char *bestClassMessage = "ECE382 is my favorite class!";
	char *messageOne = "message 1!";
	char *messageTwo = "message 2!";
	char *messageThree = "message 3!";
	char *messageQuestion = "Message?";
	char *pressMessage = "Press123";
	char buttons[] = { BIT1, BIT2, BIT4 };

	initSPI();
	LCDinit();
	LCDclear();

	configureP1PinAsButton(BIT1 | BIT2 | BIT4);

	//poll for a button while no button has been pressed
	while (!isP1ButtonPressed(BIT1 | BIT2 | BIT4)) {
		cursorToLineOne();
		writeString(messageQuestion);
		cursorToLineTwo();
		writeString(pressMessage);
		char buttonPressed = pollP1Buttons(buttons, 3);

		//check to see if it was button 1 that was pressed
		if (buttonPressed == BIT1) {
			waitForP1ButtonRelease(BIT1);
			while (1) {
				scrollString(bestClassMessage, messageOne);
			}
		}

		//check to see if it was button 2 that was pressed
		else if (buttonPressed == BIT2) {
			waitForP1ButtonRelease(BIT2);
			while (1) {
				scrollString(bestClassMessage, messageTwo);
			}
		}

		//check to see if it was button 3 that was pressed
		else if (buttonPressed == BIT4) {
			waitForP1ButtonRelease(BIT4);
			while (1) {
				scrollString(bestClassMessage, messageThree);
			}
		}
	}

	return 0;
}
