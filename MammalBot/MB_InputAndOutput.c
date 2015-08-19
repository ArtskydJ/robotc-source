void input()
	{
	//--Robot Sensors--//
	senTouch.curr =		SensorValue[TOUCH];
	senGyro.curr =		SensorValue[COMPASS]%3600;
	senLight.curr =		SensorValue[LIGHT];
	senUS.curr =		SensorValue[ULTRA];
	senEncL.curr =		-nMotorEncoder[D_LEFT];
	senEncR.curr =		nMotorEncoder[D_RIGHT];

	if (autoClockRunning)
		autoTimer = time1(T3);

	if (senGyro.last>3400 && senGyro.curr<200) senAddToAbsGyro+=3600;
	if (senGyro.last<200 && senGyro.curr>3400) senAddToAbsGyro-=3600;
	senAbsGyro.curr = senAddToAbsGyro + senGyro.curr;
	}

////////////////////////////// I/O //////////////////////////////

void output()
	{
	mtrTarget[D_LEFT]  = outDrvL;
	mtrTarget[D_RIGHT] = outDrvR;

	for (int j=0; j<3; j++)
		{
#ifdef SLEW
		mtrSlewed[j] += slew(mtrTarget[j], mtrSlewed[j], slewConstants[j]); //SLEW CONTROLLERS
#endif
		capValue(-100, mtrSlewed[j], 100); //CAP ALL MOTORS
		motor[j] = mtrSlewed[j]; //ASSIGN MOTORS
		}
	string temp1,temp2;
	StringFormat(temp1,"Time:%.1f",((float)autoTimer/1000));
	StringFormat(temp2, "Step: %d", autoStep);	//Show step
	nxtDisplayCenteredTextLine(0,temp1);
	nxtDisplayCenteredTextLine(1,temp2);
	}
