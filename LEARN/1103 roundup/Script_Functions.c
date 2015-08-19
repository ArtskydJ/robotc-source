#include "Main.h"

void Script_Functions ( void )
{
      Timer4 = GetTimer ( 4 ) ;
      Gripper_Limit = GetAnalogInput ( 7 ) ;
      if ( Script == Wall_Goal && Stage != Off )
      {
            if ( Stage == 2 && Lift_Status == Ready )
            {
                  Gripper = Off ;
                  Stage = Off ;
                  Script = Off ;
                  if ( Secondary_Script == Off )
                  {
                        Descore_Armed = Descore_Wall_Goal ;
                  }
            }
            if ( Stage == 1 )
            {
                  if ( Secondary_Script == Off )
                  {
                        Lift_Setpoint = (Wall_Goal - 66) ;
                  }
                  if ( Secondary_Script == On )
                  {
                        Lift_Setpoint = (Wall_Goal - 36) ;
                  }
                  Stage = 2 ;
            }
      }
      if ( Script == Movable_Weighted_Base && Stage != Off )
      {
            if ( Stage == 2 && Lift_Status == Ready )
            {
                  Gripper = Off ;
                  Stage = Off ;
                  Script = Off ;
                  if ( Secondary_Script == Off )
                  {
                        Descore_Armed = Descore_Movable_Weighted_Base ;
                  }
            }
            if ( Stage == 1 )
            {
                  if ( Secondary_Script == Off && Preload == Off )
                  {
                        Lift_Setpoint = (Movable_Weighted_Base - 90) ;
                  }
                  if ( Secondary_Script == On )
                  {
                        Lift_Setpoint = (Movable_Weighted_Base - 50) ;
                  }
                  if ( Secondary_Script == Off && Preload == On )
                  {
                        Lift_Setpoint = (Movable_Weighted_Base - 102) ;
                        Preload = Off ;
                  }
                  Stage = 2 ;
            }
      }
      if ( Script == Pickup && Stage != Off )
      {
            if ( Stage == 4 && Timer4 > 200 )
            {
                  Lift_Setpoint = Pickup ;
                  Stage = Off ;
                  Script = Off ;
            }
            if ( Stage == 3 && Timer4 > 300 )
            {
                  if ( Gripper_Limit < 10 )
                  {
                        Stage = Off ;
                        Script = Off ;
                  }
                  if ( Gripper_Limit > 10 )
                  {
                        Lift_Setpoint = (Lift_Encoder + 5) ;
                        Lift_Status = Ready ;
                        Gripper = Off ;
                        Stage = 4 ;
                        PresetTimer ( 4 , 0 ) ;
                  }
            }
            if ( Stage == 2 && Timer4 > Gripper_Time )
            {
                  if ( Secondary_Script == Off )
                  {
                        Lift_Setpoint = Movable_Weighted_Base ;
                  }
                  if ( Secondary_Script == On )
                  {
                        Lift_Setpoint = Wall_Goal ;
                  }
                  Stage = 3 ;
                  PresetTimer ( 4 , 0 ) ;
            }
            if ( Stage == 1 )
            {
                  Gripper = On ;
                  Stage = 2 ;
            }
      }
      if ( Script == Descore_Wall_Goal && Stage != Off )
      {
            if ( Stage == 2 && Timer4 > Gripper_Time )
            {
                  Lift_Setpoint = Wall_Goal ;
                  Stage = Off ;
                  Script = Off ;
            }
            if ( Stage == 1 )
            {
                  PresetTimer ( 4 , 0 ) ;
                  Gripper = On ;
                  Stage = 2 ;
            }
      }
      if ( Script == Descore_Movable_Weighted_Base && Stage != Off )
      {
            if ( Stage == 2 && Timer4 > Gripper_Time )
            {
                  Lift_Setpoint = Movable_Weighted_Base ;
                  Stage = 2 ;
                  Stage = Off ;
                  Script = Off ;
            }
            if ( Stage == 1 )
            {
                  PresetTimer ( 4 , 0 ) ;
                  Gripper = On ;
                  Stage = 2 ;
            }
      }
      if ( Script == Ladder && Stage != Off )
      {
            if ( Stage == 3  )
            {
                  Lift_Setpoint = (Ladder - 38) ;
                  Stage = Off ;
                  Script = Off ;
            }
            if ( Stage == 2 && Lift_Status == Ready && Lift_Limit > 10 )
            {
                  Tilt = Back ;
                  Stage = 3 ;
            }
            if ( Stage == 1 )
            {
                  if ( (Secondary_Script == On && Timer4 > 150) || Secondary_Script == Off )
                  {
                        Lift_Setpoint = 15 ;
                        Stage = 2 ;
                  }
            }
            if ( Stage == -1 )
            {
                  Tilt = Forward ;
                  PresetTimer ( 4 , 0 ) ;
                  Stage = 1 ;
            }
      }
      if ( Script == Off )
      {
            Secondary_Script = Off ;
      }
}
