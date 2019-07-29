#include"bigfish.h"
#include <graphics.h>
#include <conio.h>
#include<iostream>
#define	CMD_LEFT		1
#define	CMD_RIGHT		2
#define	CMD_UP		    3
#define CMD_DOWN        4
#define CMD_QUIT        5
bigfish::bigfish():fish(200,300)
{	
}

int bigfish::bigmove()
{

	int dx=0,dy=0;

	setfillcolor(RGB(1000,100,200));
	fillcircle(x, y, 15);
	FlushBatchDraw();
	
	
	fish c;
	if (c.getCommand() & c.keynote==CMD_LEFT)	dx = -20;
	if (c.getCommand() & c.keynote==CMD_RIGHT)	dx =  20;
	if (c.getCommand() & c.keynote==CMD_UP)		dy = -20;
	if (c.getCommand() & c.keynote==CMD_DOWN)	dy =  20;

	if (c.getCommand() & c.keynote==CMD_QUIT)	return 1;
		
	y += dy;	
	x += dx;
 		
	if(x < 15)  x = 15;
	if(y < 15)  y = 15;
	if(x > 625) x = 625;	
	if(y > 465) y = 465;

	return 0;
}

int bigfish::getX()
{
	return x;
}
int bigfish::getY()
{
	return y;
}


