#pragma config(UART_Usage, UART2, VEX_2x16_LCD, baudRate1200, IOPins, None, None)
#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  RightLiftEncoderPort, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  RightDriveEncoderPort, sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  LeftLiftEncoderPort, sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  LeftDriveEncoderPort, sensorQuadEncoder)
#pragma config(Sensor, dgtl10, BottomLeftLiftLimitSwitchPort, sensorTouch)
#pragma config(Sensor, dgtl11, BottomRightLiftLimitSwitchPort, sensorTouch)
#pragma config(Sensor, dgtl12, AutonomousJumperPort, sensorDigitalIn)
#pragma config(Motor,  port1,           DriveBL,       tmotorNormal, openLoop)
#pragma config(Motor,  port2,           IntakeL,       tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           LiftBR,        tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port4,           LiftBL,        tmotorNormal, openLoop)
#pragma config(Motor,  port5,           DriveFR,       tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,           DriveFL,       tmotorNormal, openLoop)
#pragma config(Motor,  port7,           LiftFL,        tmotorNormal, openLoop)
#pragma config(Motor,  port8,           LiftFR,        tmotorNormal, openLoop)
#pragma config(Motor,  port9,           IntakeR,       tmotorNormal, openLoop)
#pragma config(Motor,  port10,          DriveBR,       tmotorNormal, openLoop, reversed)
#pragma platform(VEX2)
#define _SIMULATED		// SIMULATOR SWITCH - FOR COMPETITION THIS SHOULD BE COMMENTED OUT!

// ************************************************************************************
// * The following code was creatively composed by Josiah Krutz and Ryan Plummer for
// * Andy, Team 3018's (Techna PWN Robotics) 2011-2012 Robot
// *
// * Addition support provided by:
// *  - http://robotc.net/forums/viewtopic.php?f=52&t=1280
// *  - Josh Duff
// ************************************************************************************

#include "Definitions.c"
#include "Variables.c"
#include "Function_Declarations.c"
#include "Pre_Autonomous.c"
#include "Initialize.c"
#include "Autonomous_Arrays.c"
#include "Get_Input.c"
#include "Autonomous.c"
#include "Operator.c"
#include "Display.c"
#include "Misc_Functions.c"
#include "Do_Output.c"
