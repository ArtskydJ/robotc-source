//Simon
//VEX Cortex
//Joseph Dykstra
//2013-04-24
#define initnum 50
int l, level=0, hit, blink[initnum];

bool correctbutton(int b)
	{
	hit=-1;
	while (hit==-1)
		{
		if (nLCDButtons==1) {hit=(b==0); PlayTone(1000,250);}
		if (nLCDButtons==2) {hit=(b==1); PlayTone(2000,250);}
		if (nLCDButtons==4) {hit=(b==2); PlayTone(3000,250);}
		}
	while (nLCDButtons!=0) {}
	return ((bool)hit);
	}

bool endofgame(int lev)
	{
	clearLCDLine(0);clearLCDLine(1);
	displayLCDString(0,0,"Failure | Again?");
	displayLCDString(1,0,"  Yes       No  ");
	PlayTone(2960,500); ClearTimer(T1); while(time1(T1)<500){}
	PlayTone(2794,550); ClearTimer(T1); while(time1(T1)<550){}
	PlayTone(2637,950); ClearTimer(T1); while(time1(T1)<950){}
	while(nLCDButtons!=1 && nLCDButtons!=4) {}
	return (nLCDButtons==1);
	}

task main()
	{
	bool playagain=true;
	while(playagain)
		{
		level=0;
		clearLCDLine(0);clearLCDLine(1);
		bool bAlive=true;
		for (int j=0; j<initnum; j++) {blink[j]=(rand()%3);}
		for (int j=0; bAlive; j++)
			{
			string show="";
			clearLCDLine(0);
			sprintf(show,"SIMON   Score=%02d",level);
			displayLCDString(0,0,show);
			level+=1;
			ClearTimer(T1); while(time1(T1)<500){}
			for (int k=0; k<level; k++)
				{
				clearLCDLine(1);
				displayLCDString(1,(blink[k]*6)+1,"[]");
				PlayTone(1000+(blink[k]*1000),250);
				ClearTimer(T1); while(time1(T1)<500){};
				}
			clearLCDLine(1);
			displayLCDString(1,5,"Repeat");
			for (l=0; l<level && bAlive; l++)
				{
				bAlive=correctbutton(blink[l]);
				}
			}
		playagain=endofgame(level);
		}
	}
