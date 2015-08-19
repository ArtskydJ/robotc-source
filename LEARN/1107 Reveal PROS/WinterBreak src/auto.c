/*
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

#include "main.h"
#include "CortexDefinitions.h"
#include "chassis.h"
#include "intake.h"
#include "lift.h"
#include "buttons.h"

#include <math.h>

void autonomous()
{
	lcdSetText(uart1, 1, " Running  Auton ");
	switch (startingLocation)
	{
	case 0: // Red Hanging
		lcdSetText(uart1, 2, "Red Hang");
		/* RED HANGING */
		chassisSetTank(90, 80);
		delay(250);
		chassisSetTank(-80, -80);
		delay(150);
		intakeSet(in);
		chassisSetTank(0, 0);
		delay(200);

		while (!chassisGoByTicks(615, 615)) {
			if (!isAutonomous()) operatorControl();
			liftGoToHeight(ground); delay(15);
		}
		while (!chassisGoByTicks(400, 400)) {
			if (!isAutonomous()) operatorControl();
			delay(15);
		}
		while (!chassisGoByGyro(90, gyro)){
			if (!isAutonomous()) operatorControl();
			delay(15);
		}
		chassisSetTank(127, 127);
		delay(200);
		while (!chassisGoToLine(aLINE_CENT, 70)) {
			if (!isAutonomous()) operatorControl();
			delay(15);
		}
		while (!chassisGoByGyro(210, gyro)) delay(15);
		chassisResetIME(); delay(10);
		while (!chassisGoByTicks(400, 400)) {
			if (!isAutonomous()) operatorControl();
			delay(15);
		}
		while (!liftGoToHeight(rollover)) {
			if (!isAutonomous()) operatorControl();
			delay(15);
		}
		liftSet(0); chassisSetTank(0, 0);
		break;

	case 1: // Blue Hanging
		lcdSetText(uart1, 2, "Blue Hang");
		chassisSetTank(90, 80);
		delay(250);
		chassisSetTank(-80, -80);
		delay(150);
		intakeSet(in);
		chassisSetTank(0, 0);
		delay(200);

		while (!chassisGoByTicks(615, 615)) {
			liftGoToHeight(ground); delay(15);
		}
		while (!chassisGoByTicks(500, 500)) delay(15);
		while (!chassisGoByGyro(-90, gyro))delay(15);
		chassisSetTank(127, 127);
		delay(200);
		while (!chassisGoToLine(aLINE_CENT, 70)) delay(15);
		while (!chassisGoByGyro(-210, gyro)) delay(15);
		chassisResetIME(); delay(10);
		while (!chassisGoByTicks(400, 400)) delay(15);
		while (!liftGoToHeight(rollover)) delay(15);
		intakeSet(out);
		liftSet(0); chassisSetTank(0, 0);
		delay(1000);
		intakeSet(0);
		break;

	case 2: // Red Middle
		lcdSetText(uart1, 2, "Red Middle");
		chassisSetTank(90, 80);
		delay(250);
		chassisSetTank(-80, -80);
		delay(150);
		intakeSet(in);
		chassisSetTank(0, 0);
		delay(200);
		chassisResetIME();  gyroReset(gyro); delay(333); // Reset ALL the things!
		// Robot has been turned around by Claire
		while (!chassisGoByTicks(570, 570)) {
			liftGoToHeight(ground); delay(15);
		}
		intakeSet(0);
		while (!chassisGoToLine(aLINE_RIGHT, 70)) delay(15);
		while (!chassisGoToLine(aLINE_RIGHT, -30)) delay(15);
		// Robot has hit cross line underneath barrier
		while (!chassisGoByGyro(-62, gyro)) delay(15);
		chassisResetIME();  delay(15);
		chassisSetTank(80, 80);
		delay(500);
		while (!chassisGoToLine(aLINE_CENT, 70)) {
			liftGoToHeight(stash); delay(15);
		}
		while (!chassisGoToLine(aLINE_CENT, -30)) {
			liftGoToHeight(stash); delay(15);
		}
		liftGoToHeight(stash);
		// Aligning to line
		chassisSetTank(-70, 70);
		while (!lineSensorDetected(aLINE_REAR)) {
			liftGoToHeight(stash); delay(10);
		}
		chassisSetTank(0, 0);
		chassisSetIndv(-70, 0, 70, 0);
		while (!lineSensorDetected(aLINE_CENT)) {
			liftGoToHeight(stash); delay(10);
		}
		chassisSetTank(0, 0);
		chassisSetIndv(0, 70, 0, -70);
		while (!lineSensorDetected(aLINE_REAR)) {
			liftGoToHeight(stash); delay(10);
		}
		chassisSetTank(0, 0);
		chassisSetTank(60, 60);
		delay(100);
		// Outaking
		intakeSet(out);
		for (int i = 0; i <= 500; i++) {
			liftGoToHeight(stash); delay(1);
		}
		intakeSet(0);

		// Going back to tile
		while (!chassisGoByGyro(-20, gyro)) delay(15);
		chassisSetTank(-50, -50);
		delay(500);
		while (!liftGoToHeight(ground)) delay(15);
		chassisSetTank(-127, -127); delay(1000);
		while (!chassisGoToLine(aLINE_CENT, -127)) delay(15);
		chassisSetIndv(0, 50, 0, -50);
		while (!lineSensorDetected(aLINE_REAR)) delay(15);
		chassisSetTank(-127, -127);
		delay(100);
		while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
		chassisSetTank(0, 0); intakeSet(0); delay(500);
		while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
		chassisResetIME();  gyroReset(gyro); delay(333); // Reset ALL the things!
		// KNOCK OFF BIG BALLZ
		while (!liftGoToHeight(bridge)) delay(15);
		liftSet(0);
		while (!chassisGoByTicks(700, 700)) {
			liftGoToHeight(bridge); delay(15);
		}
		while (!chassisGoByTicks(500, 500)) {
			liftGoToHeight(bridge); delay(15);
		}
		intakeSet(out);
		while (!chassisGoByGyro(-88, gyro)) delay(15);
		chassisSetTank(127, 125); delay(500);
		while (!chassisGoToLine(aLINE_CENT, 127)) {
			liftGoToHeight(bridge); delay(15);
		}
		while (!chassisGoByGyro(-45, gyro)) {
			liftGoToHeight(bridge); delay(15);
		}
		while (!chassisGoByGyro(-90, gyro)) {
			liftGoToHeight(bridge); delay(15);
		}
		break;

	case 3: // Blue Middle
		lcdSetText(uart1, 2, "Blue Middle");
		gyroReset(gyro);
		imeReset(eLEFT_IME); imeReset(eRIGHT_IME);
		chassisSetTank(90, 80);
		delay(250);
		chassisSetTank(-80, -80);
		delay(150);
		intakeSet(in);
		chassisSetTank(0, 0);
		delay(200);
		chassisResetIME();  gyroReset(gyro); delay(333); // Reset ALL the things!
		// Robot has been turned around by Claire
		while (!chassisGoByTicks(570, 570)) {
			liftGoToHeight(ground); delay(15);
		}
		intakeSet(0);
		while (!chassisGoToLine(aLINE_LEFT, 70)) delay(15);
		while (!chassisGoToLine(aLINE_LEFT, -30)); delay(15);
		// Robot has hit cross line underneath barrier
		while (!chassisGoByGyro(62, gyro)) delay(15);
		chassisResetIME();  delay(15);
		chassisSetTank(80, 80);
		delay(500);
		while (!chassisGoToLine(aLINE_CENT, 70)) {
			liftGoToHeight(stash); delay(15);
		}
		while (!chassisGoToLine(aLINE_CENT, -30)) {
			liftGoToHeight(stash); delay(15);
		}
		liftGoToHeight(stash);
		// Aligning to line
		chassisSetTank(70, -70);
		while (!lineSensorDetected(aLINE_REAR)) {
			liftGoToHeight(stash); delay(10);
		}
		chassisSetTank(0, 0);
		chassisSetIndv(70, 0, -70, 0);
		while (!lineSensorDetected(aLINE_CENT)) {
			liftGoToHeight(stash); delay(10);
		}
		chassisSetTank(0, 0);
		chassisSetIndv(0, -70, 0, 70);
		while (!lineSensorDetected(aLINE_REAR)) {
			liftGoToHeight(stash); delay(10);
		}
		chassisSetTank(0, 0);
		chassisSetTank(30, 30);
		delay(200);
		// Outaking
		intakeSet(out);
		for (int i = 0; i <= 500; i++) {
			liftGoToHeight(stash); delay(1);
		}
		intakeSet(0);

		// Going back to tile
		while (!chassisGoByGyro(20, gyro)) delay(15);
		chassisSetTank(-50, -50);
		delay(500);
		while (!liftGoToHeight(ground)) delay(15);
		chassisSetTank(-127, -127); delay(1000);
		while (!chassisGoToLine(aLINE_CENT, -127)) delay(15);
		chassisSetIndv(0, 50, 0, -50);
		while (!lineSensorDetected(aLINE_REAR)) delay(15);
		chassisSetTank(-127, -127);
		while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
		chassisSetTank(0, 0); intakeSet(0); delay(500);
		while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
		chassisResetIME();  gyroReset(gyro); delay(333); // Reset ALL the things!
		// KNOCK OFF BIG BALLZ
		while (!liftGoToHeight(bridge)) delay(15);
		liftSet(0);
		while (!chassisGoByTicks(700, 700)) {
			liftGoToHeight(bridge); delay(15);
		}
		while (!chassisGoByTicks(600, 600)) {
			liftGoToHeight(bridge); delay(15);
		}
		intakeSet(in);
		while (!chassisGoByGyro(88, gyro)) delay(15);
		chassisSetTank(127, 125); delay(500);
		while (!chassisGoToLine(aLINE_CENT, 127)) {
			liftGoToHeight(bridge); delay(15);
		}
		while (!chassisGoByGyro(30, gyro)) {
			liftGoToHeight(bridge); delay(15);
		}
		while (!chassisGoByGyro(90, gyro)) {
			liftGoToHeight(bridge); delay(15);
		}
		break;
	default:
		break;
	}
	lcdSetText(uart1, 2, "Auto complete");
}