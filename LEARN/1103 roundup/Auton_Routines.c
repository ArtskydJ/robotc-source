#include "Main.h"

void Auton_Routines ( void )
{
	if ( Autonomous_Code == Off )
	{
	}
	if ( Event == Match && Position == Infield && Autonomous_Code == 1 )
	{
		Autonomous_Control(Encoder_Track, 63, 63, 41, 41, 0, 0, Movable_Weighted_Base, On, 0, 0, 500, 0, Brake, Encoder_Track);
		if ( Alliance == Red )
		{
			Autonomous_Control(Encoder_Track, -15, 63, 0, 198, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Right_Encoder_Track);
		}
		if ( Alliance == Blue )
		{
			Autonomous_Control(Encoder_Track, 63, -15, 180, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Left_Encoder_Track);
		}
		Autonomous_Control(Drive, 0,	0,	0,	0,	0,	0,	Movable_Weighted_Base,	On,	0,						0,	1200,	0,	Coast,	Lift_Ready);
		Autonomous_Control(Drive, 63,	63,	93,	93,	0,	0,	Movable_Weighted_Base,	On,	0,						0,	1500,	0,	0,		Encoder_Track);
		Autonomous_Control(Drive, 15,	15,	0,	0,	0,	0,	Movable_Weighted_Base,	On,	Movable_Weighted_Base,	0,	2000,	0,	Coast,	Script_Ready);
		Wait ( 150); // #1
		Autonomous_Control(Line_Track, 63, 63, -90, -90, 0, 0, 0, 0, 0, 0, 2000, 0, Brake, Encoder_Track);
		if ( Alliance == Red )
		{
			Autonomous_Control(Drive,			-63,	10,	-117,	0,		0,		0,	Pickup,		0,		0,	0,	2500,	0,	0,		Left_Encoder_Track);
			Autonomous_Control(Encoder_Track,	-63,	63,	-237,	237,	0,		0,	Pickup,		0,		0,	0,	1500,	0,	Brake,	Encoder_Track);
			Autonomous_Control(Wall_Track,	63,		63,	300,	300,	Left,	4,	Pickup,		0,		0,	0,	3000,	0,	0, 		Encoder_Track);
			Autonomous_Control(Wall_Track,	63,		63,	0,		0,		Left,	4,	Pickup,		0,		0,	0,	3000,	100,0,		No_Line);
			Autonomous_Control(Wall_Track,	63,		63,	254,	254,	Left,	4,	Pickup,		0,		0,	0,	4000,	0,	0,		Encoder_Track);
			Autonomous_Control(Wall_Track,	63,		63,	95,		95,		Left,	4,	Pickup,		Ready2,	0,	0,	4000,	0,	Brake,	Encoder_Track);
			Autonomous_Control(Encoder_Track,	-63,	10,	-397,	0,		0,		0,	Wall_Goal,	On,		0,	0,	2000,	0,	Brake,	Left_Encoder_Track);
			Autonomous_Control(Drive,			0, 		0,	0,		0,		0,		0,	Wall_Goal,	On,		0,	0,	3000,	0,	0,		Lift_Ready);
			Autonomous_Control(Wall_Track,	50, 	50,	0,		0,		Right,	38,	Wall_Goal,	On,		0,	0,	1100,	0,	Coast,	0);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track,	10,		-63,	0,		-119,	0,		0,	Pickup,		0,		0,	0,	2500,	0,		0,		Right_Encoder_Track);
		    Autonomous_Control(Encoder_Track,	63,		-63,	235,	-235,	0,		0,	Pickup,		0,		0,	0,	1500,	0,		Brake,	Encoder_Track);
		    Autonomous_Control(Wall_Track,		63,		63,		300,	300,	Right,	4,	Pickup,		0,		0,	0,	3000,	0,		0,		Encoder_Track);
		    Autonomous_Control(Wall_Track,		63,		63,		0,		0,		Right,	4,	Pickup,		0,		0,	0,	3000,	100,	0,		No_Line);
		    Autonomous_Control(Wall_Track,		63,		63,		250,	250,	Right,	4,	Pickup,		0,		0,	0,	4000,	0,		0,		Encoder_Track);
		    Autonomous_Control(Wall_Track,		63,		63,		95,		95,		Right,	4,	Pickup,		Ready2,	0,	0,	4000,	0,		Brake,	Encoder_Track);
		    Autonomous_Control(Encoder_Track,	10,		-63,	0,		-387,	0,		0,	Wall_Goal,	On,		0,	0,	2000,	0,		Brake,	Right_Encoder_Track);
		    Autonomous_Control(Drive,			0,		0,		0,		0,		0,		0,	Wall_Goal,	On,		0,	0,	3000,	0,		0,		Lift_Ready);
		    Autonomous_Control(Wall_Track,		50,		50,		0,		0,		Left,	38,	Wall_Goal,	On,		0,	0,	1100,	0,		0,		0);
		}
		Autonomous_Control(Drive,		20,		20,		0,		0,		0,		0,		Wall_Goal,	On,	Wall_Goal,	0,	2000,	0,	Coast,	Script_Ready);
		Wait(500); // #2
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, (Descore_Wall_Goal + 20), 0, 0, 0, 1500, 0, Coast, Lift_Ready);
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, 0, 0, Descore_Wall_Goal, 0, 2000, 0, Coast, Script_Ready);
		Autonomous_Control(Encoder_Track, -63, -63, -50, -50, 0, 0, Wall_Goal, On, 0, 0, 2000, 0, 0, Encoder_Track);
		Autonomous_Control(Encoder_Track, -63, -63, -80, -80, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, Brake, Encoder_Track);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, 63, -63, 371, -371, 0, 0, Movable_Weighted_Base, On, 0, 0, 1800, 0, Brake, Encoder_Track);
		    Autonomous_Control(Wall_Track, 75, 75, 370, 370, Left, 39, Movable_Weighted_Base, On, 0, 0, 3000, 0, 0, Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, -63, 63, -395, 395, 0, 0, Movable_Weighted_Base, On, 0, 0, 1800, 0, Brake, Left_Encoder_Track);
		    Autonomous_Control(Wall_Track, 75, 75, 370, 370, Right, 39, Movable_Weighted_Base, On, 0, 0, 3000, 0, 0, Encoder_Track);
		}
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, (Movable_Weighted_Base - 55), On, 0, 0, 2000, 0, Coast, Lift_Ready);
		Autonomous_Control(Drive, -80, -80, -100, -100, 0, 0, Pickup, 0, 0, 0, 2000, 0, 0, Encoder_Track);
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Pickup, 0, 0, 0, 2000, 0, 0, Lift_Ready);
	}
	if ( Event == Match && Position == Infield && Autonomous_Code == 2 )
	{
		Autonomous_Control(Drive, -110, -110, 0, 0, 0, 0, 100, On, 0, 0, 2000, 250, 0, No_Line);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, -70, -70, -564, -564, 0, 0, 100, On, 0, 0, 3500, 0, Brake, Left_Encoder_Track);
		    Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, 0, On, 0, 0, 350, 0, Coast, 0);
		    Autonomous_Control(Encoder_Track, -15, 70, 0, 392, 0, 0, Movable_Weighted_Base, On, 0, 0, 2500, 0, Brake, Right_Encoder_Track);
		    Autonomous_Control(Wall_Track, 63, 63, 340, 340, Left, 39, Movable_Weighted_Base, On, 0, 0, 3000, 0, Coast, Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, -70, -70, -525, -525, 0, 0, 100, On, 0, 0, 3500, 0, Brake, Left_Encoder_Track);
		    Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, 0, On, 0, 0, 300, 0, Coast, 0);
		    Autonomous_Control(Encoder_Track, 70, -15, 360, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 2500, 0, Brake, Left_Encoder_Track);
		    Autonomous_Control(Wall_Track, 63, 63, 300, 300, Right, 39, Movable_Weighted_Base, On, 0, 0, 3000, 0, Coast, Encoder_Track);
		}
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, Movable_Weighted_Base, On, Movable_Weighted_Base, 0, 2000, 0, Coast, Script_Ready);
		Wait ( 150); // #1
		Autonomous_Control(Encoder_Track, -63, -63, -40, -40, 0, 0, 0, 0, 0, 0, 500, 0, Brake, Encoder_Track);
		Autonomous_Control(Drive, 10, 10, 0, 0, 0, 0, (Movable_Weighted_Base - 40), 0, 0, 0, 1500, 0, Coast, Lift_Ready);
		Autonomous_Control(Drive, 63, 63, 0, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0, 0);
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, 0, 0, Descore_Movable_Weighted_Base, 0, 2000, 0, Coast, Script_Ready);
		Autonomous_Control(Encoder_Track, -63, -63, -125, -125, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, Brake, Encoder_Track);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, -63, 63, -398, 398, 0, 0, Movable_Weighted_Base, On, 0, 0, 2250, 0, Brake, Left_Encoder_Track);
		    Autonomous_Control(Wall_Track, 55, 55, 375, 375, Right, 38, Wall_Goal, On, 0, 0, 3000, 0, 0, Encoder_Track);
		    Autonomous_Control(Wall_Track, 55, 55, 0, 0, Right, 38, Wall_Goal, On, 0, 0, 300, 0, 0, 0);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, 63, -63, 370, -370, 0, 0, Movable_Weighted_Base, On, 0, 0, 2250, 0, Brake, Encoder_Track);
		    Autonomous_Control(Wall_Track, 55, 55, 350, 350, Left, 39, Wall_Goal, On, 0, 0, 3000, 0, 0, Encoder_Track);
		    Autonomous_Control(Wall_Track, 55, 55, 0, 0, Left, 39, Wall_Goal, On, 0, 0, 300, 0, 0, 0);
		}
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, Wall_Goal, On, Wall_Goal, 0, 2000, 0, Coast, Script_Ready);
		Wait ( 150 ); // #2
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, (Wall_Goal - 50), 0, 0, 0, 500, 0, Coast, Lift_Ready);
		Autonomous_Control(Encoder_Track, -63, -63, -150, -150, 0, 0, 0, 0, 0, 0, 1500, 0, Coast, Encoder_Track);
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Pickup, 0, 0, 0, 2000, 0, 0, Lift_Ready);
	}
	if ( Event == Match && Position == Outfield && Autonomous_Code == 1 )
	{
		Autonomous_Control(Encoder_Track, 50, 50, 70, 70, 0, 0, Wall_Goal, On, 0, 0, 1000, 0, Brake, Encoder_Track);
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 5000, 1000, Coast, Lift_Ready);
		Autonomous_Control(Drive, 55, 55, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 500, 0, 0, 0);
		Autonomous_Control(Drive, 10, 10, 0, 0, 0, 0, Wall_Goal, On, Wall_Goal, 0, 2000, 0, Coast, Script_Ready);
		Wait ( 150); // #1
		Autonomous_Control(Drive, -63, -63, -65, -65, 0, 0, 0, 0, 0, 0, 1000, 0, 0, Encoder_Track);
		Autonomous_Control(Encoder_Track, -63, -63, -70, -70, 0, 0, Pickup, 0, 0, 0, 1000, 0, Brake, Encoder_Track);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, -63, 10, -210, 0, 0, 0, Pickup, 0, 0, 0, 1000, 0, Brake, Left_Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, 10, -63, 0, -217, 0, 0, Pickup, 0, 0, 0, 1000, 0, Brake, Right_Encoder_Track);
		}
		Autonomous_Control(Drive, 63, 63, 60, 60, 0, 0, Pickup, 0, 0, 0, 2000, 0, 0, Encoder_Track);
		Autonomous_Control(Drive, 63, 63, 90, 90, 0, 0, Pickup, Ready, 0, 0, 1000, 0, 0, Encoder_Track);
		Autonomous_Control(Drive, 63, 63, 0, 0, 0, 0, Pickup, On, 0, 0, 100, 100, Brake, 0);
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 300, 300, 0, 0);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, -63, 63, -160, 160, 0, 0, Movable_Weighted_Base, On, 0, 0, 1200, 0, Brake, Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, 63, -63, 136, -136, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		}
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, 0, Lift_Ready);
		Autonomous_Control(Drive, 63, 63, 160, 160, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, 0, Encoder_Track);
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, Movable_Weighted_Base, On, Movable_Weighted_Base, 0, 2000, 0, Coast, Script_Ready);
		Wait ( 150); // #2
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, 10, -63, 0, -180, 0, 0, 0, 0, 0, 0, 1000, 0, Coast, Right_Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, -63, 10, -150, 0, 0, 0, 0, 0, 0, 0, 1000, 0, Coast, Left_Encoder_Track);
		}
		Autonomous_Control(Drive, -127, -127, -50, -50, 0, 0, 0, 0, 0, 0, 1000, 0, 0, Encoder_Track);
		Autonomous_Control(Encoder_Track, -127, -127, -440, -440, 0, 0, Pickup, 0, 0, 0, 2500, 0, Coast, Encoder_Track);
		Wait ( 200);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, -63, 63, -100, 100, 0, 0, 0, 0, 0, 0, 1500, 0, Coast, Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, 63, -63, 70, -70, 0, 0, 0, 0, 0, 0, 1000, 0, Coast, Encoder_Track);
		}
		Autonomous_Control(Drive, 63, 63, 200, 200, 0, 0, 0, 0, 0, 0, 2000, 0, Coast, Encoder_Track);
	}
	if ( Event == Match && Position == Outfield && Autonomous_Code == 2 )
	{
		Autonomous_Control(Encoder_Track, 55, 55, 60, 60, 0, 0, Wall_Goal, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 200, 0, Coast, 0);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, 10, -63, 0, -405, 0, 0, Wall_Goal, On, 0, 0, 2500, 0, Brake, Right_Encoder_Track);
		    Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 3000, 0, 0, Lift_Ready);
		    Autonomous_Control(Wall_Track, 55, 55, 175, 175, Left, 38, Wall_Goal, On, 0, 0, 2000, 0, 0, Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, -63, 10, -420, 0, 0, 0, Wall_Goal, On, 0, 0, 2500, 0, Brake, Left_Encoder_Track);
		    Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 3000, 0, 0, Lift_Ready);
		    Autonomous_Control(Wall_Track, 55, 55, 175, 175, Right, 38, Wall_Goal, On, 0, 0, 2000, 0, 0, Encoder_Track);
		}
		Autonomous_Control(Drive, 25, 25, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 200, 0, 0, 0);
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, Wall_Goal, On, Wall_Goal, 0, 2000, 0, Coast, Script_Ready);
		Wait(1000); // #1
		Autonomous_Control(Encoder_Track, -50, -50, -100, -100, 0, 0, 0, 0, 0, 0, 1500, 0, Coast, Encoder_Track);
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Pickup, 0, 0, 0, 2000, 0, 0, Lift_Ready);
	}
	if ( Event == Match && Autonomous_Code == 3 )
	{
		Autonomous_Control(Encoder_Track, 80, 80, 115, 115, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 600, 0, Coast, Lift_Ready);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Drive, -20, 75, 0, 325, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, 0, Right_Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Drive, 70, -20, 325, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, 0, Left_Encoder_Track);
		}
		Autonomous_Control(Drive, 80, 80, 0, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 400, 0, 0, 0);
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, Movable_Weighted_Base, On, Movable_Weighted_Base, 0, 2000, 0, Coast, Script_Ready);
		Wait ( 150); // #1
		Autonomous_Control(Line_Track, 63, 63, -100, -100, 0, 0, 0, 0, 0, 0, 1000, 0, Brake, Encoder_Track);
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Pickup, 0, 0, 0, 2000, 0, 0, Lift_Ready);
	}
	if ( Event == Match && Autonomous_Code == 4 )
	{
		Autonomous_Control(Encoder_Track, 63, 63, 43, 43, 0, 0, Movable_Weighted_Base, On, 0, 0, 700, 0, Brake, Encoder_Track);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, -10, 63, 0, 200, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, Brake, Right_Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, 63, -10, 177, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, Brake, Left_Encoder_Track);
		}
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 1300, 0, Coast, Lift_Ready);
		Autonomous_Control(Drive, 63, 63, 93, 93, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, 0, Encoder_Track);
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, Movable_Weighted_Base, On, Movable_Weighted_Base, 0, 2000, 0, Coast, Script_Ready);
		Wait ( 150); // #1
		Autonomous_Control(Drive, -55, -55, -30, -30, 0, 0, 0, 0, 0, 0, 1000, 0, Brake, Encoder_Track);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, 10, -80, 0, -730, 0, 0, 0, 0, 0, 0, 5000, 0, Brake, Right_Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, -80, 10, -743, 0, 0, 0, 0, 0, 0, 0, 5000, 0, Brake, Left_Encoder_Track);
		}
		Autonomous_Control(Drive, -55, -55, 0, 0, 0, 0, 15, 0, 0, 0, 1500, 0, 0, Line);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, -55, -55, -55, -55, 0, 0, 15, 0, 0, 0, 1500, 0, Brake, Encoder_Track);
		    Autonomous_Control(Drive, -58, 58, 0, 0, 0, 0, 0, 0, 0, 0, 1500, 0, Brake, Line);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, -55, -55, -55, -55, 0, 0, 15, 0, 0, 0, 1500, 0, Brake, Encoder_Track);
		    Autonomous_Control(Drive, 58, -58, 0, 0, 0, 0, 0, 0, 0, 0, 1500, 0, Brake, Line);
		}
		High_Hang ();
	}
	if ( Event == Match && Position == Infield && Autonomous_Code == 5 )
	{
		Autonomous_Control(Drive, -100, -127, 0, 0, 0, 0, 100, On, 0, 0, 2000, 250, 0, No_Line);
		Autonomous_Control(Drive, -105, -127, -190, -190, 0, 0, 100, On, 0, 0, 3500, 0, 0, Left_Encoder_Track);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Drive, 10, -127, 0, -210, 0, 0, 100, On, 0, 0, 2000, 0, 0, Right_Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Drive, -127, 10, -255, 0, 0, 0, 100, On, 0, 0, 2000, 0, 0, Left_Encoder_Track);
		}
		Autonomous_Control(Drive, -105, -127, -320, -320, 0, 0, 100, On, 0, 0, 3500, 0, 0, Encoder_Track);
		Autonomous_Control(Encoder_Track, -63, -63, -310, -310, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, Brake, Encoder_Track);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, -63, 63, -130, 130, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		    Autonomous_Control(Wall_Track, 63, 63, 225, 225, Right, 38, Movable_Weighted_Base, On, 0, 0, 2500, 0, 0, Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, 63, -63, 130, -130, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		    Autonomous_Control(Wall_Track, 63, 63, 225, 225, Left, 38, Movable_Weighted_Base, On, 0, 0, 2500, 0, 0, Encoder_Track);
		}
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, Movable_Weighted_Base, On, Movable_Weighted_Base, 0, 2000, 0, Coast, Script_Ready);
		Wait ( 150); // #1
		Autonomous_Control(Encoder_Track, -63, -63, -150, -150, 0, 0, 0, 0, 0, 0, 1500, 0, Coast, Encoder_Track);
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Pickup, 0, 0, 0, 2000, 0, Coast, Lift_Ready);
	}
	if ( Event == Match && Position == Outfield && Autonomous_Code == 5 )
	{
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 500, 0, Coast, Lift_Ready);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, 55, 55, 60, 60, 0, 0, Wall_Goal, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		    Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 200, 0, Coast, 0);
		    Autonomous_Control(Encoder_Track, 15, -70, 0, -388, 0, 0, Wall_Goal, On, 0, 0, 2500, 0, Brake, Right_Encoder_Track);
		    Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 1000, 0, 0, Lift_Ready);
		    Autonomous_Control(Wall_Track, 55, 55, 175, 175, Left, 38, Wall_Goal, On, 0, 0, 1300, 0, 0, Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, 55, 55, 68, 68, 0, 0, Wall_Goal, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		    Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 200, 0, Coast, 0);
		    Autonomous_Control(Encoder_Track, -70, 15, -397, 0, 0, 0, Wall_Goal, On, 0, 0, 3000, 0, Brake, Left_Encoder_Track);
		    Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 3000, 0, 0, Lift_Ready);
		    Autonomous_Control(Wall_Track, 55, 55, 175, 175, Right, 38, Wall_Goal, On, 0, 0, 1300, 0, 0, Encoder_Track);
		}
		Autonomous_Control(Drive, 25, 25, 0, 0, 0, 0, Wall_Goal, On, 0, 0, 200, 0, 0, 0);
		Autonomous_Control(Drive, 15, 15, 0, 0, 0, 0, Wall_Goal, On, Wall_Goal, 0, 2000, 0, Coast, Script_Ready);
		Wait ( 150); // #1
		Autonomous_Control(Drive, -63, -63, -50, -50, 0, 0, 0, 0, 0, 0, 1500, 0, 0, Encoder_Track);
		Autonomous_Control(Encoder_Track, -63, -63, -173, -173, 0, 0, Pickup, 0, 0, 0, 1500, 0, Brake, Encoder_Track);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, -63, 63, -194, 194, 0, 0, Pickup, 0, 0, 0, 2000, 0, Brake, Encoder_Track);
		    Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Descore_Movable_Weighted_Base, 0, 0, 0, 1000, 1000, 0, 0);
		    Autonomous_Control(Wall_Track, 75, 75, 245, 245, Right, 16, Descore_Movable_Weighted_Base, 0, 0, 0, 2500, 0, 0, Encoder_Track);
		    Autonomous_Control(Drive, 25, 25, 0, 0, 0, 0, Descore_Movable_Weighted_Base, On, Descore_Movable_Weighted_Base, 0, 3000, 0, Coast, Script_Ready);
		    Autonomous_Control(Encoder_Track, -63, -63, -260, -260, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		    Autonomous_Control(Encoder_Track, -63, 63, -206, 206, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, 63, -63, 186, -186, 0, 0, Pickup, 0, 0, 0, 2000, 0, Brake, Encoder_Track);
		    Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Descore_Movable_Weighted_Base, 0, 0, 0, 1000, 1000, 0, 0);
		    Autonomous_Control(Wall_Track, 75, 75, 245, 245, Left, 16, Descore_Movable_Weighted_Base, 0, 0, 0, 2500, 0, 0, Encoder_Track);
		    Autonomous_Control(Drive, 25, 25, 0, 0, 0, 0, Descore_Movable_Weighted_Base, On, Descore_Movable_Weighted_Base, 0, 3000, 0, Coast, Script_Ready);
		    Autonomous_Control(Encoder_Track, -63, -63, -260, -260, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		    Autonomous_Control(Encoder_Track, 63, -63, 175, -175, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Encoder_Track);
		}
		Autonomous_Control(Drive, 75, 75, 50, 50, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, 0, Encoder_Track);
		Autonomous_Control(Encoder_Track, 75, 75, 50, 50, 0, 0, Movable_Weighted_Base, Off, 0, 0, 2000, 0, Brake, Encoder_Track);
		Autonomous_Control(Encoder_Track, -63, -63, -190, -190, 0, 0, Pickup, Off, 0, 0, 1500, 0, Brake, Encoder_Track);
		if ( Alliance == Red )
		{
		    Autonomous_Control(Encoder_Track, 10, -75, 0, -353, 0, 0, Pickup, 0, 0, 0, 3000, 0, Brake, Right_Encoder_Track);
		    Autonomous_Control(Wall_Track, 63, 63, 0, 0, Right, 5, Pickup, 0, 0, 0, 3000, 0, 0, No_Line);
		    Autonomous_Control(Wall_Track, 63, 63, 30, 30, Right, 5, Pickup, Ready, 0, 0, 1500, 0, Brake, Encoder_Track);
		    Autonomous_Control(Encoder_Track, -15, 70, 0, 190, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Right_Encoder_Track);
		}
		if ( Alliance == Blue )
		{
		    Autonomous_Control(Encoder_Track, -75, 10, -355, 0, 0, 0, Pickup, 0, 0, 0, 3000, 0, Brake, Left_Encoder_Track);
		    Autonomous_Control(Wall_Track, 63, 63, 0, 0, Left, 5, Pickup, 0, 0, 0, 3000, 0, 0, No_Line);
		    Autonomous_Control(Wall_Track, 63, 63, 45, 45, Left, 5, Pickup, Ready, 0, 0, 1500, 0, Brake, Encoder_Track);
		    Autonomous_Control(Encoder_Track, 70, -15, 185, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 1500, 0, Brake, Left_Encoder_Track);
		}
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, 0, Lift_Ready);
		Autonomous_Control(Drive, 75, 75, 130, 130, 0, 0, Movable_Weighted_Base, On, 0, 0, 2000, 0, Coast, Encoder_Track);
		Autonomous_Control(Drive, 20, 20, 0, 0, 0, 0, (Movable_Weighted_Base - 40), On, 0, 0, 2000, 0, Coast, Lift_Ready);
		Autonomous_Control(Encoder_Track, -75, -75, -120, -120, 0, 0, Pickup, 0, 0, 0, 2000, 0, Coast, Encoder_Track);
		Autonomous_Control(Drive, 0, 0, 0, 0, 0, 0, Pickup, 0, 0, 0, 2000, 0, Coast, Lift_Ready);
	}
	if ( Event == PSC )
	{
		Programming_Skills_Challenge ();
	}
}
