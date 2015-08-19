#ifndef _main_h_
#define _main_h_

#include "API.h"
#include "UserInclude.h"


#define Descore_Wall_Goal				109 
#define Movable_Weighted_Base			136 
#define Descore_Movable_Weighted_Base	39  
#define Wall_Goal						171 
#define Ladder							213 
#define Manual							7   
#define Threshold						400 
#define Forward							3   
#define Dead_Zone						6   
#define Brake							15  
#define Pickup							-1  // != 0
#define Back							2   
#define Moving							10  
#define On								1   
#define Off								0   
#define Ready							11  
#define Line_Track						10  
#define Drive							13  
#define Encoder_Track					11  
#define Wall_Track						12  
#define Script_Ready					22  
#define Line							16  
#define Coast							21  
#define Lift_Ready						14  
#define No_Line							18  
#define Cross_Line						17  
#define Right							19  
#define Left							20  
#define Gripper_Time					150 
#define Tube							26  
#define Right_Encoder_Track				27  
#define Left_Encoder_Track				28  
#define Proximity						29  
#define Match							30  
#define RSC								31  
#define Infield							32  
#define Outfield						33  
#define Red								24  
#define Blue							25  
#define PSC								34  
#define Line2							35  
#define No_Line2						36  
#define Ultrasonic_Time					50  
#define Lift_C							13  
#define Descore_Wall_Goal2				87  
#define Ready2							55  



extern double Ch4;			//Joystick Channel 4
extern double Ch3;			//Joystick Channel 3
extern unsigned char Ch6u;	//Joystick Channel 6 - Up Button
extern unsigned char Ch5u;	//Joystick Channel 5 - Up Button
extern unsigned char Ch7u;	//Joystick Channel 7 - Up Button
extern unsigned char Ch6d;	//Joystick Channel 6 - Down Button
extern unsigned char Ch7r;	//Joystick Channel 7 - Right Button
extern unsigned char Ch7l;	//Joystick Channel 7 - Left Button
extern unsigned char Ch5d;	//Joystick Channel 5 - Down Button
extern unsigned char Ch7d;	//Joystick Channel 7 - Down Button
extern unsigned char Ch8u;	//Joystick Channel 8 - Up Button
extern unsigned char Ch8d;	//Joystick Channel 8 - Down Button
extern unsigned char Ch8r;	//Joystick Channel 8 - Right Button
extern unsigned char Ch8l;	//Joystick Channel 8 - Left Button

extern int Left_Line;	//Left Line Sensor
extern int Center_Line;	//Center Line Sensor
extern int Right_Line;	//Right Line Sensor

extern long Right_Encoder;	//Right Drive Encoder
extern int Error;
extern int Lift_Encoder;	//Lift Encoder
extern long Left_Encoder;	//Left Drive Encoder

extern char Gripper;
extern int Lift_Status;
extern int Lift_Setpoint;
extern int Script;
extern int Gripper_Limit;
extern float Angle;

extern float Timer1;
extern int Timer2;
extern int Timer4;
extern char Mode;
extern int Timer5;

extern char Armed2;
extern int Stage;
extern char Tilt;
extern int Lift_Motor;
extern float Left_Motor;
extern int Ultrasonic;
extern float Right_Motor;
extern int LF_Line;
extern int Lift_Limit;
extern float Left_Error;
extern char Armed1;
extern char Right_Motor_Status;
extern char Armed3;
extern float Ultrasonic_Error;
extern char Left_Motor_Status;

extern float I_Error;
extern float Right_Error;
extern float D_Error;
extern char Last_Line;
extern float D_Out;
extern float I_Out;
extern float P_Out;
extern float Last_Error;
extern float Output;

extern int Left_Pot;
extern int Line_Position;
extern int Secondary_Script;
extern int Event;
extern int Right_Pot;
extern int Alliance;
extern int Position;
extern int Autonomous_Code;

extern int Last_Left_Pot;
extern int Last_Right_Pot;

extern int Ch6u_Armed;
extern int Ch6d_Armed;

extern int Lift_Reset;
extern int Last_Goal;
extern int Ch5d_Armed;
extern int Hang;
extern int Timer6;
extern int Finish_Time;
extern int Preload;
extern int Ultra;

extern unsigned char B1;
extern unsigned char B2;
extern unsigned char B3;

extern int Descore_Armed;



void Initialize ( void );
void Autonomous ( unsigned long ulTime );
void OperatorControl ( unsigned long ulTime );
void Driver_Control ( void );
void Motor_Drive ( void );
void Script_Functions ( void );
void Autonomous_Control ( int Navigation_Type, float Left_Motor_Setpoint, float Right_Motor_Setpoint, int Left_Encoder_Setpoint, int Right_Encoder_Setpoint, int Ultrasonic_Direction, int Ultrasonic_Setpoint, int Lift_Height_Setpoint, int Gripper_Setpoint, int Script_Setpoint, int Tilt_Setpoint, int Max_Time, int Min_Time, int Stop, int Break_Option );
void Programming_Skills_Challenge ( void );
void High_Hang ( void );
void Auton_Routines ( void );
void User_Settings ( void );

#endif