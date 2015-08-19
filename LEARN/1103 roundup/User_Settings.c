#include "Main.h"

void User_Settings ( void )
{
      Left_Pot = GetAnalogInput ( 5 ) ;
      Left_Pot = (Left_Pot/190) ;
      Right_Pot = GetAnalogInput ( 6 ) ;
      Right_Pot = (Right_Pot/190) ;
      if ( Left_Pot != Last_Left_Pot || Last_Right_Pot != Right_Pot  )
      {
            if ( Left_Pot == 0  )
            {
                  Event = Match ;
                  Alliance = Red ;
                  Position = Infield ;
                  SetLCDText ( 2 , 1 , " Red Infield" ) ;
            }
            if ( Left_Pot == 1  )
            {
                  Event = Match ;
                  Alliance = Blue ;
                  Position = Infield ;
                  SetLCDText ( 2 , 1 , " Blue Infield" ) ;
            }
            if ( Left_Pot == 2  )
            {
                  Event = Match ;
                  Alliance = Red ;
                  Position = Outfield ;
                  SetLCDText ( 2 , 1 , " Red Outfield" ) ;
            }
            if ( Left_Pot == 3  )
            {
                  Event = Match ;
                  Alliance = Blue ;
                  Position = Outfield ;
                  SetLCDText ( 2 , 1 , " Blue Outfield" ) ;
            }
            if ( Left_Pot == 4  )
            {
                  SetLCDText ( 2 , 1 , "     Robot" ) ;
                  SetLCDText ( 2 , 2 , "Skills Challenge" ) ;
                  Event = RSC ;
                  Alliance = 0 ;
                  Position = 0 ;
                  Autonomous_Code = 0 ;
            }
            if ( Left_Pot >= 5 )
            {
                  SetLCDText ( 2 , 1 , "  Programming   " ) ;
                  SetLCDText ( 2 , 2 , "Skills Challenge" ) ;
                  Event = PSC ;
                  Alliance = 0 ;
                  Position = 0 ;
                  if ( Right_Pot < 3 )
                  {
                        Autonomous_Code = 2 ;
                  }
                  if ( Right_Pot >= 3 )
                  {
                        Autonomous_Code = 1 ;
                  }
            }
            if ( Right_Pot >= 5 && Event == Match )
            {
                  Autonomous_Code = 1 ;
                  SetLCDText ( 2 , 2 , " Autonomous #1" ) ;
            }
            if ( Right_Pot == 4 && Event == Match )
            {
                  Autonomous_Code = 2 ;
                  SetLCDText ( 2 , 2 , " Autonomous #2" ) ;
            }
            if ( Right_Pot == 3 && Event == Match )
            {
                  Autonomous_Code = 3 ;
                  SetLCDText ( 2 , 2 , " Autonomous #3" ) ;
            }
            if ( Right_Pot == 2 && Event == Match )
            {
                  Autonomous_Code = 4 ;
                  SetLCDText ( 2 , 2 , " Autonomous #4" ) ;
            }
            if ( Right_Pot == 1 && Event == Match )
            {
                  Autonomous_Code = 5 ;
                  SetLCDText ( 2 , 2 , " Autonomous #5" ) ;
            }
            if ( Right_Pot == 0 &&  Event == Match )
            {
                  Autonomous_Code = 0 ;
                  SetLCDText ( 2 , 2 , " Autonomous OFF" ) ;
            }
      }
      Last_Left_Pot = Left_Pot ;
      Last_Right_Pot = Right_Pot ;
}
