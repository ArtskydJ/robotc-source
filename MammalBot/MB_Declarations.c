//Sensors
int senAddToAbsGyro; //Not actual sensor...
T_LC_INT senGyro;
T_LC_INT senAbsGyro;
T_LC_INT senEncL;
T_LC_INT senEncR;
T_LC_INT senUS;
T_LC_INT senLight;
T_LC_INT senTouch;

//Output
int outDrvL;
int outDrvR;

//Autonomous
int autoHitTarget;
bool autoDriveReady;
bool autoClockRunning = false;
int  autoStep = 0;
unsigned int autoTimer = 0;

//System
int sysLooptime;

//PID
T_PID PIDLineFollow;
T_PID PIDDriveL;
T_PID PIDDriveR;
T_PID PIDGyro1;
T_PID PIDGyro2;

//--Arrays--//
short mtrTarget[3]={0,0,0};
short mtrSlewed[3]={0,0,0};
char slewConstants[3];//Low-Level/Open/Shut		Medium-Open/Shut	High-Open/Shut			Corner-Open/Shut	Drop-Open/Shut
unsigned int autoTimeRecord[NO_TIME_RECORDS];
