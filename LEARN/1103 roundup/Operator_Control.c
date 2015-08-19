#include "Main.h"

void OperatorControl ( unsigned long ulTime )
{
      User_Settings ( ) ;
      SetLCDText ( 2 , 1 , "" ) ;
      SetLCDText ( 2 , 2 , "" ) ;
      SetLCDLight ( 2 , 0 ) ;
      PresetTimer ( 1 , 0 ) ;
      Driver_Control ( ) ;
      Timer1 = GetTimer ( 1 ) ;
      SetMotor ( 1 , 0 ) ;
      SetMotor ( 2 , 0 ) ;
      SetMotor ( 3 , 0 ) ;
      SetMotor ( 4 , 0 ) ;
      SetMotor ( 5 , 0 ) ;
      SetMotor ( 6 , 0 ) ;
      SetMotor ( 7 , 0 ) ;
      SetMotor ( 8 , 0 ) ;
      SetMotor ( 9 , 0 ) ;
      SetMotor ( 10 , 0 ) ;
      SetLCDText ( 2 , 2 , "Time = %.1f sec" , (float)(Finish_Time / 1000) ) ;
}
