void pre_auton()
{
	initializeTimers();
	initializeDisplay();
	initializePID();
	//initializeGyro(); 							//Uncomment when we start using Gyro Sensor
	initializeAutonomous();
#ifdef _SIMULATED
	while (bSimulatedRobotDisabled)
#else
	while (bIfiRobotDisabled)						//Keep letting Autonomous be selected while robot is disabled
#endif
  {
    getInput();
		if (!LockInAutonomous)
		{
		  PickAutonomous();
		}
  }
	AutonomousRoutine = CurrentMenuItem;
	CurrentMenuItem = 0;
	CurrentMenu = 0;
	DisplayNeedsRefreshing = 1;
}
