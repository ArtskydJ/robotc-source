void initialize(int INinitPoint)
	{
	zeroMotors();
	//--SET VALUES--//
	PIDLineFollow.kp = 0.2;
	PIDLineFollow.ki = 0.00;
	PIDLineFollow.kd = 0.00;

	PIDDriveL.kp = 0.5;
	PIDDriveL.ki = 0.00;
	PIDDriveL.kd = 0.00;

	PIDDriveR.kp = 0.5;
	PIDDriveR.ki = 0.00;
	PIDDriveR.kd = 0.00;

	PIDGyro1.kp = 1.8; //1 wheel
	PIDGyro1.ki = 0.00;
	PIDGyro1.kd = 0.02;

	PIDGyro2.kp = 1.2; //2 wheels
	PIDGyro2.ki = 0.00;
	PIDGyro2.kd = 0.00;
	slewConstants[D_RIGHT]= AUTO_DRV_SLEW;	//AUTONOMOUS
	slewConstants[D_LEFT] = AUTO_DRV_SLEW;

	//--RESET TIMERS--//
	ClearTimer(T1); //Current Autonomous Step
	ClearTimer(T2); //PID wait
	ClearTimer(T3); //Entire Autonomous Time
	ClearTimer(T4); //unassigned

	//--MISCELLANEOUS--//
	writeDebugStreamLine("================");
	setToZero(senEncL);
	setToZero(senEncR);
	senAddToAbsGyro=INinitPoint;
	}
