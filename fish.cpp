#include <graphics.h>
#include <conio.h>
#include <time.h>
#include"fish.h"
#define	CMD_LEFT		1
#define	CMD_RIGHT		2
#define	CMD_UP		    3
#define CMD_DOWN        4
#define CMD_QUIT        5
using namespace std;
fish::fish()
{
	m=0;
	n=0;
	last=6;

	x=0;
	y=0;
	keynote = 0;
}
fish::fish(int x,int y)
{

	this->x=x;
	this->y=y;
}

int fish::getScore()
{
	return score;
}
int fish::getCommand()
{
    
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		keynote = CMD_LEFT;
		return 1;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		keynote = CMD_RIGHT;
		return 1;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)	
	{
		keynote = CMD_UP;
		return 1;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)	 
	{
		keynote = CMD_DOWN;
		return 1;
	}
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		keynote = CMD_QUIT;
		return 1;
	}
	else return 0;
    
}

int fish::getX()
{
	return x;
}
int fish::getY()
{
	return y;
}

int Time(int t)
{
	char strsec[10];
	int sec = 40 - (GetTickCount() - t) / 1000;
	itoa(sec, strsec, 10);
	outtextxy(810, 70, "      ");
	outtextxy(810, 70, strcat(strsec, "s"));
	
	return sec;
}

int fish::eaten(int m,int n)
{	
	int dis;
	dis=(x-m)*(x-m)+(y-n)*(y-n);
	
	if(dis>529)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}

void fish::setx(int m)
{
	x=m;
}
void fish::sety(int n)
{
	y=n;
}

int fish::menu(int t)
{
	line(641, 0, 641, 480);	
	line(641, 200, 900, 200);
	char runTime[] = "游戏倒计时 : ", 
		 receiveBallNum[] = "得分:", 
		 copyRight[] = "版权所有:孙峻礁&&周劭涵",
		 finishWorkDate[] = "完成日期:2016年5月31日", 
		 introductiona[] = "按方向键控制粉色大球移动吃掉小球;",
		 introductionb[] = "绿色小球1分,黄色小球2分;",
		 introductionc[] = "倒计时为0时游戏结束.";

	setlinecolor(GREEN);
	settextcolor(GREEN);
	outtextxy(645, 10, introductiona);
	outtextxy(645, 30, introductionb);
	outtextxy(645, 50, introductionc);
	outtextxy(645, 80, runTime);
	outtextxy(645, 110, receiveBallNum);
	outtextxy(645, 150, copyRight);
	outtextxy(645, 180, finishWorkDate);

	char strsec[10];
	int sec = 40 - (GetTickCount() - t) / 1000;
	itoa(sec, strsec, 10);
	outtextxy(750, 80, "      ");
	outtextxy(750, 80, strcat(strsec, "s"));
	
	return sec;
}	

void fish::defen(int sco)
{
	char strScore[10];		
	itoa(sco, strScore, 10);
	outtextxy(690, 110, strScore);
}

void fish::draw(int k)
{	
	int dx;
	if(k==1)
	{		
    	dx=rand() % 9;
    /*	for(;;)
		{
			dx=rand() % 9;
	     	if(last!=8&&last!=1)
			{
				if((last-dx)<=1&&(last-dx)>=-1)
				{
					break;
				}
			}
			else if(last==8)
			{
				if(dx==7||dx==1||dx==8)
				{
					break;
				}
			}
			else if(last==1)
			{
				if(dx==8||dx==1||dx==2)
				{
					break;
				}
			}
		}	*/	
		if(dx==1)
		{
			m=20;
		    n=0;
		}
		else if(dx==2)
		{
			m=20;
	    	n=20;		
		}
		else if(dx==3)
		{
			m=0;
		    n=20;
		}
		else if(dx==4)
		{
			m=-20;
		    n=20;		
		}
	    else if(dx==5)
		{
		    m=-20;
	    	n=0;
		}
	    else if(dx==6)
		{
		    m=-20;
	        n=-20;			
		}
	    else if(dx==7)
		{
		    m=0;
		    n=-20;
		}
	    else if(dx==8)
		{
		    m=20;
		    n=-20;
		}
	    last=dx;
	}

	x+=m;
	y+=n;

	if(x<8)
	{
		x=632;
	}
	if(x>632)
	{
		x=8;
	}
	if(y<8)
	{
		y=472;
	}
	if(y>472)
	{
		y=8;
	}

	fillcircle(x,y,8);
	FlushBatchDraw();
}