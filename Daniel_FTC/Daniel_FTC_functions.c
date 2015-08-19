#define close true
#define open false

void startup()
	{
	nMotorEncoder[motorA]=0;	//claw
	nMotorEncoder[motorB]=0;	//wrist
	nMotorEncoder[r_lift]=0;	//right lift
	nMotorEncoder[l_lift]=0;	//left lift
	nMotorEncoder[br_drive]=0;	//right back
	nMotorEncoder[bl_drive]=0;	//left back
	SensorValue[compass]=0;
	}


void drive_motors_to_zero()
	{
	motor[fr_drive]=0;
	motor[fl_drive]=0;
	motor[br_drive]=0;
	motor[bl_drive]=0;
	}

void wait(int time_wait)
	{
	ClearTimer(T1);
	while(time1[T1]<time_wait)
		{}
	}


void forward(int time_length)
	{
	motor[fr_drive]=100;
	motor[fl_drive]=100;
	motor[br_drive]=100;
	motor[bl_drive]=100;
	wait(time_length);
	drive_motors_to_zero();
	}


void gripper(bool state)
	{
	if (state==true) //close
		{
		motor[motorA]=100;
		wait(250);
		motor[motorA]=0;
		}

	if (state==false) //open
		{
		motor[motorA]=-100;
		wait(200);
		motor[motorA]=0;
		}
	}


void wrist(int degrees)
	{
	if (nMotorEncoder[motorB]<degrees)
		{
		motor[motorB]=100;
		while(nMotorEncoder[motorB]<degrees) {}
		motor[motorB]=0;
		}
	else
		{
		motor[motorB]=-100;
		while(nMotorEncoder[motorB]>degrees) {}
		motor[motorB]=0;
		}
	}


void lift(int degrees)
	{
	if (nMotorEncoder[l_lift]<degrees)
		{
		motor[l_lift]=100;
		motor[r_lift]=100;
		while(nMotorEncoder[l_lift]<degrees) {}
		motor[l_lift]=0;
		motor[r_lift]=0;
		}
	else
		{
		motor[l_lift]=-100;
		motor[r_lift]=-100;
		while(nMotorEncoder[l_lift]>degrees) {}
		motor[l_lift]=0;
		motor[r_lift]=0;
		}
	}


void turn(int target_degrees)
	{
	target_degrees*=10;
	SensorValue[compass]=0;
	while(SensorValue[compass]>target_degrees+2 || SensorValue[compass]<target_degrees-2)
		{
		motor[fr_drive]=-(target_degrees-SensorValue[compass])*2;
		motor[fl_drive]= (target_degrees-SensorValue[compass])*2;
		motor[br_drive]=-(target_degrees-SensorValue[compass])*2;
		motor[bl_drive]= (target_degrees-SensorValue[compass])*2;
		}
	drive_motors_to_zero();
	}

void reverse(int time_length)
	{
	motor[fr_drive]=-100;
	motor[fl_drive]=-100;
	motor[br_drive]=-100;
	motor[bl_drive]=-100;
	wait(time_length);
	drive_motors_to_zero();
	}


/*
void turn(int target_degrees)
	{
	target_degrees = target_degrees*10;
	if (target_degrees<0) //Left
		{
		motor[fr_drive]=100;
		motor[fl_drive]=-100;
		motor[br_drive]=100;
		motor[bl_drive]=-100;
		while(SensorValue[compass]>target_degrees) {}
		drive_motors_to_zero();

		}
	if (target_degrees>0)
		{
		motor[fr_drive]=-100;
		motor[fl_drive]=100;
		motor[br_drive]=-100;
		motor[bl_drive]=100;
		while(SensorValue[compass]<target_degrees) {}
		drive_motors_to_zero();
		}
	}


void turn_left(int time_length)
	{
	motor[fr_drive]=100;
	motor[fl_drive]=-100;
	motor[br_drive]=100;
	motor[bl_drive]=-100;
	wait(time_length);
	drive_motors_to_zero();
	}


void turn_right(int time_length)
	{
	motor[fr_drive]=-100;
	motor[fl_drive]=100;
	motor[br_drive]=-100;
	motor[bl_drive]=100;
	wait(time_length);
	drive_motors_to_zero();
	}
*/
