#pragma config(Sensor, dgtl1,  redmiddle,      sensorDigitalIn)
#pragma config(Sensor, dgtl2,  bluemiddle,     sensorDigitalIn)
#pragma config(Sensor, dgtl3,  redhang,        sensorDigitalIn)
#pragma config(Sensor, dgtl4,  bluehang,       sensorDigitalIn)
#pragma config(Motor,  port1,           armMotor,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftfront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftmidfront,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftmidback,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftback,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightfront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightmidfront, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightmidback,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightback,     tmotorVex393_MC29, openLoop, reversed)

#include "VEXCompetitionIncludes.c"

task autonomous()
{
	if (SensorBoolean[redmiddle]) // jumper port is plugged in
	{	// Autonomous code below to run if in the Middle Zone, red alliance

		motor[armMotor] = 127;
		wait1Msec(100);

		motor[leftfront] = 127;
		motor[leftmidfront] = 127;
		motor[leftmidback] = 127;
		motor[leftback] =127;
		motor[rightfront] =127;
		motor[rightmidfront] = 127;
		motor[rightmidback] = 127;
		motor[rightback] = 127;
	}
	else if (SensorBoolean[bluemiddle])
	{	// Autonomous code below to run if in the Middle Zone, blue alliance
		motor[leftfront] = 127;
		motor[leftmidfront] = 127;
		motor[leftmidback] = 127;
		motor[leftback] =127;
		motor[rightfront] =127;
		motor[rightmidfront] = 127;
		motor[rightmidback] = 127;
		motor[rightback] = 127;
	}
	else if (SensorBoolean[redhang])
	{	// Autonomous code below to run if in the Hanging Zone, red alliance
		motor[leftfront] = 127;
		motor[leftmidfront] = 127;
		motor[leftmidback] = 127;
		motor[leftback] =127;
		motor[rightfront] =127;
		motor[rightmidfront] = 127;
		motor[rightmidback] = 127;
		motor[rightback] = 127;
	}
	else if (SensorBoolean[bluehang])
	{	// Autonomous code below to run if in the Hanging Zone, blue alliance
		motor[leftfront] = 127;
		motor[leftmidfront] = 127;
		motor[leftmidback] = 127;
		motor[leftback] = 127;
		motor[rightfront] = 127;
		motor[rightmidfront] = 127;
		motor[rightmidback] = 127;
		motor[rightback] = 127;
	}
}
