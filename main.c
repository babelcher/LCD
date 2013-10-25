#include <msp430.h> 
#include "lcd.h"
#include "buttons/button.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD; //stops watchdog timer

	char *bestClassMessage = "ECE382 is my favorite class!";
	char *messageOne = "message 1!";
	char *messageTwo = "message 2.";
	char *messageThree = "message 3!";
	char *messageQuestion = "Message?";
	char *pressMessage = "Press123";
	char buttons[] = { BIT1, BIT2, BIT4 };

	initSPI();
	LCDinit();
	LCDclear();

	configureP1PinAsButton(BIT1 | BIT2 | BIT4);

	while (!isP1ButtonPressed(BIT1 | BIT2 | BIT4)) {
		cursorToLineOne();
		writeString(messageQuestion);
		cursorToLineTwo();
		writeString(pressMessage);
		char buttonPressed = pollP1Buttons(buttons, 3);
		if (buttonPressed == BIT1) {
			waitForP1ButtonRelease(BIT1);
			while (1) {
				scrollString(bestClassMessage, messageOne);
			}
		}
		else if (buttonPressed == BIT2) {
			waitForP1ButtonRelease(BIT2);
			while (1) {
				scrollString(bestClassMessage, messageTwo);
			}
		}
		else if (buttonPressed == BIT4) {
			waitForP1ButtonRelease(BIT4);
			while (1) {
				scrollString(bestClassMessage, messageThree);
			}
		}
	}

//    scrollString(bestClassMessage, myPersonalMessage);

	return 0;
}
