/* This function gets the target motor value, the
previously assigned motor value, and the slew.
*/
float slew(int INtargetValue, int INlastValue, float INslew)
	{
	int diff = INtargetValue-INlastValue;
	if		(diff >  INslew) diff = INslew;
	else if (diff < -INslew) diff =-INslew;
	return diff;
	}

/* This function calculates the proportional,
integral and derivative values for the specified
T_PID values. (See Definitions.c for T_PID.)
*/
int updatePIDController(T_PID &INPID, int INerror)
	{
	INPID.error = INerror;
	INPID.integral = (INPID.integral * 4 / 5) + INPID.error;
	INPID.derivative = INPID.error - INPID.lastError;
	INPID.lastError = INPID.error;
	INPID.output = (float)(INPID.error		* INPID.kp)
						+ (INPID.integral	* INPID.ki)
						+ (INPID.derivative	* INPID.kd);
	return (INPID.output);
	}

/* This function sets all motor targets to 0.
*/
void zeroMotors()
	{
	outDrvL = 0;
	outDrvR = 0;
	for (int j=0; j<3; j++)
		mtrTarget[j] = 0;
	}
