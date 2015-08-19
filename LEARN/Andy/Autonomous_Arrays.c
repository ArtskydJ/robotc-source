int initializeAutonomous()
{
	// *** LoadScoreReturn ***
	AutonomousLoadScoreReturn[0].StepName = "Raise Lift";
	AutonomousLoadScoreReturn[0].LiftPower = UP;		//Lift Up
	AutonomousLoadScoreReturn[0].Timeout = 4000;

	//Repeat starting here
	AutonomousLoadScoreReturn[1].StepName = "DriveToGoal+Lift";
	AutonomousLoadScoreReturn[1].DriveType = STRAIGHT;	//Drive toward Goal and Lift
	AutonomousLoadScoreReturn[1].DrivePower = FORWARD;
	//AutonomousLoadScoreReturn[1].			//Add encoder stuff here
	AutonomousLoadScoreReturn[1].Timeout = 1700;

	AutonomousLoadScoreReturn[2].StepName = "WaitForStableBot";
	AutonomousLoadScoreReturn[2].LiftPower = 20;		//Stop the lift, and stablalize robot.
	AutonomousLoadScoreReturn[2].Timeout = 250;

	AutonomousLoadScoreReturn[3].StepName = "Release Elements";
	AutonomousLoadScoreReturn[3].IntakePower = OUT;	//Release the Barrels!
	AutonomousLoadScoreReturn[3].Timeout = 3000;

	AutonomousLoadScoreReturn[4].StepName = "StopIntake+Pause";
	AutonomousLoadScoreReturn[4].IntakePower = STOP;
	AutonomousLoadScoreReturn[4].Timeout = 250; //250
	AutonomousLoadScoreReturn[4].JumpCondition = dgtl12;
	AutonomousLoadScoreReturn[4].JumpToStep = 6;

	AutonomousLoadScoreReturn[5].StepName = "Blue (Turn Left)";
	AutonomousLoadScoreReturn[5].DriveType = LEFTONEWHEELTURN;
	AutonomousLoadScoreReturn[5].DrivePower = BACKWARD;
	AutonomousLoadScoreReturn[5].Timeout = 250; //250
	AutonomousLoadScoreReturn[5].JumpToStep = 7;

	AutonomousLoadScoreReturn[6].StepName = "Red (Turn Right)";
	AutonomousLoadScoreReturn[6].DriveType = RIGHTONEWHEELTURN;
	AutonomousLoadScoreReturn[6].DrivePower = BACKWARD;
	AutonomousLoadScoreReturn[6].Timeout = 250; //250

	AutonomousLoadScoreReturn[7].StepName = "BackToStartTile";
	AutonomousLoadScoreReturn[7].DriveType = STRAIGHT;	//Drive toward Goal and Lift
	AutonomousLoadScoreReturn[7].DrivePower = BACKWARD;
	AutonomousLoadScoreReturn[7].Timeout = 1800;

	AutonomousLoadScoreReturn[8].StepName = "HitABtnToGoAgain";
	AutonomousLoadScoreReturn[8].JumpCondition = ANYDISPLAYBUTTON;
	AutonomousLoadScoreReturn[8].JumpToStep = 1;
	AutonomousLoadScoreReturn[8].Timeout = 0;

	AutonomousLoadScoreReturn[9].StepName = "HitABtnToGoAgain";
	AutonomousLoadScoreReturn[9].JumpToStep = 8;
	AutonomousLoadScoreReturn[9].Timeout = 0;

	AutonomousLoadScoreReturn[10].StepName = "Finished!";
	AutonomousLoadScoreReturn[10].Timeout = -1;

	// *** ObjectScorer ***
	AutonomousObjectScorer[0].StepName = "Raise Lift";
	AutonomousObjectScorer[0].LiftPower = UP;		//Lift Up
	AutonomousObjectScorer[0].Timeout = 4000;

	//Repeat starting here
	AutonomousObjectScorer[1].StepName = "DriveToGoal+Lift";
	AutonomousObjectScorer[1].DriveType = STRAIGHT;	//Drive toward Goal and Lift
	AutonomousObjectScorer[1].DrivePower = FORWARD;
	//AutonomousObjectScorer[1].			//Add encoder stuff here
	AutonomousObjectScorer[1].Timeout = 1700;

	AutonomousObjectScorer[2].StepName = "WaitForStableBot";
	AutonomousObjectScorer[2].LiftPower = 20;		//Stop the lift, and stablalize robot.
	AutonomousObjectScorer[2].Timeout = 250;

	AutonomousObjectScorer[3].StepName = "Release Elements";
	AutonomousObjectScorer[3].IntakePower = OUT;	//Release the Barrels!
	AutonomousObjectScorer[3].Timeout = 3000;

	AutonomousObjectScorer[4].StepName = "StopIntake+Pause";
	AutonomousObjectScorer[4].IntakePower = STOP;
	AutonomousObjectScorer[4].Timeout = 250; //250
	AutonomousObjectScorer[4].JumpCondition = dgtl12;
	AutonomousObjectScorer[4].JumpToStep = 6;

	AutonomousObjectScorer[5].StepName = "Blue (Turn Left)";
	AutonomousObjectScorer[5].DriveType = LEFTONEWHEELTURN;
	AutonomousObjectScorer[5].DrivePower = BACKWARD;
	AutonomousObjectScorer[5].Timeout = 250; //250
	AutonomousObjectScorer[5].JumpToStep = 7;

	AutonomousObjectScorer[6].StepName = "Red (Turn Right)";
	AutonomousObjectScorer[6].DriveType = RIGHTONEWHEELTURN;
	AutonomousObjectScorer[6].DrivePower = BACKWARD;
	AutonomousObjectScorer[6].Timeout = 250; //250

	AutonomousObjectScorer[7].StepName = "BackToStartTile";
	AutonomousObjectScorer[7].DriveType = STRAIGHT;	//Drive toward Goal and Lift
	AutonomousObjectScorer[7].DrivePower = BACKWARD;
	AutonomousObjectScorer[7].Timeout = 1800;

	AutonomousObjectScorer[8].StepName = "Lo(HitSideBtn)Hi";
	AutonomousObjectScorer[8].JumpCondition = LEFTDISPLAYBUTTON;
	AutonomousObjectScorer[8].JumpToStep = 11;
	AutonomousObjectScorer[8].Timeout = 0;

	AutonomousObjectScorer[9].StepName = "Lo(HitSideBtn)Hi";
	AutonomousObjectScorer[9].JumpCondition = RIGHTDISPLAYBUTTON;
	AutonomousObjectScorer[9].JumpToStep = 1;
	AutonomousObjectScorer[9].Timeout = 0;

	AutonomousObjectScorer[10].StepName = "Lo(HitSideBtn)Hi";
	AutonomousObjectScorer[10].JumpToStep = 8;
	AutonomousObjectScorer[10].Timeout = 0;

	AutonomousObjectScorer[0].StepName = "Lower Lift";
	AutonomousObjectScorer[0].LiftPower = DOWN;		//Lift Down
	AutonomousObjectScorer[0].Timeout = 500;

	//Repeat starting here
	AutonomousObjectScorer[1].StepName = "DriveToGoal+Lift";
	AutonomousObjectScorer[1].DriveType = STRAIGHT;	//Drive toward Goal and Lift
	AutonomousObjectScorer[1].DrivePower = FORWARD;
	AutonomousObjectScorer[1].LiftPower = 0;
	//AutonomousObjectScorer[1].			//Add encoder stuff here
	AutonomousObjectScorer[1].Timeout = 1300; //1700

	AutonomousObjectScorer[2].StepName = "WaitForStableBot";
	AutonomousObjectScorer[2].LiftPower = 20;		//Stop the lift, and stablalize robot.
	AutonomousObjectScorer[2].Timeout = 250;

	AutonomousObjectScorer[3].StepName = "Release Elements";
	AutonomousObjectScorer[3].IntakePower = OUT;	//Release the Barrels!
	AutonomousObjectScorer[3].Timeout = 2000;

	AutonomousObjectScorer[4].StepName = "StopIntake+Pause";
	AutonomousObjectScorer[4].IntakePower = STOP;
	AutonomousObjectScorer[4].Timeout = 250; //250
	AutonomousObjectScorer[4].JumpCondition = dgtl12;
	AutonomousObjectScorer[4].JumpToStep = 6;

	AutonomousObjectScorer[5].StepName = "Blue (Turn Left)";
	AutonomousObjectScorer[5].DriveType = LEFTONEWHEELTURN;
	AutonomousObjectScorer[5].DrivePower = BACKWARD;
	AutonomousObjectScorer[5].Timeout = 250; //250
	AutonomousObjectScorer[5].JumpToStep = 7;

	AutonomousObjectScorer[6].StepName = "Red (Turn Right)";
	AutonomousObjectScorer[6].DriveType = RIGHTONEWHEELTURN;
	AutonomousObjectScorer[6].DrivePower = BACKWARD;
	AutonomousObjectScorer[6].Timeout = 250; //250

	AutonomousObjectScorer[7].StepName = "BackToStartTile";
	AutonomousObjectScorer[7].DriveType = STRAIGHT;	//Drive toward Goal and Lift
	AutonomousObjectScorer[7].DrivePower = BACKWARD;
	AutonomousObjectScorer[7].Timeout = 1800;

	AutonomousObjectScorer[20].StepName = "Finished!";
	AutonomousObjectScorer[20].Timeout = -1;

	return 0;
}
