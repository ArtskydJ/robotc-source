#pragma config(Sensor, S1,     TOUCH,          sensorTouch)
#pragma config(Sensor, S2,     COMPASS,        sensorVirtualCompass)
#pragma config(Sensor, S3,     LIGHT,          sensorLightActive)
#pragma config(Sensor, S4,     ULTRA,          sensorSONAR)
#pragma config(Motor,  motorA,          nil,           tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          D_RIGHT,       tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          D_LEFT,        tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "MB_Definitions.c"
#include "MB_Declarations.c"
#include "MB_OtherFunctions.c"
#include "MB_Initialize.c"
#include "MB_InputAndOutput.c"
#include "MB_Autonomous.c"

/*
By Joseph Dykstra
For practicing with the CS2N Beacons and Barriers Challenge
2013-07-09 - 2013-0?-??

Robot:	MammalBot
Do not move the robot at all from it's starting position.
*/

task main()
	{
	initialize(N_EAST); //Which way does the robot start pointing?
	autoReset(START);

	autoReset(FINISH);
	while(1==1)
		{zeroMotors();
		output();}
	}

/* BUGS...

*/
