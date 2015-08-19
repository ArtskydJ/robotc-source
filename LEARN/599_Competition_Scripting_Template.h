
//RobotC 599_Competition_Script_Template.h
//This program is a suggested template with dummy scripting for both user and autonomous modes testing.
//Simulated pwm commands are generated by joystick and scripting functions
//The pwm commands are integrated to create simulated distances, dist1,dist2 and dist3 which
//are functons of joystick axes 1,2 and 3 respectively.
//Download to cortex and use the Vexnet debug competition mode control (DISABLE,AUTONOMOUS,USER CONTROL)
//to exercise the software logic and  and watch global variables move with the joystick and scripts.
//DIASABLE...nothing but timer moves
//AUTONOMOUS...runs auto_script_2 and stops.  auto_script_2 is determined by sensor port in8 (auto_select).
//USER CONTROL...move joystick axes 1,2 and 3 and watch dist1,dist2 and dist3 move.
//Then select scripts with buttons 5U,5D,6U,6D and notice how the scripts take control of its axis and
//allows the remaining joystick axes to function as normal to joystick inputs.
//If you hold button 8L down for 3 sec, you can then use single stepping of selected scripts with subsequent 8L pushes.
//USER CONTROL .... auto_debug_mode.  Allows autonomous scripts to be tested in USER CONTROL mode.
//Hold 8R down for 3 sec and now you can use the same buttons (5U,5D,6U,6D) to select auto_scripts.
//Single stepping works here too.  Disconnect auto_debug_mode anytime with another 8R push.

//More details below:
//Driver operation with no scripts active
//Joystick Ch1 controls pwm_cmd1 which sets the speed that dist1 moves.  Same for (Ch2,pwm_cmd2,dist2)
//and (C3,pwm_cmd3,dist3).

//Script calling during driver operation (uses buttons 5U,5D,6U,6D)
//Btn5D calls script = name_1;//moves relative distance 1 up by 500 and restores it
//Btn5U calls script = name_2;//moves relative distance 2 up by 500 and restores it
//Btn6D calls script = name_3;//moves relative distance 3 up by 500 and restores it
//Btn6U calls script = name_4;//script increments total time by 1000,2000 and 3000 ms in three script steps.

//auto_debug_mode allows autonomous scripts to be called by 5U,5D,6U,6D
//Set with Btn8R 3 second push and follow with push of script button.
//Btn5D calls script = auto_name_1;//moves relative distance 1 up by 500 and restores it
//Btn5U calls script = auto_name_2;//moves relative distance 2 up by 500 and restores it
//Btn6D calls script = auto_name_3;//moves relative distance 3 up by 500 and restores it
//Btn6U calls script = auto_name_4;//script increments total time by 1000,2000 and 3000 ms in three script steps.

//single_step_mode
//Set by Btn8L 3 second push. Subsequent Btn8L pushes cause the script step to increment by 1.
//Stepping can be used for both manual and autonomous scripts.
//Single_step_mode is reset by kill_sw or button 8R push once a script has been initiated.

//Script Reset
//Running scripts are reset when they complete, when the kill_sw is hit or when Btn8R is hit.

//Can set defines  ENABLE_AUTO_DEBUG and ENABLE_KILL_SW  to enable use in testing or disable for competition.

//Written by Chris S.
//vamfun@yahoo.com
//599 Robodox Engineering Mentor
//see blog for further details www.vamfun.wordpress.com

//script name defines (Put your names here)
#define  no_script 0
#define  name_1    1
#define  name_2    2
#define  name_3    3
#define  name_4    4
#define  auto_name_1 10
#define  auto_name_2 20
#define  auto_name_3 30
#define  auto_name_4 40

#define  ENABLE_AUTO_DEBUG  true  //(true or false) Enables button 8L and 8R for use with single_step_mode and auto_debug_mode
#define  ENABLE_KILL_SWITCH true  //(true of false) Enables bumper kill sw on robot to kill all scripts
//core function prototypes ... (Rename if you want)
void Autonomous599();
void User599();
void Initialize();
void Select_autonomous_script();
void Select_user_script();
void Run_scripts();
void Reset_scripts();
void Reset_timers();
void Process_sensors();
void Operator();
void Core_functions();//contains collection of motor and manipulator action functions

void Reset_simulation();// delete if not using simulation

//script prototypes (Replace with your script names)
void Script_name_1(); //use replace for name_1 in program to use your own name
void Script_name_2();
void Script_name_3();
void Script_name_4();
void Script_auto_name_1();
void Script_auto_name_2();
void Script_auto_name_3();
void Script_auto_name_4();

//Script utility function prototypes
//Define your own

int Event_timer(int goal);  // this is called by scripts to do something.. it increments total time by goal
int Move_dist_ch1(int goal , int pwm_input); //causes distance 1 to increment by goal at pwm_input rate.
int Move_dist_ch2(int goal , int pwm_input); //causes distance 2 to increment by goal at pwm_input rate.
int Move_dist_ch3(int goal , int pwm_input); //causes distance 3 to increment by goal at pwm_input rate.

//global variables
//used for script engine (DO NOT MODIFY)
int step =  0; //script index
int script = no_script; //script name
int done = 0 ; //script status  ... done = 0 means script is in progress, done = 1 means script is finished
int auto_script_no = 0 ;  // number of script selected for autonomous based upon auto_select sensor port
bool bdisconnect = false; // push and release of button 8R in less than 3 seconds causes bdisconnect = true;
bool bauto_debug_mode = false; // auto_debug_mode status... false=disengaged,true = engaged
bool bsingle_step_mode = false;// script single_step_mode status...false=disengaged, true = engaged
bool bsingle_step = false;//when in single_step_mode...setting bsingle_step to true causes one step to occur.
bool bsys_reset = true;//flag used to initialize all scripts.  Set true by reset_scripts() and false by script utility once it has initialized.

//modify these to match your automated pwm commands
bool auto_cmd1 = false; //auto_cmd flags are set by scripts to disable joystick cmd conlicts
bool auto_cmd2 = false;
bool auto_cmd3 = false;
int pwm_cmd1 = 0; //rate command for dist1 etc
int pwm_cmd2 = 0;
int pwm_cmd3 = 0;

//used for simulated script action functions (Delete when simulator is not used)
int total_time = 0;//this is incremented by calling script name_4
int dist1 = 0;//simulated encoder distance that responds to pwm_cmd1
int dist2 = 0;
int dist3 = 0;
