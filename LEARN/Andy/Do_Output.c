int doOutput()
{
	//output code here
	int ErrorCode = 0;

	/*motorRampedLeftFrontDrive += ((motorLeftFrontDrive - motorRampedLeftFrontDrive) * MOTORRAMPCONSTANT);
	motorRampedLeftBackDrive += ((motorLeftFrontDrive - motorRampedLeftBackDrive) * MOTORRAMPCONSTANT);
	motorRampedRightFrontDrive += ((motorLeftFrontDrive - motorRampedRightFrontDrive) * MOTORRAMPCONSTANT);
	motorRampedRightBackDrive += ((motorLeftFrontDrive - motorRampedRightBackDrive) * MOTORRAMPCONSTANT);*/

	if (FrontBackDrive == NORMAL)
	{
		motor[DriveFL] = motorLeftFrontDrive;
		motor[DriveBL] = motorLeftBackDrive;
		motor[DriveFR] = motorRightFrontDrive;
		motor[DriveBR] = motorRightBackDrive;

		motor[IntakeL] = motorIntakeFront;
		motor[IntakeR] = motorIntakeFront;
	}
	else
	{
		motor[DriveBR] = 0 - motorLeftFrontDrive;
		motor[DriveFR] = 0 - motorLeftBackDrive;
		motor[DriveBL] = 0 - motorRightFrontDrive;
		motor[DriveFL] = 0 - motorRightBackDrive;

		motor[IntakeL] = 0 - motorIntakeFront;
		motor[IntakeR] = 0 - motorIntakeBack;

	}
	motor[LiftFL] = motorLiftLeftTop;
	motor[LiftBL] = motorLiftLeftBottom;
	motor[LiftFR] = motorLiftRightTop;
	motor[LiftBR] = motorLiftRightBottom;

	return ErrorCode;
}
