#include "Main.h"

void IO_Initialization(void)
{
    SetCompetitionMode ( -1, -1 ) ;
    SetAutonomousMode ( 0 ) ;
    SetTeamInfo ( "000easyC" ) ;
    DefineControllerIO ( 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0 ) ;
    DefineImeTable ( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ) ;
    DefineMotorTypes ( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ) ;
}
