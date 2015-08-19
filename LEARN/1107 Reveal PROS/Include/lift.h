#ifndef LIFT_H_
#define LIFT_H_

#define eLIFT_resetThreshold		100

#define eLIFT_Kp					.80
#define eLIFT_Ki					.0005
#define eLIFT_Kd					0
#define eLIFT_Mi					20
#define eLIFT_AT					30

#define eLIFT_ground				0
#define eLIFT_rollover				50
#define eLIFT_bridge				600
#define eLIFT_stash					620
#define eLIFT_hanging				620

typedef enum vLiftHeights
{
	ground = eLIFT_ground,
	rollover = eLIFT_rollover,
	bridge = eLIFT_bridge,
	stash = eLIFT_stash,
	hanging = eLIFT_hanging
} vLiftHeights;

vLiftHeights goal;
/**
* Returns smart height relative to ground (based off of limit switch)
*/
int liftGetHeight();

/**
* Sets lift to value. 
* Limits to MAX_MOTOR_SPEED
* Will not lower if already at ground (limit switch is pressed)
*/
void liftSet(int value);

void liftResetPID();

/**
* Sets lift to value. Limits to MAX_MOTOR_SPEED
*/
bool liftGoToHeight(int goal);

#endif