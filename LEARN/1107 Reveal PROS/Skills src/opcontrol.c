/*
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

#include "main.h"
#include "CortexDefinitions.h"
#include "chassis.h"
#include "lift.h"
#include "intake.h"
#include "buttons.h"

void joshControl(vLiftHeights *goal, int *mode)
{
	// LCD DISPLAY
	lcdSetText(uart1, 1, " Steel Eagle II ");
	if (*mode >= 4) *mode = 0;
	switch (*mode)
	{
	case 0:
		lcdSetText(uart1, 2, " TeleOp - Josh ");
		break;
	case 1:
		lcdSetText(uart1, 2, "Powered by: PROS");
		break;
	case 2:
		lcdSetText(uart1, 2, "Machinador | IN");
		break;
	case 3:
		lcdPrint(uart1, 2, "M:%1.2fV|E:%1.2fV", (double)powerLevelMain() / 1000, (double)analogRead(aPWR_EXPNDR_STATUS) / 280);
		break;
	}


	// CHASSIS CONTROL
	chassisSetMecanumTank(joystickGetAnalog(1, 3), joystickGetAnalog(1, 2), joystickGetAnalog(1, 4));

	// LIFT CONTROL
	if (buttonIsNewPress(JOY1_6D) && *goal != ground) {
		if (*goal == stash)
		{ // Automatically go backward if coming from stash to ground (to prevent lift/scoring mechanism from hitting stash)
			chassisSetTank(-127, -127);
			liftSet(-50);
			delay(500);
		}
		liftResetPID();
		*goal = ground;
	}
	if (buttonIsNewPress(JOY1_6U) && *goal != stash) {
		liftResetPID();
		*goal = stash;
	}
	if (buttonIsNewPress(JOY1_8R) && *goal != bridge) {
		liftResetPID();
		*goal = bridge;
	}
	if (buttonIsNewPress(JOY1_8D) && *goal != rollover) {
		liftResetPID();
		*goal = rollover;
	}
	liftGoToHeight(*goal);

	// INTAKE CONTROL
	if (joystickGetDigital(1, 5, JOY_UP))			intakeSet(out);
	else if (joystickGetDigital(1, 5, JOY_DOWN))	intakeSet(in);
	else											intakeSet(0);
}


void ClaireControl(vLiftHeights *goal, int *mode)
{
	// LCD DISPLAY
	lcdSetText(uart1, 1, " Steel Eagle II ");
	if (*mode >= 4) *mode = 0;
	switch (*mode)
	{
	case 0:
		lcdSetText(uart1, 2, "TeleOp - Claire");
		break;
	case 1:
		lcdSetText(uart1, 2, "Powered by: PROS");
		break;
	case 2:
		lcdSetText(uart1, 2, "Machinador | IN");
		break;
	case 3:
		lcdPrint(uart1, 2, "M:%1.2f|E:%1.2fV", (double)powerLevelMain() / 1000, (double)analogRead(aPWR_EXPNDR_STATUS) / 280);
		break;
	}



	// CHASSIS CONTROL
	chassisSetMecanumTank(joystickGetAnalog(1, 3), joystickGetAnalog(1, 2), joystickGetAnalog(1, 4));

	// LIFT CONTROL
	if (buttonIsNewPress(JOY1_6D) && *goal != ground) {
		liftResetPID();
		*goal = ground;
	}
	if (buttonIsNewPress(JOY1_6U) && *goal != stash) {
		liftResetPID();
		*goal = stash;
	}
	if (buttonIsNewPress(JOY1_8R) && *goal != bridge) {
		liftResetPID();
		*goal = bridge;
	}
	if (buttonIsNewPress(JOY1_8D) && *goal != rollover) {
		liftResetPID();
		*goal = rollover;
	}
	liftGoToHeight(*goal);

	//lcdPrint(uart1, 2, "%d, %d", (eLIFT_Kp * (*goal - liftGetHeight())), motorGet(LIFT_LEFT));

	// INTAKE CONTROL
	if (joystickGetDigital(1, 5, JOY_UP)) intakeSet(in);
	else if (joystickGetDigital(1, 5, JOY_DOWN)) intakeSet(out);
	else intakeSet(0);
}

void defaultControl(vLiftHeights *goal, int *mode)
{
	// LCD DISPLAY
	lcdSetText(uart1, 1, " Steel Eagle II ");
	//double liftIMESpeed;
	//imeGetVelocity(eLIFT_IME, &liftIMESpeed);
	//liftIMESpeed /= 39.2;
	//lcdPrint(uart1, 1, "%d", motorGet(LIFT_LEFT));
	if (*mode >= 4) *mode = 0;
	switch (*mode)
	{
	case 0:
		lcdSetText(uart1, 2, "TeleOp - Default");
		break;
	case 1:
		lcdSetText(uart1, 2, "Powered by: PROS");
		break;
	case 2:
		lcdSetText(uart1, 2, "Machinador | IN");
		break;
	case 3:
		lcdPrint(uart1, 2, "M:%1.2fV|E:%1.2fV", (double)powerLevelMain() / 1000, (double)analogRead(aPWR_EXPNDR_STATUS) / 280);
		break;
	}


	// CHASSIS CONTROL
	chassisSetMecanumTank(joystickGetAnalog(1, 3), joystickGetAnalog(1, 2), joystickGetAnalog(1, 4));

	// LIFT CONTROL
	if (buttonIsNewPress(JOY1_6D) && *goal != ground) {
		liftResetPID();
		*goal = ground;
	}
	if (buttonIsNewPress(JOY1_6U) && *goal != stash) {
		liftResetPID();
		*goal = stash;
	}
	if (buttonIsNewPress(JOY1_8R) && *goal != bridge) {
		liftResetPID();
		*goal = bridge;
	}
	if (buttonIsNewPress(JOY1_8D) && *goal != rollover) {
		liftResetPID();
		*goal = rollover;
	}
	liftGoToHeight(*goal);

	//lcdPrint(uart1, 2, "%d, %d", (eLIFT_Kp * (*goal - liftGetHeight())), motorGet(LIFT_LEFT));

	// INTAKE CONTROL
	if (joystickGetDigital(1, 5, JOY_UP)) intakeSet(out);
	else if (joystickGetDigital(1, 5, JOY_DOWN)) intakeSet(in);
	else intakeSet(0);
}

void operatorControl() {
	vLiftHeights goal = ground;
	unsigned long modeTime = millis();
	int mode = 0;
	chassisResetIME();
	while (true)
	{
		switch (defaultDriver){
		case 1:
			joshControl(&goal, &mode);
			break;
		case 2:
			ClaireControl(&goal, &mode);
			break;
		default:
			defaultControl(&goal, &mode);
			break;
		}

		if (millis() > modeTime + 5000) {
			modeTime = millis();
			mode++;
		}

		if (buttonIsNewPress(LCD_LEFT)){
			defaultDriver = 0;
			mode = 0;
			modeTime = millis();
		}
		else if (buttonIsNewPress(LCD_CENT)) {
			defaultDriver = 1;
			mode = 0;
			modeTime = millis();
		}
		else if (buttonIsNewPress(LCD_RIGHT)) {
			defaultDriver = 2;
			mode = 0;
			modeTime = millis();
		}
		delay(50);
	}
}