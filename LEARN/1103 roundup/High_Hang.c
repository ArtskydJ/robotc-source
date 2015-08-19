#include "Main.h"

void High_Hang ( void )
{
	Autonomous_Control(Drive,		0,		0,		0,		0,		0, 0, 0,				0, 0, Back, 200,	0,		0,		0 ) ;
	Autonomous_Control(Line_Track,	-50,	-50,	0,		0,		0, 0, 40,				0, 0, Back, 2000,	0,		0,		Line2 ) ;
	Autonomous_Control(Line_Track,	-50,	-50,	-20,	-20,	0, 0, (Ladder - 39),	0, 0, Back, 1000,	0,		0,		Encoder_Track ) ;
	Autonomous_Control(Drive,		5,		15,		0,		0,		0, 0, (Ladder - 39),	0, 0, Back, 3000,	0,		Coast,	Lift_Ready ) ;
	Autonomous_Control(Line_Track,	-50,	-50,	-65,	-65,	0, 0, (Ladder - 39),	0, 0, Back, 1000,	0,		0,		Encoder_Track ) ;
	Autonomous_Control(Drive,		6,		6,		0,		0,		0, 0, Ladder,			0, 0, Back, 2000,	250,	0,		Lift_Ready ) ;
	Autonomous_Control(Drive,		-80,	-80,	0,		0,		0, 0, Ladder,			0, 0, Back, 500,	0,		0,		0 ) ;
	Autonomous_Control(Drive,		-5,		-5,		0,		0,		0, 0, Pickup,			0, 0, Back, 7000,	0,		Coast,	Lift_Ready ) ;
	SetMotor ( 3 , -127 ) ;
	SetMotor ( 4 , 127 ) ;
	SetMotor ( 5 , 127 ) ;
	SetMotor ( 6 , 127 ) ;
	SetMotor ( 9 , -127 ) ;
	SetMotor ( 10 , 127 ) ;
	Wait ( 400 ) ;
}
