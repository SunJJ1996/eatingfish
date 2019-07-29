#include"1fen.h"
#include <graphics.h>
#include <conio.h>
#include<iostream>
onefen::onefen():fish(20 + rand() % 32,200 + rand() % 32)
{
	a=20 + rand() % 32;
	b=200 + rand() % 32;
	last=4;
}
int onefen::getScore()
{
	return 1;
}
int onefen::getX()
{
	return x;
}
int onefen::getY()
{
	return y;
}
void onefen::setx(int m)
{
	x=m;
}
void onefen::sety(int n)
{
	y=n;
}

void onefen::draw(int k)
{	
	int dx;
	if(k==1)
	{		
    	for(;;)
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
		}		
		if(dx==1)
		{
			m=10;
		    n=0;
		}
		else if(dx==2)
		{
			m=10;
	    	n=10;		
		}
		else if(dx==3)
		{
			m=0;
		    n=10;
		}
		else if(dx==4)
		{
			m=-10;
		    n=10;		
		}
	    else if(dx==5)
		{
		    m=-10;
	    	n=0;
		}
	    else if(dx==6)
		{
		    m=-10;
	        n=-10;			
		}
	    else if(dx==7)
		{
		    m=0;
		    n=-10;
		}
	    else if(dx==8)
		{
		    m=10;
		    n=-10;
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
	setfillcolor(RGB(357,1020,127));
	fillcircle(x,y,8);
	FlushBatchDraw();
}

