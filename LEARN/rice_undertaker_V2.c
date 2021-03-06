#pragma config(Sensor, in1,    armPot,              sensorPotentiometer)
#pragma config(Sensor, in5,    AutoWheel,           sensorPotentiometer)
#pragma config(Sensor, in7,    leftLine,            sensorLineFollower)
#pragma config(Sensor, in8,    centerLine,          sensorLineFollower)
#pragma config(Sensor, in9,    rightLine,           sensorLineFollower)
#pragma config(Sensor, in11,   runLED,              sensorDigitalOut)
#pragma config(Sensor, in13,   sideSwitch,          sensorTouch)
#pragma config(Sensor, in14,   armLimit,            sensorTouch)
#pragma config(Sensor, in15,   leftEnc,             sensorQuadEncoder, int5)
#pragma config(Sensor, in16,   rightEnc,            sensorQuadEncoder, int6)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//CODE written by Rice Robotics Club - (Andrew Lynch) - 2009

//Defines the platform this code will be functional for.
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)/autonomousTest, Competition (the main mode)
#pragma autonomousDuration(60) //20 for VEX Competition. 60 for Autonomous Challenge.
#pragma userControlDuration(120)

#define FORWARD 1
#define BACKWARD 0
#define RAISE 1
#define LOWER 0
#define RIGHT 1  //right for the robot perspective
#define LEFT 0

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
//#include "rice_nav.c"
void drive(int distance, char direction, char power);
void arm(int position, char direction, char power);
void turn(int position, char direction, char power);

//All tasks that occur before the competition starts
//Example: clearing encoders, setting motor reflectives, setting servo positions
void pre_auton()
{
	bMotorReflected[port7]= true;//port reflected for collector
	bMotorReflected[port3]= true; //port2 reflected for drive system
	bMotorReflected[port6]= true; //port reflected for arm
	SensorValue[rightEnc]=0;  SensorValue[leftEnc]=0;  // clear encoders
}


task autonomous()
{
	if(SensorValue(AutoWheel) < 200)  //RED RED RED SIDE Dump & collect
	{
		arm(350,RAISE,127); //Raise ARM to 350 at max power (127)
		drive(40,FORWARD,90); //drive 40 clicks, 90 power, and forward
		// conveyor belt out
		motor[port5]=-35;    motor[port6]=-35; wait1Msec(4500);
		motor[port5]=0;      motor[port6]=0;   wait1Msec(20);
		drive(105,BACKWARD,90); //drive backward 105 clicks & 90 power
		turn(580,LEFT,124);//turn LEFT 580 clicks att 124 power
		arm(650,LOWER,127); //Lower ARM to 650 at max power (127)
		// conveyor belt in
		motor[port5]=127;    motor[port6]=127; //no time delay
		drive(350,FORWARD,50); //drive forward for 1st cube collect
		wait1Msec(3000); //wait 3 seconds for collector to load cube
		drive(55,FORWARD,50); //drive forward for 2nd cube collect
		wait1Msec(3000); //wait 3 seconds for collector to load cube
		arm(500,RAISE,127); //Raise ARM to middle position at max power (127)
		wait1Msec(500);
		drive(105,BACKWARD,90); //drive backward 105 clicks & 90 power
		wait1Msec(500);
		arm(650,LOWER,127); //Lower ARM to 650 at max power (127)
		wait1Msec(500);
		//ANTI JAM RED RED RED
		motor[port5]=-80;    motor[port6]=-80; //no time delay
		wait1Msec(500);
		motor[port5]=127;    motor[port6]=127; //no time delay
		drive(900,FORWARD,50); //drive forward for 3rd cube collect
		wait1Msec(3000); //wait 3 seconds for collector to load cube
		motor[port5]=0;      motor[port6]=0;   wait1Msec(20);   // stops collector
	} // end of RED IF
	if(SensorValue(AutoWheel) > 800)    //BLUE SIDE Dump & Collect
	{
		arm(350,RAISE,127); //Raise ARM to 350 at max power (127)
		drive(40,FORWARD,90); //drive 40 clicks, 90 power, and forward
		motor[port5]=-35;    motor[port6]=-35; wait1Msec(4500); // collector spit out
		motor[port5]=0;      motor[port6]=0;   wait1Msec(20);
		drive(105,BACKWARD,90); //drive backward 105 clicks & 90 power
		turn(610,RIGHT,124);//turn RIGHT 610 clicks att 124 power
		arm(650,LOWER,127); //Lower ARM to 650 at max power (127)
		// conveyor belt in
		motor[port5]=127;    motor[port6]=127; //no time delay
		drive(350,FORWARD,50); //drive forward for 1st cube collect
		wait1Msec(3000); //wait 3 seconds for collector to load cube
		drive(55,FORWARD,50); //drive forward for 2nd cube collect
		wait1Msec(3000); //wait 3 seconds for collector to load cube
		arm(500,RAISE,127); //Raise ARM to middle position at max power (127)
		wait1Msec(500);
		drive(105,BACKWARD,90); //drive backward 105 clicks & 90 power
		wait1Msec(500);
		arm(650,LOWER,127); //Lower ARM to 650 at max power (127)
		wait1Msec(500);
		//ANTI JAM RED RED RED
		motor[port5]=-80;    motor[port6]=-80; //no time delay
		wait1Msec(500);
		motor[port5]=127;    motor[port6]=127; //no time delay
		drive(900,FORWARD,50); //drive forward for 3rd cube collect
		wait1Msec(3000); //wait 3 seconds for collector to load cube
		motor[port5]=0;      motor[port6]=0;   wait1Msec(20);   // stops collector
	}//end of BLUE IF
	if(SensorValue(AutoWheel) < 800 && SensorValue(AutoWheel) > 200)    //COLLECT
	{
		motor[port5]=127;      motor[port6]=127;   wait1Msec(500);
		drive(150,FORWARD,50); //collect 1st cube
		wait1Msec(3000);
		drive(50,FORWARD,50); //collect 2nd cube
		wait1Msec(3000);
		drive(200,FORWARD,90); //collect 3rd cube and keep moving
		wait1Msec(3000);
		// stops belts
		motor[port5]=0;      motor[port6]=0;   wait1Msec(20);
		arm(561,RAISE,127); //Raise ARM to middle position at max power (127)
		drive(150,FORWARD,90); //move until near 3 high goal
		wait1Msec(500);
		motor[port2]=80;      motor[port3]=80;   wait1Msec(3000);//timed run into wall
		motor[port2]=0;      motor[port3]=0;   wait1Msec(800);
		motor[port2]=30;      motor[port3]=80;   wait1Msec(2000);//timed turn
		// conveyor belt out
		drive(25,BACKWARD,90); //drive backwards slightly
		motor[port5]=-39;    motor[port6]=-39; wait1Msec(3000); //dump 3 cubes
		motor[port5]=0;      motor[port6]=0;   wait1Msec(20);
	}// END OF COLLECT & dump ELSE
}


task usercontrol()
{
//User control code here, inside the loop
//int ArmPower = 0;
	while(true)
	{
		motor[port3] = vexRT(Ch3); //Left Side Wheel
		motor[port2] = vexRT(Ch2); //Right Side Wheel
		motor[port5] = vexRT(Ch5); // Belt
		motor[port6] = vexRT(Ch5); // Belt
		if(SensorValue[armPot] > 730)// arm down
		{  //Code segment runs if the armLimit if not pressed
			motor[port7] = vexRT(Ch6)/2; // left arm
			motor[port8] = vexRT(Ch6)/2; // right arm
		}
		else
		{
			motor[port7] = vexRT(Ch6); // left arm
			motor[port8] = vexRT(Ch6); // right arm
		}
		motor[port1] = vexRT(Ch4); //undertaker left belt
		motor[port4] = vexRT(Ch1); // undertaker right belt
	}
}


void turn(int position, char direction, char power)
{
	SensorValue[rightEnc]=0;  SensorValue[leftEnc]=0;   // clear encoders
	if(direction == LEFT)
	{
		while(SensorValue[rightEnc] < position && SensorValue[leftEnc] > -position)
		{ //Turns Left 210 degrees RED RED RED
			motor[port2]=power;    motor[port3]=-power;
		}
	}//end of LEFT turn
	else
	{
		while(SensorValue[rightEnc] > -position && SensorValue[leftEnc] < position)
		{
			motor[port2]=-power;    motor[port3]=power;
		}     //stop
	} //end of RIGHT turn
	motor[port2]=0;  	  motor[port3]=0;  wait1Msec(20); //stop turning
}


void arm(int position, char direction, char power)
{
	if(direction == RAISE)
	{
		while(SensorValue[armPot] > position)// arm up for high goal
		{  //747 is fully down , 400 is fully extended for 5 goal
			motor[port7]=power;    motor[port8]=power;
		}
	}//end of RAISE
	else //LOWER
	{
		while(SensorValue[armPot] < position)// arm down
		{ //Arm Down
			motor[port7]=-power;   motor[port8]=-power;
		}
	}
	motor[port7]=0;      motor[port8]=0;   wait1Msec(20);//stop arm
}


void drive(int distance, char direction, char power)
{
	SensorValue[rightEnc]=0;  SensorValue[leftEnc]=0;  // clear encoders
	if(direction == FORWARD)//forward move
	{
		while(SensorValue[rightEnc] < distance && SensorValue[leftEnc] < distance)
		{
			motor[port2]=power;  	  	motor[port3]=power;//move motors at power
		}
	}//end of forward move
	else //backward move
	{
		while(SensorValue[rightEnc] > -distance && SensorValue[leftEnc] > -distance)
		{
		motor[port2]=-power;  	  	motor[port3]=-power;
		}
	}//end of backward move
	motor[port2]=0;      motor[port3]=0;   wait1Msec(20);//turn motors off
}
