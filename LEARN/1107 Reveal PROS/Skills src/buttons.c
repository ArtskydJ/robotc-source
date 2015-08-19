/*
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

#include "main.h"
#include "CortexDefinitions.h"
#include "buttons.h"

bool buttonPressed[27];

void initButtons()
{
	for (int i = 0; i <= 27; i++)
		buttonPressed[i] = false;
}

bool buttonIsNewPress(buttons button)
{
	bool currentButton;

	// Determine how to get the current button value (from what function) and where it is, then get it
	if (button < LCD_LEFT) // button is a joystick button
	{
		unsigned char joystick;
		unsigned char buttonGroup;
		unsigned char buttonLocation;

		buttons newButton;
		if (button <= 11) { // button is on joystick 1 
			joystick = 1;
			newButton = button;
		} else {
			joystick = 2;
			newButton = button - 12;
		}

		switch (newButton)
		{
		case 0:
			buttonGroup = 5;
			buttonLocation = JOY_DOWN;
			break;
		case 1:
			buttonGroup = 5;
			buttonLocation = JOY_UP;
			break;
		case 2:
			buttonGroup = 6;
			buttonLocation = JOY_DOWN;
			break;
		case 3:
			buttonGroup = 6;
			buttonLocation = JOY_UP;
			break;
		case 4:
			buttonGroup = 7;
			buttonLocation = JOY_UP;
			break;
		case 5:
			buttonGroup = 7;
			buttonLocation = JOY_LEFT;
			break;
		case 6:
			buttonGroup = 7;
			buttonLocation = JOY_RIGHT;
			break;
		case 7:
			buttonGroup = 7;
			buttonLocation = JOY_DOWN;
			break;
		case 8:
			buttonGroup = 8;
			buttonLocation = JOY_UP;
			break;
		case 9:
			buttonGroup = 8;
			buttonLocation = JOY_LEFT;
			break;
		case 10:
			buttonGroup = 8;
			buttonLocation = JOY_RIGHT;
			break;
		case 11:
			buttonGroup = 8;
			buttonLocation = JOY_DOWN;
			break;
		default:
			break;
		}
		currentButton = joystickGetDigital(joystick, buttonGroup, buttonLocation);
	}
	else if (button == 27)
	{
		if (digitalRead(dBUMP_SWITCH) == LOW) currentButton = true;
		else currentButton = false;
	}
	else // button is on LCD
	{
		if (button == LCD_LEFT)
		{
			if (lcdReadButtons(uart1) == LCD_BTN_LEFT) currentButton = true;
			else currentButton = false;
		}
		if (button == LCD_CENT)
		{
			if (lcdReadButtons(uart1) == LCD_BTN_CENTER) currentButton = true;
			else currentButton = false;
		}
		if (button == LCD_RIGHT)
		{
			if (lcdReadButtons(uart1) == LCD_BTN_RIGHT) currentButton = true;
			else currentButton = false;
		}
	}

	if (!currentButton)
	{
		buttonPressed[button] = false;
	}

	if (currentButton && !buttonPressed[button])
	{
		buttonPressed[button] = true;
		return true;
	}
	else return false; // button is not pressed or was already detected
}