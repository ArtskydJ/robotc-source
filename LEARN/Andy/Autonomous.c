task autonomous()
{
	AutonomousStep = 0;
	while (true)
	{
		getInput();
		processAutonomous();
		doOutput();
	}
}

int processAutonomous()
{
	int ErrorCode = 0;
	int StartGyro = 0;
	int WillJump = 0;

	if (ReadyForNextAutonomousStep)
	{
		if (AutonomousRoutine == 0)			//LoadScoreReturn
		{
			//CurrentStep = AutonomousLoadScoreReturn[AutonomousStep]; //This doesn't work in ROBOTC
			memcpy(CurrentStep, AutonomousLoadScoreReturn[AutonomousStep], sizeof(CurrentStep)); //This does
		}
		else if (AutonomousRoutine == 1)	//ObjectScorer
		{
			memcpy(CurrentStep, AutonomousObjectScorer[AutonomousStep], sizeof(CurrentStep)); //This does
		}
		else								//No Autonomous
		{
			CurrentStep.Timeout = -1;
			CurrentStep.StepName = "Preparing to PWN";
		}
		displayLCDNumber(0, 14, AutonomousStep, 1); //Debug line; implement in future
	  displayLCDString(1, 0, "                ");
	  displayLCDString(1, 0, CurrentStep.StepName);

		if (CurrentStep.LiftPower != 0 && CurrentStep.LiftPower >= -127 && CurrentStep.LiftPower <= 127)
		{
			motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = CurrentStep.LiftPower;
		}
		else if (CurrentStep.LiftPower == 128)
		{
			motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = 0;
		}
		if (CurrentStep.IntakePower  != 0 && CurrentStep.IntakePower >= -127 && CurrentStep.IntakePower <= 127)
		{
			motorIntakeBack = motorIntakeFront = CurrentStep.IntakePower;
		}
		else if (CurrentStep.IntakePower == 128)
		{
			motorIntakeBack = motorIntakeFront = 0;
		}
		if (CurrentStep.DriveType == STRAIGHT)
		{
			motorLeftFrontDrive = CurrentStep.DrivePower;
			motorLeftBackDrive = CurrentStep.DrivePower;
			motorRightFrontDrive = CurrentStep.DrivePower;
			motorRightBackDrive = CurrentStep.DrivePower;
		}
		else if (CurrentStep.DriveType == LEFTONEWHEELTURN)
		{
			motorLeftFrontDrive = 0;
			motorLeftBackDrive = 0;
			motorRightFrontDrive = CurrentStep.DrivePower;
			motorRightBackDrive = CurrentStep.DrivePower;

		}
		else if (CurrentStep.DriveType == RIGHTONEWHEELTURN)
		{
			motorLeftFrontDrive = CurrentStep.DrivePower;
			motorLeftBackDrive = CurrentStep.DrivePower;
			motorRightFrontDrive = 0;
			motorRightBackDrive = 0;
		}
		else if (CurrentStep.DriveType == BOTHWHEELTURN)
		{
			motorLeftFrontDrive = CurrentStep.DrivePower;
			motorLeftBackDrive = CurrentStep.DrivePower;
			motorRightFrontDrive = 0 - CurrentStep.DrivePower;
			motorRightBackDrive = 0 - CurrentStep.DrivePower;
		}
		ReadyForNextAutonomousStep = 0;
		ClearTimer(T2);
		StartGyro = gyrGyroscope;
	}
	if (CurrentStep.Timeout != -1)			//If the trip statement isn't met
	{
		if (CurrentStep.Timeout != 0 && ((time1[T2]) >= CurrentStep.Timeout))
			ReadyForNextAutonomousStep = 1;
		if (CurrentStep.GyroDegrees != 0 && (gyrGyroscope - StartGyro >= CurrentStep.GyroDegrees))
			ReadyForNextAutonomousStep = 1;
		if (CurrentStep.EncoderTicks != 0 && (RightDriveEncoder >= CurrentStep.EncoderTicks))
			ReadyForNextAutonomousStep = 1;
	  if (CurrentStep.Timeout == 0)
	    ReadyForNextAutonomousStep = 1;
  }
  else
	{
		motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = 0;
		motorIntakeBack = motorIntakeFront = 0;
		motorLeftFrontDrive = 0;
		motorLeftBackDrive = 0;
		motorRightFrontDrive = 0;
		motorRightBackDrive = 0;
	}
	if (CheckJoystick())
	{
		StartTask(usercontrol);
		StopTask(autonomous);
	}

	if (ReadyForNextAutonomousStep)
  {
    if (CurrentStep.JumpToStep != 0)
    {
      if (CurrentStep.JumpCondition == 0)
        WillJump = 1;
      else if ((CurrentStep.JumpCondition >= 8) && CurrentStep.JumpCondition <= 19)
      {
        if (SensorValue[CurrentStep.JumpCondition])
          WillJump = 1;
      }
      else if(CurrentStep.JumpCondition == LEFTDISPLAYBUTTON && LeftDisplayButton)
        WillJump = 1;
      else if(CurrentStep.JumpCondition == CENTERDISPLAYBUTTON && CenterDisplayButton)
        WillJump = 1;
      else if(CurrentStep.JumpCondition == RIGHTDISPLAYBUTTON && RightDisplayButton)
        WillJump = 1;
      else if((CurrentStep.JumpCondition == ANYDISPLAYBUTTON) && (LeftDisplayButton || CenterDisplayButton || RightDisplayButton))
	    {
	      writeDebugStreamLine("Hi");
	      WillJump = 1;
	    }
	  }
	  if (WillJump)
	  {
      if (CurrentStep.JumpToStep == -1)
		  	AutonomousStep = 0;
		  else
		    AutonomousStep = CurrentStep.JumpToStep;
		}
		else
		{
			AutonomousStep++;
	  }
	}
	return ErrorCode;
}