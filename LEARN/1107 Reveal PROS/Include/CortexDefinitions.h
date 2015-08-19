/**
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

#ifndef CORTEXDEFINITIONS_H_
#define CORTEXDEFINITIONS_H_

/*-- MOTOR DEFINITIONS --*/

#define DRIVE_FRONT_RIGHT	1 // Inverted
#define DRIVE_FRONT_LEFT	2
#define	SCORING_MECH_RIGHT	3
#define LIFT_LEFT			4 // Inverted
#define LIFT_LEFT_2			5
#define LIFT_RIGHT			6
#define LIFT_RIGHT_2		7
#define SCORING_MECH_LEFT	8 // Inverted
#define DRIVE_REAR_LEFT	    9 
#define DRIVE_REAR_RIGHT	10

/*-- SENSOR DEFINTIONS --*/
// ANALOG
#define aGYROSCOPE			1
#define aLINE_LEFT			2
#define aLINE_CENT			3
#define aLINE_RIGHT			4
#define aLINE_REAR			5
#define aPWR_EXPNDR_STATUS	6

// DIGITAL
#define dAUTON_DISABLE		1
#define dLIFT_MAX			2
#define dSENSOR_READOUT		3
#define dBUMP_SWITCH		11
#define dLIFT_LIMIT			12

// I2C
#define eRIGHT_IME			0
#define eLEFT_IME			1 // Inverted
#define eLIFT_IME			2 // Inverted


/*-- TYPEDEF ENUMS --*/
typedef enum
{
	on = HIGH,
	off = LOW
} bClampPositions;

typedef enum
{
	pressed = LOW,
	depressed = HIGH
} bLimitPositions;

/*-- MISC DEFINITIONS -- */
#define MAX_MOTOR_SPEED  127
#define JOY_DEADBAND	 40
#define LOW_BAT_THRESHOLD	7300
#define LCD_TIMEOUT		5000

/* -- COMPETITIONS DEFINITIONS -- */
extern char startingLocation;
extern bool hasAutonomousRun;
extern char defaultDriver;

extern Gyro gyro;
#endif // !CORTEXDEFINITIONS_H_