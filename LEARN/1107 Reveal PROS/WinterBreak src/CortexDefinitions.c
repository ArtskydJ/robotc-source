/*
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

#include "main.h"
#include "CortexDefinitions.h"

/* Starting Location Codes */
// 0: red haning
// 1: blue hanging
// 2: red middle
// 3: blue middle
// 4: default

// red = 0
// blue = 1
// hanging = 0,
// middle = 2


char startingLocation = 4;

bool hasAutonomousRun = false;

/* Default Driver Codes */
// 0: default driver layout
// 1: Josh
// 2: Claire
char defaultDriver = 0;


Gyro gyro;