/*
* Copyright (c) 2013-2014 Elliot Berman for VRC Team 7702 (Steel Eagle II).
* All rights reserved.
* Portions of this solution are produced by Purdue University ACM SIG BOTS.
* Their copyright notice is on API.h and main.h (both have been unmodified)
*/

#include "main.h"
#include "CortexDefinitions.h"
#include "lift.h"
#include "chassis.h"
#include <math.h>

#include "intake.h"

void chassisSetTank(int left, int right)
{
	/*double scale = 1;
	if (abs(left) >= abs(right) && abs(left) > MAX_MOTOR_SPEED)
	{
		//requested abs(left) value is larger than 127, and larger than or equal to the abs(right) requested value
		scale = MAX_MOTOR_SPEED / (double)abs(left);
	}

	else if (abs(right) > abs(left) && abs(right) > MAX_MOTOR_SPEED)
		// Requested abs(right) value is larger than 127
		scale = MAX_MOTOR_SPEED / (double)abs(right);

	if (liftGetHeight() > LIFT_SCALE_THRESHOLD)
		scale *= 1 / (liftGetHeight() / LIFT_SCALE_THRESHOLD);
	//lcdPrint(uart1, 2, "%d %d %f", left, right, scale);

	left *= scale;
	right *= scale;*/


	motorSet(DRIVE_FRONT_LEFT, left);
	motorSet(DRIVE_REAR_LEFT, left);
	motorSet(DRIVE_FRONT_RIGHT, -right);
	motorSet(DRIVE_REAR_RIGHT, right);
}

void chassisSetIndv(int frontLeft, int rearLeft, int frontRight, int rearRight)
{
	char values[4] = { frontLeft, frontRight, rearLeft, rearRight };
	char max = MAX_MOTOR_SPEED;
	for (int i = 0; i <= 3; i++)
	{
		if (abs(values[i]) > max) max = abs(values[i]);
	}
	double scale = abs(max) / MAX_MOTOR_SPEED;

	if (liftGetHeight() > LIFT_SCALE_THRESHOLD)
		scale *= 1 / (liftGetHeight() / LIFT_SCALE_THRESHOLD);

	frontLeft *= scale;
	frontRight *= scale;
	rearLeft *= scale;
	rearRight *= scale;

	motorSet(DRIVE_FRONT_LEFT, frontLeft);
	motorSet(DRIVE_REAR_LEFT, rearLeft);
	motorSet(DRIVE_FRONT_RIGHT, -frontRight);
	motorSet(DRIVE_REAR_RIGHT, rearRight);
}

void chassisSetMecanumArcade(char y_axis, char x_axis, char strafe_axis)
{
	if (abs(x_axis) < JOY_DEADBAND) x_axis = 0;
	if (abs(y_axis) < JOY_DEADBAND) y_axis = 0;
	if (abs(strafe_axis) < JOY_STRAFE_DEADBAND) strafe_axis = 0;


	char frontLeft = (y_axis + x_axis) + strafe_axis;
	char rearLeft = (y_axis + x_axis) - strafe_axis;
	char frontRight = (y_axis - x_axis) - strafe_axis;
	char rearRight = (y_axis - x_axis) + strafe_axis;

	chassisSetIndv(frontLeft, rearLeft, frontRight, rearRight);
}

void chassisSetMecanumTank(char left_axis, char right_axis, char strafe_axis)
{
	if (abs(left_axis) < JOY_DEADBAND) left_axis = 0;
	if (abs(right_axis) < JOY_DEADBAND) right_axis = 0;

	if (abs(strafe_axis) < JOY_STRAFE_DEADBAND || abs(left_axis) > JOY_DEADBAND || abs(right_axis) > JOY_DEADBAND)
		// Weird results happen when all axises are influencing direction of robot
		strafe_axis = 0;
	if (abs(strafe_axis) > abs(left_axis)) {
		left_axis = 0;
		right_axis = 0;
	}
	else strafe_axis = 0;


	int frontLeft = left_axis + strafe_axis;
	int rearLeft = left_axis - strafe_axis;
	int frontRight = right_axis - strafe_axis;
	int rearRight = right_axis + strafe_axis;

	chassisSetIndv(frontLeft, rearLeft, frontRight, rearRight);
}

void chassisSetMecanum(double angle, double speed, char rotation)
{
	// rightDiag applies to FRONT RIGHT and REAR LEFT
	// leftDiag applies to FRONT LEFT and REAR RIGHT
	char rightDiag = 127 * cos(angle + (PI / 4));
	char leftDiag = 127 * cos(angle - (PI / 4));

	char frontRight = rightDiag + rotation;
	char rearRight = leftDiag + rotation;
	char frontLeft = leftDiag - rotation;
	char rearLeft = rightDiag - rotation;

	char max = 127;
	if (frontLeft > 127) max = frontLeft;
	if (rearLeft > max) max = rearLeft;
	if (frontRight > max) max = frontRight;
	if (rearRight > max) max = rearRight;

	double speedScale = 127 / max; // adjust all motor outputs to properly scaled values
	frontLeft *= speedScale;
	rearLeft *= speedScale;
	frontRight *= speedScale;
	rearRight *= speedScale;

	motorSet(DRIVE_FRONT_LEFT, frontLeft);
	motorSet(DRIVE_REAR_LEFT, rearLeft);
	motorSet(DRIVE_FRONT_RIGHT, -frontRight);
	motorSet(DRIVE_REAR_RIGHT, rearRight);
}

int leftError,
leftPrevError = 0,
leftIntegral,
leftDerivative;

int rightError,
rightPrevError = 0,
rightIntegral,
rightDerivative;

int gyroError,
gyroPrevError = 0,
gyroIntegral,
gyroDerivative;

void chassisResetPID()
{
	leftError = 0;
	leftPrevError = 0;
	leftIntegral = 0;
	leftDerivative = 0;

	rightError = 0;
	rightPrevError = 0;
	rightIntegral = 0;
	rightDerivative = 0;

	gyroError = 0;
	gyroPrevError = 0;
	gyroIntegral = 0;
	gyroDerivative = 0;
}

void chassisResetIME()
{
	imeReset(eRIGHT_IME);
	imeReset(eLEFT_IME);
}
bool chassisGoByTicks(long leftTicks, long rightTicks)
{
	int leftCurrent, rightCurrent;

	imeGet(eLEFT_IME, &leftCurrent);
	imeGet(eRIGHT_IME, &rightCurrent);

	rightCurrent = -rightCurrent;

	leftError = leftTicks - leftCurrent;
	rightError = rightTicks - rightCurrent;

	leftIntegral += leftError;
	rightIntegral += rightError;

	if (abs(leftError) <= (leftTicks + eLEFT_AT) || abs(leftIntegral) <= eLEFT_Mi) leftIntegral = 0;
	if (abs(rightError) <= (rightTicks + eRIGHT_AT) || abs(rightIntegral) <= eRIGHT_Mi) rightIntegral = 0;

	leftDerivative = leftError - leftPrevError;
	rightDerivative = rightError - rightPrevError;

	int left = (eLEFT_Kp * leftError) + (eLEFT_Ki * leftIntegral) + (eLEFT_Kd * leftDerivative);
	int right = (eRIGHT_Kp * rightError) + (eRIGHT_Ki * rightIntegral) + (eRIGHT_Kd * rightDerivative);

	chassisSetTank(left, right);
	lcdPrint(uart1, 2, "%d %d", leftError, rightError);

	leftPrevError = leftError;
	rightPrevError = rightError;

	if ((abs(leftError) <= eLEFT_AT) && (abs(rightError) <= eRIGHT_AT)) return true;
	else return false;
}

bool chassisGoByInches(double leftInches, double rightInches)
{
	return chassisGoByTicks((long)(leftInches * eLEFT_TICKS_IN), (long)(rightInches * eRIGHT_TICKS_IN));
}

bool chassisIsOnGoal(long ticks)
{
	int current;
	imeGet(eLEFT_IME, &current);

	current = ticks - current;
	lcdPrint(uart1, 2, "%d", current);
	if ((abs(current) <= eLEFT_AT)) return true;
	else return false;
}

bool chassisGoByGyro(long degrees, Gyro gyro)
{
	int gyroCurrent = gyroGet(gyro);

	gyroError = degrees - gyroCurrent;

	gyroIntegral += gyroError;
	if (abs(gyroError) <= (degrees + GYRO_AT) || abs(gyroIntegral) <= GYRO_Mi) gyroIntegral = 0;

	gyroDerivative = gyroError - gyroPrevError;

	int gyroOut = (GYRO_Kp * gyroError) + (GYRO_Ki * gyroIntegral) + (GYRO_Kd * gyroDerivative);

	lcdPrint(uart1, 2, "%d, %d", gyroError, gyroCurrent);

	if (abs(gyroOut) < 35) gyroOut = (abs(gyroOut) / gyroOut) * 35;
	if (abs(gyroError) <= GYRO_AT) gyroOut = 0;

	chassisSetTank(-gyroOut, gyroOut);

	gyroPrevError = gyroError;

	if (abs(gyroError) <= GYRO_AT) return true;
	else return false;
}

bool lineSensorDetected(int sensor)
{
	if (analogRead(sensor) < LINE_THRESHOLD) return true;
	else return false;
}

bool chassisGoToLine(int sensor, char speed)
{
	if (lineSensorDetected(sensor)) {
		chassisSetTank(0, 0);
		return true;
	}
	else {
		chassisSetTank(speed, speed);
		return false;
	}
}

// Don't use this function
bool chassisAlignToLine(chassisAlignments alignment, chassisTurnDirections direction)
{
	switch (alignment)
	{
	case parallel:
		if (chassisGoToLine(aLINE_CENT, 50)) // reports true of robot is on line, OK to turn
		{
			if (lineSensorDetected(aLINE_REAR)) //Line detected
			{
				chassisSetTank(0, 0);
				return true;
			}
			else //Line not detected, turn in direction given
			{
				chassisSetTank(direction * 50, -direction * 50);
				return false;
			}
		}
		else return false;
		break;
	case perpindicular:
		if (chassisGoToLine(aLINE_CENT, -50)) // reports true of robot is on line, OK to turn
		{
			if (lineSensorDetected(aLINE_LEFT))
			{
				switch (lineSensorDetected(aLINE_RIGHT))
				{
				case true: // line detected on left and right
					chassisSetTank(0, 0);
					return true;
					break;
				case false: // Line detected on left but not right
					chassisSetTank(0, (-direction * 50));
					return false;
					break;
				}
			}
			else
			{
				switch (lineSensorDetected(aLINE_RIGHT))
				{
				case true:// line detected on right, but not left
					chassisSetTank((direction * 50), 0);
					return false;
					break;
				case false: // no line detected on either left or right
					chassisSetTank((direction * 50), (-direction * 50));
					return false;
					break;
				}
			}
		}
		else return false;
		break;
	default:
		return false;
	}
}

#include "buttons.h"
void testAutonomous()
{
	/* SKILLS RUN  V2 */
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
	// Backing over the bump
	chassisSetTank(-127, -127);
	while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
	chassisSetTank(0, 0); intakeSet(0); delay(1000);
	while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
	chassisResetIME(); gyroReset(gyro); delay(300); // Reset ALL the things!
	// Robot has been turned around by Claire
	while (!chassisGoByTicks(570, 570)) {
		liftGoToHeight(ground); delay(15);
	}
	while (!chassisGoToLine(aLINE_LEFT, 70)) {
		liftGoToHeight(ground); delay(15);
	}
	while (!chassisGoToLine(aLINE_LEFT, -30)); {
		liftGoToHeight(ground); delay(15);
	}
	// Robot has hit cross line underneath barrier
	while (!chassisGoByGyro(57, gyro)) delay(15);
	chassisResetIME();  delay(15);
	chassisSetTank(60, 60);
	delay(500);
	while (!chassisGoToLine(aLINE_CENT, 70)) {
		liftGoToHeight(stash); delay(15);
	}
	delay(25);
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
	chassisSetTank(30, 30);
	delay(100);
	chassisSetTank(0, 0);
	// Outaking
	intakeSet(out);
	for (int i = 0; i <= 1750; i++) {
		liftGoToHeight(stash); delay(1);
	}
	intakeSet(0);

	// Going back to tile
	while (!chassisGoByGyro(20, gyro)) delay(15);
	chassisSetTank(-50, -50);
	delay(500);
	while (!liftGoToHeight(ground)) delay(15);
	chassisSetTank(-127, -127);
	delay(750);
	while (!liftGoToHeight(rollover)) delay(15);
	liftSet(0);
	while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
	liftSet(0);
	chassisSetTank(0, 0); delay(750);
	while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
	// Picking up three on bump
	/*intakeSet(in);
	chassisResetIME(); gyroReset(gyro); delay(10);
	while (!chassisGoByTicks(500, 500)) {
		liftGoToHeight(rollover); delay(15);
	}
	delay(500);
	while (!chassisGoByTicks(0, 0)) delay(15);
	*/
	// Backing over bump
	/*
	while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
	liftSet(-10);
	chassisSetTank(0, 0); intakeSet(0); delay(1000);
	while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
	chassisResetIME();  gyroReset(gyro); delay(300); // Reset ALL the things!	
	while (!chassisGoByInches(17.5, 17.5)) {
		liftGoToHeight(ground); delay(15);
	}
	intakeSet(in);
	chassisSetMecanum((PI * 88 / 180), 70, 0);
	while (!chassisIsOnGoal(-1750)) {
		liftGoToHeight(ground); delay(15);
	}
	chassisSetTank(127, 127);
	delay(350);
	chassisSetTank(0, 0);
	chassisSetTank(-127, -127);
	delay(200);
	chassisSetTank(127, 127);
	delay(175);
	chassisResetIME(); 
	while (!chassisGoByGyro(-70, gyro)) delay(15);
	chassisResetIME();
	chassisSetTank(-127, -127);

	while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
	chassisSetTank(0, 0); delay(1000);
	while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
	chassisResetIME();  gyroReset(gyro); delay(333); // Reset ALL the things!
	chassisSetTank(-127, -127); delay(500);
	*/
	//while (!buttonIsNewPress(BUMP_SWITCH)) delay(10);
	chassisResetIME();  gyroReset(gyro); delay(333); // Reset ALL the things!
	// Robot has been turned around by Claire
	while (!chassisGoByTicks(570, 570)) {
		liftGoToHeight(ground); delay(15);
	}
	intakeSet(0);
	while (!chassisGoToLine(aLINE_LEFT, 70)) delay(15);
	while (!chassisGoToLine(aLINE_LEFT, -30)); delay(15);
	// Robot has hit cross line underneath barrier
	while (!chassisGoByGyro(57, gyro)) delay(15);
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
	// Outaking
	intakeSet(out);
	for (int i = 0; i <= 1750; i++) {
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
	while (!chassisGoByGyro(88, gyro)) delay(15);
	chassisSetTank(127, 125); delay(500);
	while (!chassisGoToLine(aLINE_CENT, 127)) {
		liftGoToHeight(bridge); delay(15);
	}
	while (!chassisGoByGyro(45, gyro)) {
		liftGoToHeight(bridge); delay(15);
	}
	while (!chassisGoByGyro(90, gyro)) {
		liftGoToHeight(bridge); delay(15);
	}
	chassisResetIME(); 
	while (!chassisGoByInches(38, 38)) {
		liftGoToHeight(bridge); delay(15);
	}
	while (!chassisGoByGyro(45, gyro)) {
		liftGoToHeight(bridge); delay(15);
	}
	while (!chassisGoByGyro(90, gyro)) {
		liftGoToHeight(bridge); delay(15);
	}
	chassisResetIME();
	while (!chassisGoByInches(38, 38)) {
		liftGoToHeight(bridge); delay(15);
	}
	while (!chassisGoByGyro(45, gyro)) {
		liftGoToHeight(bridge); delay(15);
	}
	while (!chassisGoByGyro(90, gyro)) {
		liftGoToHeight(bridge); delay(15);
	}
}