int UpdatePIDControllers()
{
	PIDController(PIDLift);
	return 1;
}

int PickAutonomous()
{
	LockInAutonomous = 0;
	TotalMenuItems = 3;
		if (DisplayNeedsRefreshing)
		{
			DisplayMenu2("Pick Autonomous", AutonomousMenu[CurrentMenuItem]);
			DisplayNeedsRefreshing = 0;
		}
		DisplayButtonHandling();
		if (IsMenuItemActivated())
		{
			AutonomousRoutine = CurrentMenuItem;
			CurrentMenuItem = 0;
			CurrentMenu = 0;
			LockInAutonomous = 1;
		}
	return 0;
}


int IsMenuItemActivated() //This function makes sure that the activate action happens only when it is supposed to
{
	int Dummy = ActivateMenuItem;
	ActivateMenuItem = 0;
	return Dummy;
}

int CheckJoystick()
{
	//Are the joystick tests
	if (abs(vexRT[Ch1]) > JOYSTICKDEADZONE || abs(vexRT[Ch2]) > JOYSTICKDEADZONE || abs(vexRT[Ch3]) > JOYSTICKDEADZONE || abs(vexRT[Ch4]) > JOYSTICKDEADZONE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ToggleCheck (int CurrentButtonState, int &WasAlreadyPressed, int &ToBeToggled)
{
	if (CurrentButtonState && !WasAlreadyPressed)
	{
		ToBeToggled = !ToBeToggled;			//If Old Drive, switch to New Drive. If New Drive, switch to Old Drive
	}
	WasAlreadyPressed = CurrentButtonState;
}

void RangeCheck (int LowerLimit, int &Value, int UpperLimit)
{
	if (Value > UpperLimit)
	{
		Value = UpperLimit;
	}
	if (Value < LowerLimit)
	{
		Value = LowerLimit;
	}
}

void PIDController(TPidSystem &PIDObject)
{
	PIDObject.Integral = ((3 / 4) * PIDObject.Integral) + PIDObject.Error;
	PIDObject.Derivative = PIDObject.Error - PIDObject.LastError;
	PIDObject.Output = (PIDObject.Error * PIDObject.Kp) + (PIDObject.Integral * PIDObject.Ki) + (PIDObject.Derivative * PIDObject.Kd);
	PIDObject.LastError = PIDObject.Error;
}

int WasPressedOnce(int CurrentButtonState, int &WasAlreadyPressed)
{
  int Pressed = 0;
	if (CurrentButtonState && !WasAlreadyPressed)
		Pressed = 1;
	WasAlreadyPressed = CurrentButtonState;
	return Pressed;
}

void MotorTest()
{
	int MotorNumber1 = 4;
	int ButtonBitMap = nLCDButtons;
	int LeftDisplayButton1;
	int CenterDisplayButton1 = 0;
	int RightDisplayButton1;
	int LeftJoystickButton1;
	int RightJoystickButton1;
	int LeftDisplayButton2;
	int RightDisplayButton2;
	int LeftJoystickButton2;
	int RightJoystickButton2;
	int LeftDisplayButtonPressed1;
	int RightDisplayButtonPressed1;
	int LeftJoystickButtonPressed1;
	int RightJoystickButtonPressed1;
	int LeftDisplayButtonPressed2;
	int RightDisplayButtonPressed2;
	int LeftJoystickButtonPressed2;
	int RightJoystickButtonPressed2;
	displayLCDString(0, 0, "Motor           ");
	displayLCDNumber(1, 0, MotorNumber1);
	while (!CheckJoystick())
	{
		ButtonBitMap = nLCDButtons;
		LeftDisplayButton1 = (ButtonBitMap & 1) && 1;
		CenterDisplayButton1 = (ButtonBitMap & 2) && 1;
		RightDisplayButton1 = (ButtonBitMap & 4) && 1;
		LeftJoystickButton1 = vexRT[Btn8L];
		RightJoystickButton1 = vexRT[Btn8R];

		if ((WasPressedOnce(LeftJoystickButton1, LeftJoystickButtonPressed1) || WasPressedOnce(LeftDisplayButton1, LeftDisplayButtonPressed1)) && MotorNumber1 > 1)
		{
			MotorNumber1--;
			clearLCDLine(1);
			displayLCDNumber(1, 0, MotorNumber1);
		}
		if ((WasPressedOnce(RightJoystickButton1, RightJoystickButtonPressed1) || WasPressedOnce(RightDisplayButton1, RightDisplayButtonPressed1)) && MotorNumber1 < 10)
		{
			MotorNumber1++;
			clearLCDLine(1);
			displayLCDNumber(1, 0, MotorNumber1);
		}
		if (vexRT[Btn5U])
			motor[MotorNumber1 - 1] = 127;
		else if (vexRT[Btn5D])
			motor[MotorNumber1 - 1] = -127;
		else
			motor[MotorNumber1 - 1] = 0;
	}
}
