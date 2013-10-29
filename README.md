LCD
===
Library for working with the LCD in the black box via MSP430. Functionality performed through main.c.

General Notes
________________________________________________________________________________________________________________________
Contains the main.c, LCD.c, and lcd.h
________________________________________________________________________________________________________________________
Functions
________________________________________________________________________________________________________________________
void initSPI();
	-Initializes the SPI for the chip

void LCDinit();
	-Initializes the LCD screen

void LCDclear();
	-Clears the LCD screen

void cursorToLineTwo();
	-Positions the cursor on the bottom line of the LCD

void cursorToLineOne();
	-Positions the cursor on the top line of the LCD

void writeChar(char asciiChar);
	-Writes a character to the LCD

void writeString(char * string);
	-Writes a string to the LCD

void scrollString(char * string1, char * string2);
	-Scrolls the string across the screen