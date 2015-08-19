///////////////////////////////Global Variables/////////////////////
//Used for calcultaing linevalue
int valuepre1;
//Used for calcultaing linevalue
int valuepre2;
//Difference in value between sensors
//If on line line, 0 = center, negative value = to far left, positive value = to far right
int linevalue = 0;
/////////////////////////////////////////////////////////////////////

////////////////////////////Variables/////////////////////////////////
int lineaverage;
int middlethreshold;
int maxspeed;
int minspeed;
bool lasttask;
//////////////////////////////////////////////////////////////////////


//Drive forward until it finds the line
void findline()
{
	bMotorReflected[port1] = true;
	motor[port1] = 80;
	motor[port2] = 80;
	while(SensorValue[in3] > SensorValue[in5] - 150) {}
}

task followline()
{

	//Check if exact following mode is on
	switch(exact)
	{

		/////////////////////////////Settings/////////////////////////////////
		//Turn exact mode on (more accurate)
	case true:
		//Set how far from middle of line before correcting
		middlethreshold = 1;
		//Set maximum speed to use while turning
		maxspeed = 65;
		//Set minimum speed to use while turning
		minspeed = 50;
		break;

		//Turn exact mode off (slightly faster)
	case false:
		//Set how far from middle of line before correcting
		middlethreshold = 1;
		//Set maximum speed to use while turning
		maxspeed = 80;
		//Set minimum speed to use while turning
		minspeed = 60;
		break;
	}
	///////////////////////////////////////////////////////////////////////

	//Loop while line follower task is active
	while(true)
	{
		//Reflect Motors
		bMotorReflected[port1] = true;

		//Check that at least one line sensor is on line
		lineaverage = (SensorValue(in2) + SensorValue(in3) + SensorValue(in4))/3;
		if (((SensorValue(in2) < lineaverage + 20) && (SensorValue(in2) > lineaverage - 20)) && ((SensorValue(in3) < lineaverage + 20) && (SensorValue(in3) > lineaverage - 20)) && ((SensorValue(in4) < lineaverage + 20) && (SensorValue(in4) > lineaverage - 20)))
		{
			//If no line sensors on line spin the way the robot was turning when it came of the line
			switch(lasttask)
			{

				//Spin Left
			case false:
				motor[port1] = -100;
				motor[port2] = 100;
				break;

				//Spin Right
			case true:
				motor[port1] = 100;
				motor[port2] = -100;
				break;
			}
		}

		//If at least one sensor is on the line
		else
		{
			valuepre1 = SensorValue(in3) - SensorValue(in4);
			valuepre2 = SensorValue(in3) - SensorValue(in2);

			linevalue = valuepre2 - valuepre1;

			//Go Straight
			if (linevalue > -middlethreshold && linevalue < middlethreshold)
			{
				motor[port1] = 127;
				motor[port2] = 127;
			}


			//Turn Right
			if (linevalue < -middlethreshold)
			{

				if (maxspeed + linevalue >= minspeed)
				{
					motor[port2] = maxspeed + linevalue;
				}

				else
				{
					motor[port2] = minspeed;
				}

				motor[port1] = maxspeed;

				//Set the last task to turning right incase it overshoots and all the line sensors come off the line
				lasttask = true;
			}


			//Turn Left
			if (linevalue > middlethreshold)
			{

				if (maxspeed - linevalue >= minspeed)
				{
					motor[port1] = maxspeed - linevalue;
				}

				else
				{
					motor[port1] = minspeed;
				}

				motor[port2] = maxspeed;
				lasttask = false;
			}

		}
	}
}

void findlineturn()
{
	bMotorReflected[port1] = true;
	motor[port1] = -80;
	motor[port2] = 80;

	while(SensorValue[in2] > SensorValue[in4] - 100) {}

}
