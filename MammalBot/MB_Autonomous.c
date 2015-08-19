void autoReset(int INcurrentStep)
	{
	zeroMotors();
	if (INcurrentStep == 0) //Runs at start of Autonomous
		{
		ClearTimer(T1);
		ClearTimer(T3);
		autoTimer=0;
		autoClockRunning = true;
		autoStep = 0;
		setToZero(senEncL);
		setToZero(senEncR);
		}
	else //Runs at end of Autonomous
		{
		writeDebugStreamLine("----------------");
		writeDebugStreamLine("Time: %.1f",((float)autoTimer/1000));
		writeDebugStreamLine("----------------");
		autoClockRunning = false;
		setToZero(senEncL);
		setToZero(senEncR);
		}
	}


void auto(int INdrvType, long INdrvLft, long INdrvRht, int INdelayPID)
	{

	//Next Step...
	string msg1;
	if (autoStep < NO_TIME_RECORDS)
		autoTimeRecord[autoStep] = time1(T1);
	if (time1(T1)<1000)
		writeDebugStreamLine("%d\t\t|%d",time1(T1),autoStep);
	else
		writeDebugStreamLine("%d\t|%d",time1(T1),autoStep);
	autoClockRunning=true;
	autoDriveReady = false;
	autoHitTarget = NOT_HIT;
	autoStep++;
	nMotorEncoder[D_LEFT]=0;
	nMotorEncoder[D_RIGHT]=0;
	setToZero(senEncL);
	setToZero(senEncR);

	//--Step start values--//
	setStep(senGyro);
	setStep(senAbsGyro);
	setStep(senEncL);
	setStep(senEncR);
	ClearTimer(T1);


	while(autoHitTarget!=NEXT)
		{
		input();

		if (INdrvType!=SPD && INdrvType!=FLINE) //INdelayPID is used as time limit in SPD and FLINE
			{
			if (INdelayPID<NEXT) INdelayPID=NEXT;
			if (INdelayPID>PID)  INdelayPID=PID;
			}

		/* Drive Outputs */
		outDrvL = 0;
		outDrvR = 0;
		switch (INdrvType)
			{
			case SPD:
				outDrvL = INdrvLft;
				outDrvR = INdrvRht;
				if (time1(T1)>INdelayPID) autoHitTarget=NEXT;
				break;
			case ENC:
				updatePIDController(PIDDriveL,INdrvLft - diffStep(senEncL));
				updatePIDController(PIDDriveR,INdrvRht - diffStep(senEncR));
				outDrvL = PIDDriveL.output;
				outDrvR = PIDDriveR.output;
				if (abs(PIDDriveL.error)<PID_ZONE && abs(PIDDriveR.error)<PID_ZONE) autoHitTarget=INdelayPID;
				break;
			case STR:											//Gyro keep straight
				updatePIDController(PIDGyro2, INdrvLft-senAbsGyro.curr);
				updatePIDController(PIDDriveL,INdrvRht - (diffStep(senEncL) + diffStep(senEncR))/2 );
				outDrvL = PIDDriveL.output;		//Left
				capValue(-TURN,outDrvL,TURN);
				outDrvL+=PIDGyro2.output;
				outDrvR = PIDDriveL.output;		//Right
				capValue(-TURN,outDrvR,TURN);
				outDrvR-=PIDGyro2.output;
				if (abs(PIDDriveL.error) < PID_ZONE && abs(PIDDriveR.error) < PID_ZONE) autoHitTarget=INdelayPID;
				break;
			case FLINE:											//Follow Line
				updatePIDController(PIDLineFollow,senLight.curr-LINE);
				outDrvL = INdrvLft - PIDLineFollow.output;
				outDrvR = INdrvLft + PIDLineFollow.output;
				if (time1(T1)>INdelayPID) autoHitTarget=NEXT;
				break;
			case CMP_2:											//Gyro turn both
				updatePIDController(PIDGyro2, INdrvLft-diffStep(senGyro));
				outDrvL =  PIDGyro2.output; capValue(-abs(INdrvRht),outDrvL,abs(INdrvRht));
				outDrvR = -PIDGyro2.output; capValue(-abs(INdrvRht),outDrvL,abs(INdrvRht));
				if (abs(PIDGyro2.error) < PID_ZONE) autoHitTarget=INdelayPID;
				break;
			case CMP_L:											//Gyro turn left - GOOD
				updatePIDController(PIDGyro1, INdrvLft-diffStep(senAbsGyro));
				outDrvL = PIDGyro1.output; capValue(-abs(INdrvRht),outDrvR,abs(INdrvRht));
				outDrvR = 0;
				if (abs(PIDGyro1.error) < PID_ZONE) autoHitTarget=INdelayPID;
				break;
			case CMP_R:											//Gyro turn right - GOOD
				updatePIDController(PIDGyro1, -INdrvLft+diffStep(senAbsGyro));
				outDrvL = 0;
				outDrvR = PIDGyro1.output; capValue(-abs(INdrvRht),outDrvR,abs(INdrvRht));
				if (abs(PIDGyro1.error) < PID_ZONE) autoHitTarget=INdelayPID;
				break;
			}

		if (autoHitTarget==PID && time1(T2)>=PID_WAIT_MS)	autoHitTarget=NEXT; //PID timeout

		output();

		//--Sensors--//
		setLast(senGyro);
		setLast(senAbsGyro);
		setLast(senEncL);
		setLast(senEncR);

		//--Constant Loop Time--//
		sysLooptime=time1(T4);
		while (time1(T4) < MIN_LOOP_MS) {}
		ClearTimer(T4);
		}
	}
