#ifndef INTAKE_H_
#define INTAKE_H_

/**
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

typedef enum
{
	in = 127,
	out = -127
} mIntakeDirections;

/**
* Sets intake to speed
*/
void intakeSet(char speed);

#endif