

/*
 * lcd.h
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Brandon.Belcher
 *      Description: Header file given by Capt Branchflower to
 *      implement a LCD driver.
 */

#ifndef LCD_H_
#define LCD_H_

void initSPI();

void LCDinit();

void LCDclear();

void cursorToLineTwo();

void cursorToLineOne();

void writeChar(char asciiChar);

void writeString(char * string);

void scrollString(char * string1, char * string2);

#endif /* LCD_H_ */
