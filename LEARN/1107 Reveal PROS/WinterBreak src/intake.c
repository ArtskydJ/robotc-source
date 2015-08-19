/*
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

#include "main.h"
#include "CortexDefinitions.h"
#include "intake.h"

void intakeSet(char speed)
{
	motorSet(SCORING_MECH_LEFT, -speed);
	motorSet(SCORING_MECH_RIGHT, speed);
}