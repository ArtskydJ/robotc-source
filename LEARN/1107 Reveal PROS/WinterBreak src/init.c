/*
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

#include "main.h"
#include "CortexDefinitions.h"
#include "buttons.h"

void initializeIO() {
	setTeamName("7702");
}


void initialize()
{
	lcdInit(uart1);
	lcdSetBacklight(uart1, true);
	lcdSetText(uart1, 1, " Steel Eagle II ");
	lcdSetText(uart1, 2, "loading PROS");
	// If recovering from lost connection, be sure IMEs have properly been shut down
	imeShutdown();
	delay(300);
	imeInitializeAll();
	imeReset(eLEFT_IME);
	gyro = gyroInit(aGYROSCOPE, 200);
	imeReset(eRIGHT_IME);
	imeReset(eLIFT_IME);
	initButtons();
	lcdSetText(uart1, 2, "PROS loaded");
	if (!isEnabled()) // Run the rest of the initialize sequence if not trying to boot directly into driver mode
	{
		delay(750);

		lcdClear(uart1);
		/* Bootup Animation */
		lcdPrint(uart1, 1, "M:%1.2fV/E:%1.2fV", (double)powerLevelMain() / 1000, (double)analogRead(aPWR_EXPNDR_STATUS) / 280);
		lcdSetText(uart1, 2, "       MA      ");
		delay(75); // 900
		if (powerLevelMain() < LOW_BAT_THRESHOLD) lcdSetBacklight(uart1, false);
		delay(75); // 975
		lcdPrint(uart1, 1, "M:%1.2fV/E:%1.2fV", (double)powerLevelMain() / 1000, (double)analogRead(aPWR_EXPNDR_STATUS) / 280);
		lcdSetText(uart1, 2, "      MACH     ");
		delay(75); // 1050
		if (powerLevelMain() < LOW_BAT_THRESHOLD) lcdSetBacklight(uart1, true);
		delay(75); // 1125
		lcdPrint(uart1, 1, "M:%1.2fV/E:%1.2fV", (double)powerLevelMain() / 1000, (double)analogRead(aPWR_EXPNDR_STATUS) / 280);
		lcdSetText(uart1, 2, "    MACHIN    ");
		delay(75); // 1200
		if (powerLevelMain() < LOW_BAT_THRESHOLD) lcdSetBacklight(uart1, false);
		delay(75); // 1275
		lcdPrint(uart1, 1, "M:%1.2fV/E:%1.2fV", (double)powerLevelMain() / 1000, (double)analogRead(aPWR_EXPNDR_STATUS) / 280);
		lcdSetText(uart1, 2, "   MACHINAD   ");
		delay(75); // 1350
		if (powerLevelMain() < LOW_BAT_THRESHOLD) lcdSetBacklight(uart1, true);
		delay(75); // 1425
		lcdPrint(uart1, 1, "M:%1.2fV/E:%1.2fV", (double)powerLevelMain() / 1000, (double)analogRead(aPWR_EXPNDR_STATUS) / 280);
		lcdSetText(uart1, 2, "  MACHINADOR  ");
		delay(75); // 1500
		if (powerLevelMain() < LOW_BAT_THRESHOLD) lcdSetBacklight(uart1, false);
		delay(75); // 1575
		lcdPrint(uart1, 1, "M:%1.2fV/E:%1.2fV", (double)powerLevelMain() / 1000, (double)analogRead(aPWR_EXPNDR_STATUS) / 280);
		lcdSetText(uart1, 2, "");
		delay(75); // 1650
		lcdSetText(uart1, 2, "   MACHINADOR  ");
		if (powerLevelMain() < LOW_BAT_THRESHOLD) lcdSetBacklight(uart1, true);
		delay(75); // 1725

		lcdClear(uart1);
		long startTime;
		/* DEFAULT DRIVER SELECTION */
		lcdSetText(uart1, 1, "Select Driver:");
		lcdSetText(uart1, 2, "Josh Claire Def");
		delay(10);
		for (startTime = millis(); millis() < startTime + LCD_TIMEOUT;)
		{
			if (buttonIsNewPress(LCD_LEFT))	{
				defaultDriver = 1; // Josh's layout
				startTime -= LCD_TIMEOUT;
			}
			else if (buttonIsNewPress(LCD_CENT)) {
				defaultDriver = 2; // Claire's layout
				startTime -= LCD_TIMEOUT;
			}
			else if (buttonIsNewPress(LCD_RIGHT)) {
				defaultDriver = 0; // Default layout
				startTime -= LCD_TIMEOUT;
			}
			delay(50);
		}
		lcdSetText(uart1, 1, "Default Driver:");
		switch (defaultDriver)
		{
		case 1:
			lcdSetText(uart1, 2, "      Josh     ");
			break;
		case 2:
			lcdSetText(uart1, 2, "     Claire     ");
			break;
		default:
			lcdSetText(uart1, 2, " None (default) ");
			break;
		}
		delay(1000);

		if (!hasAutonomousRun && digitalRead(dAUTON_DISABLE) == LOW && isOnline()) 
		{
			/* ALLIANCE SELECTION */
			lcdSetText(uart1, 1, "    Alliance?   ");
			lcdSetText(uart1, 2, "Red         Blue");
			delay(10);
			startTime = millis();
			for (startTime = millis(); millis() < startTime + LCD_TIMEOUT;)
			{
				if (buttonIsNewPress(LCD_LEFT))	{
					startingLocation = 0;
					startTime -= LCD_TIMEOUT;
				}
				else if (buttonIsNewPress(LCD_RIGHT)) {
					startingLocation = 1;
					startTime -= LCD_TIMEOUT;
				}
				delay(40);
			}
			lcdSetText(uart1, 1, "    Alliance:   ");
			switch (startingLocation)
			{
			case 0:
				lcdSetText(uart1, 2, "       Red      ");
				break;
			case 1:
				lcdSetText(uart1, 2, "     Blue       ");
				break;
			default:
				lcdSetText(uart1, 2, "None Selected");
				break;
			}
			delay(1000);

			/* TILE SELECTION */
			if (startingLocation != 4) // only select tile if alliance color has been selected
			{
				lcdSetText(uart1, 1, "     Tile?      ");
				lcdSetText(uart1, 2, "Middle   Hanging");
				delay(10);
				for (startTime = millis(); millis() < startTime + LCD_TIMEOUT;)
				{
					if (buttonIsNewPress(LCD_LEFT)) {
						startingLocation += 2;
						startTime -= LCD_TIMEOUT;
					}
					else if (buttonIsNewPress(LCD_RIGHT)) {
						startingLocation += 0;
						startTime -= LCD_TIMEOUT;
					}
					delay(40);
				}
			}
			lcdSetText(uart1, 1, "StartingLocation");
			switch (startingLocation)
			{
			case 0:
				lcdSetText(uart1, 2, "  Red  Hanging  ");
				break;
			case 1:
				lcdSetText(uart1, 2, "  Blue Hanging  ");
				break;
			case 2:
				lcdSetText(uart1, 2, "   Red Middle   ");
				break;
			case 3:
				lcdSetText(uart1, 2, "  Blue  Middle  ");
				break;
			default:
				lcdSetText(uart1, 2, "Unknown");
				break;
			}
			delay(1000);

			/* Final Display */
			if (!isEnabled()) {
				lcdClear(uart1);
				lcdSetText(uart1, 1, "Disabled");
				switch (startingLocation)
				{
				case 0:
					switch (defaultDriver)
					{
					case 1:
						lcdSetText(uart1, 2, "RedHang    Josh");
						break;
					case 2:
						lcdSetText(uart1, 2, "RedHang   Claire");
						break;
					default:
						lcdSetText(uart1, 2, "RedHang  Default");
						break;
					}
					break;
				case 1:
					switch (defaultDriver)
					{
					case 1:
						lcdSetText(uart1, 2, "BluHang    Josh");
						break;
					case 2:
						lcdSetText(uart1, 2, "BluHang   Claire");
						break;
					default:
						lcdSetText(uart1, 2, "BluHang  Default");
						break;
					}
					break;
				case 2:
					switch (defaultDriver)
					{
					case 1:
						lcdSetText(uart1, 2, "RedMid      Josh");
						break;
					case 2:
						lcdSetText(uart1, 2, "RedMid    Claire");
						break;
					default:
						lcdSetText(uart1, 2, "RedMid   Default");
						break;
					}
					break;
				case 3:
					switch (defaultDriver)
					{
					case 1:
						lcdSetText(uart1, 2, "BluMid      Josh");
						break;
					case 2:
						lcdSetText(uart1, 2, "BluMid    Claire");
						break;
					default:
						lcdSetText(uart1, 2, "BluMid   Default");
						break;
					}
					break;
				default:
					switch (defaultDriver)
					{
					case 1:
						lcdSetText(uart1, 2, "default     Josh");
						break;
					case 2:
						lcdSetText(uart1, 2, "default   Claire");
						break;
					default:
						lcdSetText(uart1, 2, "default  Default");
						break;
					}
					break;
				}
			}
		}
	}

	if (digitalRead(dSENSOR_READOUT) == LOW)
	{
		/* SENSOR DEBUG READOUT */
#include "lift.h"
#include "chassis.h"
		lcdSetText(uart1, 1, "Sensor Readout");
		lcdSetText(uart1, 2, "Enabled");
		int mode = 0;
		bool quit = false;
		int leftIME, rightIME;
		while (!quit)
		{
			if (buttonIsNewPress(LCD_LEFT)) mode--;
			if (buttonIsNewPress(LCD_CENT))
			{
				imeReset(eLEFT_IME);
				imeReset(eRIGHT_IME);
				gyroReset(gyro);
			}
			if (buttonIsNewPress(LCD_RIGHT)) mode++;


			if (mode < 0) mode = 4;
			if (mode > 4) mode = 0;

			switch (mode)
			{
			case 0:
				lcdSetText(uart1, 1, "  Lift Sensors  ");
				lcdPrint(uart1, 2, "IME%d ; Lim%d", liftGetHeight(), digitalRead(dLIFT_LIMIT));
				break;
			case 1:
				imeGet(eLEFT_IME, &leftIME);
				imeGet(eRIGHT_IME, &rightIME);
				lcdPrint(uart1, 1, "IME Left: %d", leftIME);
				lcdPrint(uart1, 2, "Right: %d", -rightIME);
				break;
			case 2:
				lcdPrint(uart1, 1, "Gyro: %d", gyroGet(gyro));
				lcdPrint(uart1, 2, "TopLim:%d", digitalRead(dLIFT_MAX));
				break;
			case 3:
				lcdPrint(uart1, 1, "LineLe: %d,%d", analogRead(aLINE_LEFT), lineSensorDetected(aLINE_LEFT));
				lcdPrint(uart1, 2, "LineRi: %d,%d", analogRead(aLINE_RIGHT), lineSensorDetected(aLINE_RIGHT));
				break;
			case 4:
				lcdPrint(uart1, 1, "LineCe: %d,%d", analogRead(aLINE_CENT), lineSensorDetected(aLINE_CENT));
				lcdPrint(uart1, 2, "LineRe: %d,%d", analogRead(aLINE_REAR), lineSensorDetected(aLINE_REAR));
				break;
			}

			if (digitalRead(dSENSOR_READOUT) == HIGH) quit = true;

			delay(50);
		}
		if (quit) while (!buttonIsNewPress(BUMP_SWITCH)) delay(15);
	}
}