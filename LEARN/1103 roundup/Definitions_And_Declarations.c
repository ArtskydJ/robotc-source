#define Descore_Wall_Goal				109
#define Movable_Weighted_Base			136
#define Descore_Movable_Weighted_Base	39
#define Wall_Goal						171
#define Ladder						213
#define Manual					7
#define Threshold			400
#define Forward				3
#define Dead_Zone			6
#define Brake				15
#define Pickup				-1		// !=0
#define Back				2
#define Moving				10
#define On					1
#define Off					0
#define Ready				11
#define Line_Track			10
#define Drive				13
#define Encoder_Track		11
#define Wall_Track			12
#define Script_Ready		22
#define Line				16
#define Coast				21
#define Lift_Ready			14
#define No_Line				18
#define Cross_Line			17
#define Right				19
#define Left				20
#define Gripper_Time		150
#define Tube				26
#define Right_Encoder_Track	27
#define Left_Encoder_Track	28
#define Proximity			29
#define Match				30
#define RSC					31
#define Infield				32
#define Outfield			33
#define Red					24
#define Blue				25
#define PSC					34
#define Line2				35
#define No_Line2			36
#define Ultrasonic_Time		50
#define Lift_C				13
#define Descore_Wall_Goal2	87
#define Ready2				55

int Ch3;
int Ch4;
bool Ch5u = 0;
bool Ch5d = 0;
bool Ch6u;
bool Ch6d;
bool Ch7u;
bool Ch7d;
bool Ch7l;
bool Ch7r;
bool Ch8u;
bool Ch8d;
bool Ch8l;
bool Ch8r;

int Left_Line;
int Center_Line;
int Right_Line;
int Left_Encoder;
int Right_Encoder;
int Lift_Encoder;

bool Gripper = 0;
int Lift_Status = Ready;
int Lift_Setpoint = Pickup;
int Script = 0;
int GripperLimit;
float Angle;

float Timer1;
int Timer2;
int Timer4 = 0;
int Timer5;
int Timer6;
int Finish_Time = 0;

int Mode = Manual;
int Armed1 = On;
int Armed2 = On;
int Armed3 = On;
int Ch5d_Armed = On;
int Ch6u_Armed = On;
int Ch6d_Armed = On;
int Descore_Armed = Off;
int State = 0;
int Tilt = Forward;

int Lift_Motor = 0;
int Left_Motor;
int Right_Motor;
int Left_Motor_Status;
int Right_Motor_Status;
float Left_Error;
float Right_Error

int Ultrasonic;
float Ultrasonic_Error;
int LF_Line;
int Lift_Limit = 0;
int Last_Line = -3;

int Error;
float I_Error;
float D_Error;
float P_Out;
float I_Out;
float D_Out;
float Last_Error
float Output;

int Left_Pot;
int Right_Pot;
int Last_Left_Pot = -1;
int Last_Right_Pot = -1;

int Line_Position;
int Secondary_Script = Off;
int Event = 1;

int Alliance = 0;
int Position = 1;
int Autonomous_Code = 0;

int Lift_Reset = Off;
int Last_Goal = Movable_Weighted_Base;
int Hang = Off;

int Preload = On;
int Ultra = Off;

bool B1 = 0;
bool B2 = 0;
bool B3 = 0;
