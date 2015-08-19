//Whack a mole
int level=1, result;

bool correctbutton(int b)
	{
	bool l, c, r;
	bool correcthit=false, stayalive=true;
	for (int i=0; i<sqrt(30-level); i++)
		{
		l=nLCDButtons&1>0;
		c=nLCDButtons&2>0;
		r=nLCDButtons&4>0;
		if (b==0)
			{
			if (l) {correcthit=true; PlayTone(1500,20);}
			if (c||r) {stayalive=false;}
			}
		if (b==1)
			{
			if (c) {correcthit=true; PlayTone(1500,20);}
			if (l||r) {stayalive=false;}
			}
		if (b==2)
			{
			if (r) {correcthit=true; PlayTone(1500,20);}
			if (l||c) {stayalive=false;}
			}
		if (correcthit==false) {Wait(250);}
		}
	if (correcthit==false) {stayalive=false;}
	return stayalive;
	}

task main()
	{
	int temp;
	bool alive=true;
	for (int i=0; alive; i++)
		{
		for (int i=0; (i<level)&&(alive); i++)
			{
			temp=(rand()%3);
			ClearLine(LCD_LINE8);
			TextOut(temp*45,LCD_LINE8,"X",DRAW_OPT_NORMAL);
			PlayTone(2500,50);
			alive=correctbutton(temp);
			Wait(300);
			}
		if (alive==true)	//ALIVE
			{
			level+=1;
			ClearScreen();
			TextOut(30,LCD_LINE1,"Level Up!",DRAW_OPT_NORMAL);
			PlayTone(1175,500);
			Wait(500);
			PlayTone(1568,500);
			Wait(500);
			PlayTone(2093,500);
			Wait(500);
			ClearScreen();
			}
		else				//DEAD
			{
			ClearScreen();
			TextOut(30,LCD_LINE1,"Failure!",0);
			TextOut(30,LCD_LINE3,"Score:"+NumToStr(level),0);
			TextOut(30,LCD_LINE4,StrCat("HighSscore: ",NumToStr( readHigh("Whack.dat") )),0);
			PlayTone(2960,500);
			Wait(500);
			PlayTone(2794,650);
			Wait(650);
			PlayTone(2637,1100);
			Wait(1100);
			}
		}
	}
