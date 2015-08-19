#include	"Main.h"

void Programming_Skills_Challenge(void)
{
	Autonomous_Control(Encoder_Track,		50,		50,		44,		44,		0,		0,	Movable_Weighted_Base,	On,		0,						0,	800,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Encoder_Track,		-15,	50,		0,		216,	0,		0,	Movable_Weighted_Base,	On,		0,						0,	1500,	0,		Brake,	Right_Encoder_Track);
	Autonomous_Control(Drive,				0,		0,		0,		0,		0,		0,	Movable_Weighted_Base,	On,		0,						0,	1000,	0,		0,		Lift_Ready);
	Autonomous_Control(Encoder_Track,		50,		50,		145,	145,	0,		0,	Movable_Weighted_Base,	On,		0,						0,	1100,	0,		Coast,	Encoder_Track);
	Autonomous_Control(Line_Track,			15,		15,		0,		0,		0,		0,	Movable_Weighted_Base,	On,		Movable_Weighted_Base,	0,	1300,	0,		Coast,	Script_Ready);
	Wait(300);	//	#1
	Autonomous_Control(Line_Track,			-50,	-50,	-60,	-60,	0,		0,	0,						0,		0,						0,	2000,	0,		0,		Left_Encoder_Track);
	Autonomous_Control(Line_Track,			-58,	-58,	-90,	-90,	0,		0,	0,						0,		0,						0,	2000,	0,		Brake,	Left_Encoder_Track);
	Autonomous_Control(Encoder_Track,		-63,	85,		-101,	478,	0,		0,	Pickup,					0,		0,						0,	2800,	0,		Brake,	Right_Encoder_Track);
	Autonomous_Control(Wall_Track,			63,		63,		0,		0,		Left,	16,	0,						0,		0,						0,	4000,	350,	0,		Line2);
	Autonomous_Control(Wall_Track,			63,		63,		100,	100,	Left,	17,	0,						0,		0,						0,	2000,	0,		0,		Encoder_Track);
	Autonomous_Control(Wall_Track,			63,		63,		0,		0,		Left,	17,	Pickup,					Ready,	0,						0,	2000,	100,	0,		No_Line2);
	Autonomous_Control(Wall_Track,			63,		63,		306,	306,	Left,	17,	Movable_Weighted_Base,	On,		0,						0,	4000,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Encoder_Track,		63,		-63,	196,	-197,	0,		0,	Movable_Weighted_Base,	On,		0,						0,	1000,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Wall_Track,			63,		63,		135,	135,	Left,	39,	Movable_Weighted_Base,	On,		0,						0,	2000,	0,		0,		Encoder_Track);
	Autonomous_Control(Wall_Track,			55,		55,		135,	135,	Left,	39,	Movable_Weighted_Base,	On,		0,						0,	1500,	0,		Coast,	Encoder_Track);
	Autonomous_Control(Line_Track,			15,		15,		0,		0,		0,		0,	Movable_Weighted_Base,	On,		Movable_Weighted_Base,	0,	2000,	0,		Coast,	Script_Ready);
	Wait(150);	//	#2
	Autonomous_Control(Encoder_Track,		80,		80,		-130,	-130,	0,		0,	0,						0,		0,						0,	2000,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Encoder_Track,		63,		63,		-143,	143,	0,		0,	Pickup,					0,		0,						0,	1200,	0,		Brake,	Left_Encoder_Track);
	Autonomous_Control(Encoder_Track,		63,		63,		272,	272,	0,		0,	Pickup,					0,		0,						0,	3000,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Encoder_Track,		63,		-10,	218,	0,		0,		0,	Pickup,					0,		0,						0,	3000,	0,		Brake,	Left_Encoder_Track);
	Autonomous_Control(Wall_Track,			63,		63,		0,		0,		Left,	17,	Pickup,					0,		0,						0,	3000,	0,		0,		Line2);
	Autonomous_Control(Wall_Track,			63,		63,		100,	100,	Left,	17,	Pickup,					Ready,	0,						0,	3000,	0,		0,		Left_Encoder_Track);
	Autonomous_Control(Wall_Track,			63,		63,		80,		80,		Left,	17,	Movable_Weighted_Base,	On,		0,						0,	3000,	0,		0,		Left_Encoder_Track);
	Autonomous_Control(Wall_Track,			63,		63,		0,		0,		Left,	17,	Movable_Weighted_Base,	On,		0,						0,	4000,	100,	0,		No_Line2);
	Autonomous_Control(Wall_Track,			63,		63,		85,		85,		Left,	17,	Movable_Weighted_Base,	On,		0,						0,	4000,	0,		Coast,	Left_Encoder_Track);
	Autonomous_Control(Line_Track,			-10,	-10,	0,		0,		0,		0,	Movable_Weighted_Base,	On,		0,						0,	2000,	250,	Coast,	Lift_Ready);
	Autonomous_Control(Wall_Track,			55,		55,		160,	160,	Left,	18,	Movable_Weighted_Base,	On,		0,						0,	2500,	0,		Coast,	Left_Encoder_Track);
	Autonomous_Control(Line_Track,			15,		15,		0,		0,		0,		0,	Movable_Weighted_Base,	On,		Movable_Weighted_Base,	0,	2000,	0,		Coast,	Script_Ready);
	Wait(150);	//	#3
	Autonomous_Control(Encoder_Track,		-63,	-63,	-160,	-160,	0,		0,	0,						0,		0,						0,	3000,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Encoder_Track,		63,		-63,	106,	-106,	0,		0,	Pickup,					0,		0,						0,	1200,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Line_Track,			63,		63,		0,		0,		0,		0,	Pickup,					0,		0,						0,	1500,	200,	0,		Line);
	Autonomous_Control(Encoder_Track,		63,		63,		52,		52,		0,		0,	Pickup,					0,		0,						0,	1500,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Encoder_Track,		63,		-10,	162,	0,		0,		0,	Pickup,					0,		0,						0,	2500,	0,		Brake,	Left_Encoder_Track);
	Autonomous_Control(Wall_Track,			63,		63,		0,		0,		Left,	16,	Pickup,					0,		0,						0,	3000,	500,	0,		No_Line2);
	Autonomous_Control(Wall_Track,			63,		63,		50,		50,		Left,	16,	Movable_Weighted_Base,	On,		0,						0,	3000,	0,		Coast,	Left_Encoder_Track);
	Autonomous_Control(Line_Track,			-7,		-7,		0,		0,		0,		0,	Movable_Weighted_Base,	On,		0,						0,	3000,	0,		Coast,	Lift_Ready);
	Autonomous_Control(Wall_Track,			55,		55,		175,	175,	Left,	16,	Movable_Weighted_Base,	On,		0,						0,	3000,	0,		Coast,	Left_Encoder_Track);
	Autonomous_Control(Line_Track,			15,		15,		0,		0,		0,		0,	Movable_Weighted_Base,	On,		Movable_Weighted_Base,	0,	2000,	0,		Coast,	Script_Ready);
	Wait(150);	//	#4
	Autonomous_Control(Encoder_Track,		-63,	-63,	-243,	-243,	0,		0,	0,						0,		0,						0,	2000,	0,		Brake,	Left_Encoder_Track);
	Autonomous_Control(Encoder_Track,		63,		-63,	90,		-91,	0,		0,	Pickup,					0,		0,						0,	1000,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Line_Track,			63,		63,		215,	215,	0,		0,	0,						0,		0,						0,	2000,	0,		0,		Encoder_Track);
	Autonomous_Control(Wall_Track,			61,		61,		255,	255,	Right,	8,	Pickup,					0,		0,						0,	2000,	0,		0,		Left_Encoder_Track);
	//	//
	Autonomous_Control(Line_Track,			63,		63,		0,		0,		0,		0,	Pickup,					Ready,	0,						0,	2000,	0,		0,		Line2);
	Autonomous_Control(Line_Track,			63,		63,		0,		0,		0,		0,	Movable_Weighted_Base,	On,		0,						0,	2000,	0,		Brake,	Line);
	Autonomous_Control(Line_Track,			-7,		-7,		0,		0,		0,		0,	Movable_Weighted_Base,	On,		0,						0,	200,	0,		0,		0);
	Autonomous_Control(Encoder_Track,		-63,	-63,	-105,	-105,	0,		0,	Movable_Weighted_Base,	On,		0,						0,	1500,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Encoder_Track,		63,		63,		-285,	285,	0,		0,	Movable_Weighted_Base,	On,		0,						0,	1500,	0,		Brake,	Encoder_Track);
	Autonomous_Control(Line_Track,			60,		60,		0,		0,		0,		0,	Movable_Weighted_Base,	On,		0,						0,	250,	250,	0,		0);
	Autonomous_Control(Wall_Track,			60,		60,		260,	260,	Right,	16,	Movable_Weighted_Base,	On,		0,						0,	3000,	0,		0,		Left_Encoder_Track);
	Autonomous_Control(Line_Track,			15,		15,		0,		0,		0,		0,	Movable_Weighted_Base,	On,		Movable_Weighted_Base,	0,	2000,	0,		Coast,	Script_Ready);
	Wait(150);	//	#5
	if(Autonomous_Code==1)
		{
		Autonomous_Control(Encoder_Track,	-63,	-63,	-125,	-125,	0,		0,	0,						0,		0,						0,	2000,	0,		Brake,	Encoder_Track);
		Autonomous_Control(Encoder_Track,	-63,	63,		-380,	380,	0,		0,	Pickup,					0,		0,						0,	3000,	0,		Brake,	Left_Encoder_Track);
		Autonomous_Control(Wall_Track,		61,		61,		400,	400,	Left,	17,	Pickup,					0,		0,						0,	2500,	0,		0,		Left_Encoder_Track);
		Autonomous_Control(Wall_Track,		61,		61,		0,		0,		Left,	17,	Pickup,					0,		0,						0,	2500,	150,	Brake,	No_Line2);
		Autonomous_Control(Line_Track,		-12,	-12,	0,		0,		0,		0,	0,						0,		0,						0,	100,	0,		Coast,	0);
		Autonomous_Control(Encoder_Track,	10,		-63,	0,		-190,	0,		0,	0,						0,		0,						0,	1000,	0,		Brake,	Right_Encoder_Track);
		Autonomous_Control(Line_Track,		60,		60,		0,		0,		0,		0,	15,						0,		0,						0,	2000,	700,	0,		Line2);
		Autonomous_Control(Line_Track,		50,		50,		0,		0,		0,		0,	15,						0,		0,						0,	1000,	0,		Brake,	Line);
		Autonomous_Control(Encoder_Track,	50,		50,		-100,	-100,	0,		0,	15,						0,		0,						0,	1500,	0,		Brake,	Encoder_Track);
		Autonomous_Control(Line_Track,		-55,	55,		0,		0,		0,		0,	0,						0,		0,						0,	1500,	0,		Brake,	Line);
		}
	if(Autonomous_Code==2)
		{
		Autonomous_Control(Encoder_Track,	-85,	10,		-500,	0,		0,		0,	0,						0,		0,						0,	2000,	0,		0,		Left_Encoder_Track);
		Autonomous_Control(Encoder_Track,	-63,	63,		-140,	140,	0,		0,	Pickup,					0,		0,						0,	1200,	0,		Brake,	Encoder_Track);
		Autonomous_Control(Line_Track,		60,		60,		0,		0,		0,		0,	0,						0,		0,						0,	100,	0,		0,		0);
		Autonomous_Control(Wall_Track,		63,		63,		300,	300,	Left,	5,	Pickup,					0,		0,						0,	3000,	0,		0,		Left_Encoder_Track);
		Autonomous_Control(Wall_Track,		63,		63,		0,		0,		Left,	5,	Pickup,					0,		0,						0,	2500,	50,		0,		No_Line2);
		Autonomous_Control(Wall_Track,		63,		63,		0,		0,		Left,	5,	Pickup,					Ready,	0,						0,	1000,	50,		0,		No_Line);
		Autonomous_Control(Wall_Track,		63,		63,		15,		15,		Left,	5,	Wall_Goal,				On,		0,						0,	1000,	0,		0,		Encoder_Track);
		Autonomous_Control(Line_Track,		-15,	-15,	0,		0,		0,		0,	Wall_Goal,				On,		0,						0,	250,	0,		0,		0);
		Autonomous_Control(Encoder_Track,	-63,	18,		-405,	0,		0,		0,	Wall_Goal,				On,		0,						0,	2000,	0,		Brake,	Left_Encoder_Track);
		//	//
		Autonomous_Control(Line_Track,		0,		0,		0,		0,		0,		0,	Wall_Goal,				On,		0,						0,	3000,	0,		0,		Lift_Ready);
		Autonomous_Control(Line_Track,		60,		60,		0,		0,		0,		0,	0,						On,		0,						0,	100,	0,		0,		0);
		Autonomous_Control(Wall_Track,		50,		50,		0,		0,		Right,	38,	Wall_Goal,				On,		0,						0,	1000,	0,		Coast,	0);
		Autonomous_Control(Line_Track,		20,		20,		0,		0,		0,		0,	Wall_Goal,				On,		Wall_Goal,				0,	2000,	0,		Coast,	Script_Ready);
		Wait(250);	//	#6
		Autonomous_Control(Line_Track,		-63,	-63,	-100,	-100,	0,		0,	0,						0,		0,						0,	1500,	0,		0,		Encoder_Track);
		Autonomous_Control(Encoder_Track,	-63,	-63,	-150,	-150,	0,		0,	Pickup,					0,		0,						0,	2000,	0,		Brake,	Encoder_Track);
		Autonomous_Control(Encoder_Track,	-63,	15,		-200,	0,		0,		0,	Pickup,					0,		0,						0,	2000,	0,		Brake,	Left_Encoder_Track);
		Autonomous_Control(Line_Track,		-55,	-55,	0,		0,		0,		0,	15,						0,		0,						0,	1500,	0,		0,		Line);
		Autonomous_Control(Encoder_Track,	-55,	-55,	-60,	-60,	0,		0,	15,						0,		0,						0,	1500,	0,		Brake,	Encoder_Track);
		Autonomous_Control(Line_Track,		60,		-60,	0,		0,		0,		0,	0,						0,		0,						0,	1500,	0,		Brake,	Line);
		}
	High_Hang();
}
