#include"2fen.h"
#include <graphics.h>
#include <conio.h>
#include<iostream>
twofen::twofen():fish(20 + rand() % 32,200 + rand() % 32)
{
	a=20 + rand() % 32;
	b=200 + rand() % 32;
	last=6;
}
int twofen::getScore()
{
	return 2;
}
int twofen::getX()
{
	return x;
}
int twofen::getY()
{
	return y;
}
void twofen::draw(int k)
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
			m=25;
		    n=0;
		}
		else if(dx==2)
		{
			m=25;
	    	n=25;		
		}
		else if(dx==3)
		{
			m=0;
		    n=25;
		}
		else if(dx==4)
		{
			m=-25;
		    n=25;		
		}
	    else if(dx==5)
		{
		    m=-25;
	    	n=0;
		}
	    else if(dx==6)
		{
		    m=-25;
	        n=-25;			
		}
	    else if(dx==7)
		{
		    m=0;
		    n=-25;
		}
	    else if(dx==8)
		{
		    m=25;
		    n=-25;
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
	setfillcolor(RGB(255,200,1207));
	fillcircle(x,y,8);
	FlushBatchDraw();
}