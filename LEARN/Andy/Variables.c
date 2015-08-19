//-------------------------------------< Global Variable Declarations >-----------------------------------------\\
// btn = Button (Input), stk = Stick (Input), pneu = Pneumatics (Output), motor = Motor (Output)

//Inputs
float stkDriveX;									//Current X value of drive stick (-127 to 127)
float stkDriveY;							 		//Current Y value of drive stick (-127 to 127)
float stkDriveS;
int stkLift;										//Lift Joystick Channel
int stkLift1;
int stkLift2;
int btnLiftTopUp2;
int btnLiftTopDown2;
int btnLiftBottomUp2;
int btnLiftBottomDown2;
int btnOldNewDrive;								//Old/New-Drive Joystick Button
int btnFrontBackDrive;
int gyrGyroscope;
int btnIntakeIn1;
int btnIntakeOut1;
int btnIntakeIn2;
int btnIntakeOut2;
int btnLiftEncoderReset1;
int btnLiftEncoderReset2;
int btnLiftLowGoal1;
int btnLiftMiddleGoal1;
int btnLiftHighGoal1;
int btnLiftLowGoal2;
int btnLiftMiddleGoal2;
int btnLiftHighGoal2;
float MainBatteryVoltageAverage;
float MainBatteryVoltageLevel;
int ButtonBitMap;
int LeftDisplayButton;
int CenterDisplayButton;
int RightDisplayButton;
int LeftLiftEncoder;
int RightLiftEncoder;
int LeftDriveEncoder;
int RightDriveEncoder;
int BottomLeftLiftLimitSwitch;
int BottomRightLiftLimitSwitch;

//Outputs
int motorLeftFrontDrive;
int motorLeftBackDrive;
int motorRightFrontDrive;
int motorRightBackDrive;
int motorRampedLeftFrontDrive;
int motorRampedLeftBackDrive;
int motorRampedRightFrontDrive;
int motorRampedRightBackDrive;
int motorLiftLeftTop;                  //Value assigned to left lift motors
int motorLiftLeftBottom;
int motorLiftRightTop;									//Value assigned to right lift motors
int motorLiftRightBottom;
int motorIntakeFront;								//gets put into the front of the intake mechanism
int motorIntakeBack;								//Gets put into the back of the intake mechanism
int LiftUp;
int LiftDown;

//Stuff that needs to remembered
int btnOldNewDrivePressed;							//Old/New-Drive Joystick Button Pressed Variable
TDriveAlgorithm OldNewDrive = PLAIN;
int btnFrontBackDrivePressed;
TRobotDirection FrontBackDrive = NORMAL;
int btnLiftLowGoal1Pressed;
int btnLiftMiddleGoal1Pressed;
int btnLiftHighGoal1Pressed;
int btnLiftLowGoal2Pressed;
int btnLiftMiddleGoal2Pressed;
int btnLiftHighGoal2Pressed;
TGoalHeightButton LastGoalHeightButton1;
TGoalHeightButton LastGoalHeightButton2;
int LiftTargetHeight;
int LiftToPresetHeight;
int LeftDisplayButtonPressed;
int CenterDisplayButtonPressed;
int RightDisplayButtonPressed;
int ActivateMenuItem = 0;
int DisplayNeedsRefreshing = 1;
int CurrentMenu = 0;
int CurrentMenuItem = 0;
int TotalMenuItems;
//int MenuStack[64];
string MainMenuStrings[7] = {"Run Autonomous", "Pick Autonomous", "Motor Test", "Show Variables", "Edit Autonomous", "Make Autonomous", "Show Errors"};
string AutonomousMenu[3] = {"LoadScoreReturn", "AutonomousSkills", "No Autonomous"};
TPidSystem PIDLift;
TAutonomous AutonomousLoadScoreReturn[11];
TAutonomous AutonomousObjectScorer[21];
TAutonomous CurrentStep;
int ReadyForNextAutonomousStep = 1;
int AutonomousStep = 0;
int AutonomousRoutine = 0;
int LockInAutonomous = 0;
int EnableOutput = 1;
int LiftButtonsAreControlling = 0;
