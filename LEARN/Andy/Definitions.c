//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#ifdef _SIMULATED
	#include "Vex_Techna_PWN_Debug_Includes.c"			//Debug code - enable
#else
	#include "Vex_Competition_Includes.c"				//Main competition background code...do not modify!
#endif

//Constants
#define LIFTENCODERCONSTANT 1
#define DRIVEENCODERCONSTANT 1
#define FLOORHEIGHT 10
#define LOWGOALHEIGHT 100
#define MIDDLEGOALHEIGHT 200
#define HIGHGOALHEIGHT 300
#define JOYSTICKDRIVEMAX 127
#define MOTORDRIVEMAX 127
#define JOYSTICKDEADZONE 20
#define RIGHTDRIVESLOWDOWNCONSTANT 0.9
#define MOTORRAMPCONSTANT 0.3
#define IN 127
#define OUT -127
#define UP 127
#define DOWN -127
#define FORWARD 127
#define BACKWARD -127
#define STOP 128

//Enums
typedef enum
{
	STRAIGHT,
	LEFTONEWHEELTURN,
	RIGHTONEWHEELTURN,
	BOTHWHEELTURN
} TAutoDriveType;

typedef enum
{
	PLAIN,
	EXPERIMENT
} TDriveAlgorithm;

typedef enum
{
	NORMAL,
	REVERSED
} TRobotDirection;

typedef enum
{
	NOGOALBUTTON,
	LOWGOALBUTTON,
	MIDDLEGOALBUTTON,
	HIGHGOALBUTTON
} TGoalHeightButton;

typedef enum
{
  ANALOG1 = -1,
  NOCONDITION = 0,
  ANALOG2 = 1,
  ANALOG3 = 2,
  ANALOG4 = 3,
  ANALOG5 = 4,
  ANALOG6 = 5,
  ANALOG7 = 6,
  ANALOG8 = 7,
  DIGITAL1 = 8,
  DIGITAL2 = 9,
  DIGITAL3 = 10,
  DIGITAL4 = 11,
  DIGITAL5 = 12,
  DIGITAL6 = 13,
  DIGITAL7 = 14,
  DIGITAL8 = 15,
  DIGITAL9 = 16,
  DIGITAL10 = 17,
  DIGITAL11 = 18,
  DIGITAL12 = 19,
  LEFTDISPLAYBUTTON = 20,
  CENTERDISPLAYBUTTON = 21,
  RIGHTDISPLAYBUTTON = 22,
  ANYDISPLAYBUTTON = 23
} TJumpCondition;

//---------------------------------------------< Structs >-----------------------------------------------\\

typedef struct
{
	float Kp;
	float Ki;
	float Kd;
	float Integral;
	float Derivative;
	float Error;
	float LastError;
	float TargetValue;
	float TargetPower;
	float Output;
} TPidSystem;

typedef struct
{
	string StepName;
	//Outputs
	int LiftPower;
	//int LiftHeight;
	int IntakePower;
	TAutoDriveType DriveType;
	int DrivePower;
	//Trip values
	int Timeout;
	int GyroDegrees;
	int EncoderTicks;
	//Functions
	TJumpCondition JumpCondition;
	int JumpToStep;
} TAutonomous;
