int Display()
{
	switch(CurrentMenu)
	{
		case 1:   //Start Autonomous
			CurrentMenu = 0;
			StartTask(autonomous);
			StopTask(usercontrol);
			break;
		case 2:   //Pick Autonomous
		  CurrentMenuItem = AutonomousRoutine;
		  allMotorsOff();
		  do
		  {
		    getInput();
			  PickAutonomous();
			} while (!LockInAutonomous);
			while(nLCDButtons);
			break;
		case 3:
			//StopTask(usercontrol);
			//EnableOutput = 0;
			allMotorsOff();
			MotorTest();
			//EnableOutput = 1;
			CurrentMenu = 0;
			break;
		default:
			DisplayMainMenu();
			break;
	}
	return 0;
}

void DisplayMainMenu()
{
	TotalMenuItems = 7;
	if (DisplayNeedsRefreshing)
	{
		DisplayMenu2("Main Menu", MainMenuStrings[CurrentMenuItem]);
		DisplayNeedsRefreshing = 0;
	}
	DisplayButtonHandling();
	if (IsMenuItemActivated())
	{
		CurrentMenu = CurrentMenuItem + 1;
	}
}

void DisplayMenu2(string MenuTitle, string MenuItem)
{
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDCenteredString(0, MenuTitle);
	displayLCDCenteredString(1, MenuItem);
}

void DisplayButtonHandling()
{
	if (LeftDisplayButton && !LeftDisplayButtonPressed && CurrentMenuItem > 0)
	{
		CurrentMenuItem--;
		DisplayNeedsRefreshing = 1;
	}
	LeftDisplayButtonPressed = LeftDisplayButton;
	if (RightDisplayButton && !RightDisplayButtonPressed && CurrentMenuItem < TotalMenuItems - 1)
	{
		CurrentMenuItem++;
		DisplayNeedsRefreshing = 1;
	}
	RightDisplayButtonPressed = RightDisplayButton;
	if (CenterDisplayButton && !CenterDisplayButtonPressed)
	{
		ActivateMenuItem = 1;
		DisplayNeedsRefreshing = 1;
	}
	CenterDisplayButtonPressed = CenterDisplayButton;
}
