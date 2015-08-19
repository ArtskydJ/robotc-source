/*
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

#include "main.h"
#include "CortexDefinitions.h"
#include "lift.h"



int liftGetHeight()
{
	int value;
	imeGet(eLIFT_IME, &value);
	if (digitalRead(dLIFT_LIMIT) == pressed)
		imeReset(eLIFT_IME);
	imeGet(eLIFT_IME, &value);
	return value;
}


void liftSet(int value)
{
	if (value > 80) value = 80;
	if (value < -80) value = -80;

	motorSet(LIFT_LEFT, -value);
	motorSet(LIFT_LEFT_2, value);
	motorSet(LIFT_RIGHT, value);
	motorSet(LIFT_RIGHT_2, -value);
}

int liftError,
	liftPrevError = 0,
	liftIntegral,
	liftDerivative;

void liftResetPID()
{
	liftError = 0;
	liftPrevError = 0;
	liftIntegral = 0;
	liftDerivative = 0;
}

bool liftGoToHeight(int height)
{
	if (height == ground)
	{
		if (digitalRead(dLIFT_LIMIT) == pressed){
			liftSet(-7);
			return true;
		}
		else {
			liftSet(-50);
			return false;
		}
	}
	if (height == stash)
	{
		if (digitalRead(dLIFT_MAX) == pressed) {
			liftSet(10);
			return true;
		}
		else {
			liftSet(110);
			return false;
		}
	}
	else
	{
		liftError = height - liftGetHeight();

		liftIntegral += liftError;

		if (abs(liftError) <= (height + eLIFT_AT) || abs(liftIntegral) <= eLIFT_Mi) liftIntegral = 0;

		liftDerivative = liftError - liftPrevError;

		int liftOut = (eLIFT_Kp * liftError) + (eLIFT_Ki * liftIntegral) + (eLIFT_Kd * liftDerivative);
		
		if (liftOut > 127) liftOut = 127;
		if (liftOut < -127) liftOut = -127;
		liftSet(liftOut);
		//lcdPrint(uart1, 2, "%d, %d", liftOut, motorGet(LIFT_LEFT));

		liftPrevError = liftError;

		if (abs(liftError) <= eLIFT_AT) return true;
		else return false;
	}
}