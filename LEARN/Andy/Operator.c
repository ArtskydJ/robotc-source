task usercontrol()
{
#ifdef _SIMULATED
	while (!bSimulatedAutonomousMode)
#else
	while (!bIfiAutonomousMode)
#endif
	{
		getInput();
		processOperator();
		if (EnableOutput)
			doOutput();
	}

}

int processOperator()
{
	//Driver control code here
	int ErrorCode = 0;
	operatorDriveTrain();
	operatorLift();
	operatorIntake();
	Display();
	UpdatePIDControllers();
	return ErrorCode;
}


//--------------------------------------------< Drive-train Code >-----------------------------------------------\\

int operatorDriveTrain()
{
  int ErrorCode;

	//ToggleCheck(btnOldNewDrive, btnOldNewDrivePressed, (int) OldNewDrive);
	ToggleCheck(btnFrontBackDrive, btnFrontBackDrivePressed, (int) FrontBackDrive);

	if (OldNewDrive == PLAIN)
	{
	  if(!(abs(stkDriveX) > JOYSTICKDEADZONE))
	  {
	    stkDriveX = 0;
	  }
	  if(!(abs(stkDriveY) > JOYSTICKDEADZONE))
	  {
	    stkDriveY = 0;
	  }
	  if(!(abs(stkDriveS) > JOYSTICKDEADZONE * 2))
	  {
	    stkDriveS = 0;
	  }
	  /*if((abs(stkDriveY) > JOYSTICKDEADZONE) || (abs(stkDriveX) > JOYSTICKDEADZONE) || (abs(stkDriveS) > JOYSTICKDEADZONE))	//If the Joystick hasn't been pushed far enough
		{*/
			motorLeftFrontDrive = stkDriveY + stkDriveX + stkDriveS;
			motorLeftBackDrive =  stkDriveY + stkDriveX - stkDriveS;
			motorRightFrontDrive = stkDriveY - stkDriveX - stkDriveS;
			motorRightBackDrive =  stkDriveY - stkDriveX + stkDriveS;
		/*}*/
		/*else
		{
			motorLeftFrontDrive = 0;
			motorLeftBackDrive = 0;
			motorRightFrontDrive = 0;
			motorRightBackDrive = 0;
		}*/
	}
	else
	{
		if((abs(stkDriveY) > JOYSTICKDEADZONE) || (abs(stkDriveX) > JOYSTICKDEADZONE))	//If the Joystick has been pushed far enough
		{
		  motorLeftFrontDrive = stkDriveY + stkDriveX;
		  motorLeftBackDrive = stkDriveY + stkDriveX;
		  motorRightFrontDrive = stkDriveY - stkDriveX;
		  motorRightBackDrive = stkDriveY - stkDriveX;
		}
		else
		{
			motorLeftFrontDrive = 0;
			motorLeftBackDrive = 0;
			motorRightFrontDrive = 0;
			motorRightBackDrive = 0;
		}
	}
	RangeCheck(0-MOTORDRIVEMAX, motorLeftFrontDrive, MOTORDRIVEMAX);
	RangeCheck(0-MOTORDRIVEMAX, motorLeftBackDrive, MOTORDRIVEMAX);
	RangeCheck(0-MOTORDRIVEMAX, motorRightFrontDrive, MOTORDRIVEMAX);
	RangeCheck(0-MOTORDRIVEMAX, motorRightBackDrive, MOTORDRIVEMAX);

	return ErrorCode;
}

//------------------------------------Lift Code-------------------------------------//

int operatorLift()
{
  int ErrorCode = 0;
	/*//Direct Lift
	if (btnLiftRestBack1 && btnLiftRestFront1)
	{
		stkLift = 0;
	}
	else if (btnLiftRestBack2 && btnLiftRestFront2)
	{
		stkLift = 0;
	}
	else if (abs(stkLift1) > JOYSTICKDEADZONE)
	{
		stkLift = stkLift1;
	}
	else if (abs(stkLift2) > JOYSTICKDEADZONE)
	{
		stkLift = stkLift2;
	}
	else if (BottomLiftLimitSwitch)
	{
		stkLift = 0;
	}
	else
	{
		stkLift = 10;
	}

	motorLiftLeft = stkLift;
	motorLiftRight = stkLift;*/

	//PID Lift

	//Main Joystick Low Goal Button
	if (btnLiftLowGoal1 && !btnLiftLowGoal1Pressed)
	{
	  if (LastGoalHeightButton1 == LOWGOALBUTTON)
	  {
  	  LastGoalHeightButton1 = NOGOALBUTTON;
  	  LiftTargetHeight = FLOORHEIGHT;
  	}
	  else
	  {
      LastGoalHeightButton1 = LOWGOALBUTTON;
  	  LiftTargetHeight = LOWGOALHEIGHT;
  	}
	  LiftToPresetHeight = 1;
	}
	btnLiftLowGoal1Pressed = btnLiftLowGoal1;

	//Main Joystick Middle Goal Button
	if (btnLiftMiddleGoal1 && !btnLiftMiddleGoal1Pressed)
	{
	  if (LastGoalHeightButton1 == MIDDLEGOALBUTTON)
	  {
  	  LastGoalHeightButton1 = NOGOALBUTTON;
  	  LiftTargetHeight = FLOORHEIGHT;
  	}
	  else
	  {
      LastGoalHeightButton1 = MIDDLEGOALBUTTON;
  	  LiftTargetHeight = MIDDLEGOALHEIGHT;
  	}
	  LiftToPresetHeight = 1;
	}
	btnLiftMiddleGoal1Pressed = btnLiftMiddleGoal1;

	//Main Joystick High Goal Button
	if (btnLiftHighGoal1 && !btnLiftHighGoal1Pressed)
	{
	  if (LastGoalHeightButton1 == HIGHGOALBUTTON)
	  {
  	  LastGoalHeightButton1 = NOGOALBUTTON;
  	  LiftTargetHeight = FLOORHEIGHT;
  	}
	  else
	  {
  	  LastGoalHeightButton1 = HIGHGOALBUTTON;
  	  LiftTargetHeight = HIGHGOALHEIGHT;
  	}
	  LiftToPresetHeight = 1;
	}
	btnLiftHighGoal1Pressed = btnLiftHighGoal1;


	//Second Joystick Low Goal Button
	if (btnLiftLowGoal2 && !btnLiftLowGoal2Pressed)
	{
	  if (LastGoalHeightButton2 == LOWGOALBUTTON)
	  {
  	  LastGoalHeightButton2 = NOGOALBUTTON;
  	  LiftTargetHeight = FLOORHEIGHT;
  	}
	  else
	  {
      LastGoalHeightButton2 = LOWGOALBUTTON;
  	  LiftTargetHeight = LOWGOALHEIGHT;
  	}
	  LiftToPresetHeight = 2;
	}
	btnLiftLowGoal2Pressed = btnLiftLowGoal2;

	//Second Joystick Middle Goal Button
	if (btnLiftMiddleGoal2 && !btnLiftMiddleGoal2Pressed)
	{
	  if (LastGoalHeightButton2 == MIDDLEGOALBUTTON)
	  {
  	  LastGoalHeightButton2 = NOGOALBUTTON;
  	  LiftTargetHeight = FLOORHEIGHT;
  	}
	  else
	  {
      LastGoalHeightButton2 = MIDDLEGOALBUTTON;
  	  LiftTargetHeight = MIDDLEGOALHEIGHT;
  	}
	  LiftToPresetHeight = 2;
	}
	btnLiftMiddleGoal2Pressed = btnLiftMiddleGoal2;

	//Second Joystick High Goal Button
	if (btnLiftHighGoal2 && !btnLiftHighGoal2Pressed)
	{
	  if (LastGoalHeightButton2 == HIGHGOALBUTTON)
	  {
  	  LastGoalHeightButton2 = NOGOALBUTTON;
  	  LiftTargetHeight = FLOORHEIGHT;
  	}
	  else
	  {
  	  LastGoalHeightButton2 = HIGHGOALBUTTON;
  	  LiftTargetHeight = HIGHGOALHEIGHT;
  	}
	  LiftToPresetHeight = 2;
	}
	btnLiftHighGoal2Pressed = btnLiftHighGoal2;

	/*else if (btnLiftMiddleGoal1 && !btnLiftMiddleGoal1Pressed)
	  LiftTargetHeight = MIDDLEGOALHEIGHT;
	else if (btnLiftHighGoal1 && !btnLiftHighGoal1Pressed)
	  LiftTargetHeight = HIGHGOALHEIGHT;
	else if (btnLiftLowGoal2 && !btnLiftLowGoal2Pressed)
	  LiftTargetHeight = LOWGOALHEIGHT;
	else if (btnLiftMiddleGoal2 && !btnLiftMiddleGoal2Pressed)
	  LiftTargetHeight = MIDDLEGOALHEIGHT;
	else if (btnLiftHighGoal2 && !btnLiftHighGoal2Pressed)
	  LiftTargetHeight = HIGHGOALHEIGHT;*/


	PIDLift.Error = RightLiftEncoder - LeftLiftEncoder;

	if (btnLiftEncoderReset1 || btnLiftEncoderReset2)
	{
		SensorValue[LeftLiftEncoderPort] = 0;
		SensorValue[RightLiftEncoderPort] = 0;
	}

  if (abs(stkLift1) > JOYSTICKDEADZONE)
	{
		PIDLift.TargetPower = stkLift1;
	}
	else if (abs(stkLift2) > JOYSTICKDEADZONE)
	{
		PIDLift.TargetPower = stkLift2;
	}
	else if (BottomLeftLiftLimitSwitch && BottomRightLiftLimitSwitch)
	{
	  PIDLift.TargetPower = 0;
		SensorValue[LeftLiftEncoderPort] = 0;
		SensorValue[RightLiftEncoderPort] = 0;
	}
	else			//Joysticks are Centered, the encoder reset buttons and the bottom lift switches are not pressed
	{
		PIDLift.TargetPower = 0;
	}

	//BUTTON LIFT CODE
	if(btnLiftTopUp2)
	{
	  LiftUp = UP;
	}
	else if(btnLiftTopDown2)
	{
	  LiftUp = DOWN;
	}
	else
	{
	  LiftUp = 0;
	}

  if(btnLiftBottomUp2)
	{
	  LiftDown = UP;
	}
	else if(btnLiftBottomDown2)
	{
	  LiftDown = DOWN;
	}
	else
	{
		LiftDown = 0;
	}

  if (LiftUp == 0 && LiftDown == 0)
    LiftButtonsAreControlling = 0;
  else
    LiftButtonsAreControlling = 1;

	//motorLiftLeft = PIDLift.TargetPower + PIDLift.Output;
	//motorLiftRight = PIDLift.TargetPower - PIDLift.Output;
	if (LiftButtonsAreControlling)
	{
		motorLiftLeftTop = motorLiftRightTop = LiftUp;
		motorLiftLeftBottom = motorLiftRightBottom = LiftDown;
	}
	else
	{
		motorLiftLeftTop = motorLiftRightTop = PIDLift.TargetPower;
		motorLiftLeftBottom = motorLiftRightBottom = PIDLift.TargetPower;
	}
	/*if ((PIDLift.TargetPower + PIDLift.Output) < 0)   //If Left Lift is going down, slow it down
	{
		motorLiftLeft = (PIDLift.TargetPower + PIDLift.Output)*.5;  //.75
	}
	if ((PIDLift.TargetPower - PIDLift.Output) < 0)   //If Right Lift is going down, slow it down
	{
		motorLiftRight = (PIDLift.TargetPower + PIDLift.Output)*.5;  //.75
	}*/

	return ErrorCode;
}

//------------------------------------Intake Code-------------------------------------//

int operatorIntake()
{
  int ErrorCode = 0;
  	if(btnIntakeIn1 == 1)
    {
      motorIntakeFront = 127;
      motorIntakeBack = 127;
    }
    else if(btnIntakeOut1 == 1)
    {
	  motorIntakeFront = -127;
      motorIntakeBack = -127;
   }
    else if(btnIntakeIn2 == 1)
    {
      motorIntakeFront = 127;
      motorIntakeBack = 127;
    }
    else if(btnIntakeOut2 == 1)
    {
      motorIntakeFront = -127;
      motorIntakeBack = -127;
    }
    else
    {
      motorIntakeFront = 0;
      motorIntakeBack = 0;
    }
  return ErrorCode;
}
