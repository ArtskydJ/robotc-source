#include "Main.h"

void Motor_Drive ( void )
{
	Lift_Encoder = GetQuadEncoder ( 9 , 10 ) ;
	Lift_Limit = GetAnalogInput ( 4 ) ;
	if ( Lift_Limit < 10  )
	{
		PresetQuadEncoder ( 9 , 10 , 0) ;
	}
	if ( Script != Off )
	{
		Script_Functions (   ) ;
	}
	if ( (Ch5u == 0 && Ch5d == 0) || Lift_Reset == On || Ch5d_Armed == Off )
	{
		Error = (Lift_Setpoint - Lift_Encoder) ;
		if ( Error >= -Dead_Zone && Error <= Dead_Zone ) //Lift is inside dead zone
		{
			if ( Lift_Setpoint == Pickup && Lift_Limit >= 10  ) //Lift is too high
			{
				Lift_Motor = -127 ;
			}
			if ( Lift_Setpoint == Pickup && Lift_Limit < 10 ) //Lift is low enough
			{
				Lift_Status = Ready ;
				if ( Tilt == Forward )
				{
					Lift_Motor = -5 ;
				}
				if ( Tilt == Back )
				{
					Lift_Motor = -10 ;
				}
			}
			if ( Lift_Setpoint != Pickup && Lift_Limit >= 10 )
			{
				Lift_Motor = 10 ;
				Lift_Status = Ready ;
			}
		}
		if ( Error > Dead_Zone || Error < -Dead_Zone ) //Lift is outside deadzone
		{
			if ( Error > 0 && Lift_Setpoint != Pickup && Lift_Setpoint <= Wall_Goal )
			{
				Lift_Motor = ((Error * 3) + 80) ;
			}
			if ( Error > 0 && Lift_Setpoint > Wall_Goal )
			{
				Lift_Motor = 127 ;
			}
			if ( Error > 0 && Lift_Setpoint == Pickup )
			{
				Lift_Motor = -45 ;
			}
			if ( Error < 0 && Lift_Setpoint == Pickup )
			{
				Lift_Motor = -127 ;
			}
			if ( Error < 0 && Lift_Setpoint != Pickup )
			{
				Lift_Motor = ((Error * 1.8) + 22) ;
			}
			Lift_Status = Moving ;
		}
		if ( Lift_Motor > 127 )
		{
			Lift_Motor = 127 ;
		}
		if ( Lift_Motor < -127 )
		{
			Lift_Motor = -127 ;
		}
		if ( Lift_Limit < 10 && Lift_Motor < -15 && Tilt == Forward )
		{
			Lift_Motor = -15 ;
		}
	}
	if ( Lift_Encoder > (Ladder + 6) && Lift_Motor > 10 )
	{
		Lift_Motor = 10 ;
	}
	SetMotor ( 3 , Lift_Motor ) ;
	SetMotor ( 4 , (-Lift_Motor) ) ;
	SetMotor ( 5 , (-Lift_Motor) ) ;
	SetMotor ( 6 , (-Lift_Motor) ) ;
	SetMotor ( 9 , Lift_Motor ) ;
	SetMotor ( 10 , (-Lift_Motor) ) ;
	if ( Tilt == Back )
	{
		SetDigitalOutput ( 12 , 1 ) ;
	}
	if ( Tilt == Forward  )
	{
		SetDigitalOutput ( 12 , 0 ) ;
	}
	if ( Gripper == On )
	{
		SetDigitalOutput ( 11 , 1 ) ;
	}
	if ( Gripper == Off )
	{
		SetDigitalOutput ( 11 , 0 ) ;
	}
	SetMotor ( 1 , -Left_Motor ) ;
	SetMotor ( 2 , Right_Motor ) ;
	SetMotor ( 8 , Right_Motor ) ;
	SetMotor ( 7 , Left_Motor ) ;
}
