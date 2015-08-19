//Definitions.c
//2013-05-06
#define SLEW

#define checkTarget(cndtn,value)	(cndtn)?((value)>=INtarget):((value)<=INtarget)
#define capValue(Min,Value,Max)		Value = (Value<Min)? (Min):(Value); Value = (Value>Max)? (Max):(Value)
#define changed(INLC)				(INLC.last != INLC.curr)
#define pressed(INLC)				(!INLC.last && INLC.curr)
#define diffLast(INLC)				(INLC.curr - INLC.last)
#define diffStep(INLC)				(INLC.curr - INLC.stepStart)
#define setLast(INLC)				INLC.last = INLC.curr
#define setStep(INLC)				INLC.stepStart = INLC.curr
#define setToZero(INLC)				INLC.last=0; INLC.curr=0; INLC.stepStart=0

#define NO_AUTO_COLUMNS		4
#define NO_TIME_RECORDS		100

#define MIN_LOOP_MS			4
#define PID_WAIT_MS			350

#define START	0
#define FINISH	1

#define LFT_90	-900	//Relative-v-
#define LFT_45	-450	//Relative |
#define RHT_45	450		//Relative |
#define RHT_90	900		//Relative-^-
#define WEST	0		//Absolute-v-
#define N_WEST	450		//Absolute |
#define NORTH	900		//Absolute |
#define N_EAST	1350	//Absolute |
#define EAST	1800	//Absolute |
#define S_EAST	2250	//Absolute |
#define SOUTH	2700	//Absolute |
#define S_WEST	3150	//Absolute-^-


/*Motor Speed Constants
 Shortcuts for autonomous writing.
*/
#define UP		 100
#define DOWN	-100
#define FWD		 100
#define REV		-100
#define LEFT	-100
#define RIGHT	 100
#define BOTH	 0
#define IN		 100
#define OUT		-100
#define FULL	 100
#define HALF	 50
#define FOLLOW	 100
#define TURN	 100
#define BRAKE	 5 //can also be used in -Action- column

#define AUTO_DRV_SLEW	3

#define NOT_HIT	0
#define NEXT	1
#define PID		2

#define LINE	50

// Drive Types
#define SPD		0	//Speed
#define ENC		1	//Encoder
#define STR		2	//Straight
#define CMP_2	3	//Compass turn - 2 Sides
#define CMP_L	4	//Compass turn - Left Side
#define CMP_R	5	//Compass turn - Right Side
#define FLINE	6	//Follow Line

#define PID_ZONE			25			//If the PID error is within this amount, it is close enough to its target

typedef struct
	{
	int curr;
	int last;
	int stepStart;
	}
	T_LC_INT;

typedef struct
	{
	float kp;
	float ki;
	float kd;
	int error;
	int integral;
	int derivative;
	int lastError;
	int output;
	}
	T_PID;
