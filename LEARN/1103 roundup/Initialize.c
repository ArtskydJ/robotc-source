#include "Main.h"

void Initialize ( void )
{
      InitLCD ( 2 ) ;
      SetLCDLight ( 2 , 1 ) ;
      StartLCDButtonsWatcher ( 2 ) ;
      StartQuadEncoder ( 9 , 10 , 0 ) ;
      StartQuadEncoder ( 5 , 6 , 0 ) ;
      StartQuadEncoder ( 7 , 8 , 0 ) ;
      StartTimer ( 1 ) ; // Match Clock
      StartTimer ( 2 ) ; // Autonomous Control
      StartTimer ( 4 ) ; // Script_Functions
      StartTimer ( 5 ) ; // PID
      StartTimer ( 6 ) ; // Ultrasonics 
      PresetQuadEncoder ( 9 , 10 , 0) ;
      while ( ! IsEnabled() )
      {
            GetLCDButtonsWatcher ( 2 , &B1 , &B2 , &B3 ) ;
            User_Settings ( ) ;
            if ( B1 == 0 && B2 == 1 && B3 == 0 )
            {
                  GlobalData(1) = Off ;
                  SetLCDText ( 2 , 1 , "" ) ;
                  SetLCDText ( 2 , 2 , "" ) ;
                  SetLCDLight ( 2 , 0 ) ;
                  break ;
            }
      }
      if ( Position == Outfield && Autonomous_Code == 1 )
      {
            Gripper = On ;
            SetDigitalOutput ( 11 , On ) ;
      }
}
