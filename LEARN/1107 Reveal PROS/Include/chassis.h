/**
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

#ifndef CHASSIS_H_
#define CHASSIS_H_

#define JOY_STRAFE_DEADBAND		30
#define LIFT_SCALE_THRESHOLD	700

// Left Encoder PID Constants
#define eLEFT_Kp				.5
#define eLEFT_Ki				0.01
#define eLEFT_Kd				0.001
#define eLEFT_Mi				40
#define eLEFT_AT				30
#define eLEFT_TICKS_IN			31.22

// Right Encoder PID Constants
#define eRIGHT_Kp				.5
#define eRIGHT_Ki				0.01
#define eRIGHT_Kd				0.001
#define eRIGHT_Mi				40
#define eRIGHT_AT				30
#define eRIGHT_TICKS_IN			30.29

// Gyro PID Constants
#define GYRO_Kp					3.5
#define GYRO_Ki					.001
#define GYRO_Kd					0
#define GYRO_Mi					20
#define GYRO_AT					1

#define LINE_THRESHOLD			2650 // Less than is on line
#define PI 3.1415926535897932384626433


typedef enum
{
	forward = 1,
	backward = -1
} chassisDirections;

typedef enum
{
	perpindicular = 1,
	parallel = -1
} chassisAlignments;

typedef enum
{
	left = 1,
	right = -1
} chassisTurnDirections;

/**
* Set the left/right motor of the chassis. Self scaling.
*/
void chassisSetTank(int left, int right);

/**
* Set the individual motors of the chassis. Self scaling.
*/
void chassisSetIndv(int frontLeft, int rearLeft, int frontRight, int rearRight);

/**
* Set chassis based off of joystick values. Faster than chassisSetMecanumAuto
* Utilizes the arcade style control
* Self scaling joystick axis
*/
void chassisSetMecanumArcade(char y_axis, char x_axis, char rot_axis);

/**
* Set chassis based off of joystick values. Faster than chassisSetMecanumAuto
* Utilizes the tank style control
* Self scaling joystick axis
*/
void chassisSetMecanumTank(char left_axis, char right_axis, char rot_axis);

/**
* Input heading, speed, and rotation then outputs correct PWM values
* Intended for non-"continuous" use, like autonomous applications or where joystick values are not inputed/converted
* Param rotation: positive values are to left, negative values to right
*/
void chassisSetMecanum(double angle, double speed, char rotation);





/**
* Resets all chassis PID Controllers
*/
void chassisResetPID();


void chassisResetIME();

/**
* Uses a PID Controller to go to tick value. 
* Make sure IMEs have been reset, if necessary.
*/
bool chassisGoByTicks(long leftTicks, long rightTicks);

bool chassisIsOnGoal(long ticks);

/**
* Uses a PID Controller to go to tick value.
* Make sure IMEs have been reset, if necessary.
*/
bool chassisGoByInches(double leftInches, double rightInches);

/**
* Uses a PID Controller to go to degree value. 
* Degrees in base unit (1 degree : 1 degree)
* Make sure gyro has been reset, if necessary.
*/
bool chassisGoByGyro(long degrees, Gyro gyro);

/**
* Returns true/false if a line is detected for a line follower
*/
bool lineSensorDetected(int sensor);

/**
* Chassis goes forward until line sensor has detected a line.
*/
bool chassisGoToLine(int sensor, char speed);

/**
* Chassis turns in direction until aligned to parameter given
* !THIS FUNCTION IS IN BETA AND NEEDS TO BE TESTED!
*/
bool chassisAlignToLine(chassisAlignments alignment, chassisTurnDirections direction);

void testAutonomous();
#endif