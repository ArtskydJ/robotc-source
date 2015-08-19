//----------------------------------------< Function Declarations >----------------------------------------------\\
//void pre_auton();
//task autonomous()
//task usercontrol();
void initializeTimers();
int initializeDisplay();
int initializePID();
int initializeGyro();
int initializeAutonomous();
int getInput();
int processAutonomous();
int processOperator();
int operatorDriveTrain();
int operatorLift();
int operatorIntake();
int Display();
void DisplayMainMenu();
void DisplayMenu2(string MenuTitle, string MenuItem);
void DisplayButtonHandling();
int UpdatePIDControllers();
int PickAutonomous();
int IsMenuItemActivated();
int CheckJoystick();
void ToggleCheck (int CurrentButtonState, int &WasAlreadyPressed, int &ToBeToggled);
void RangeCheck (int LowerLimit, int &Value, int UpperLimit);
void PIDController(TPidSystem &PIDObject);
void MotorTest();
int doOutput();
