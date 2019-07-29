#include"fish.h"
#include"bigfish.h"
#ifndef __TWOFEN_H__
#define __TWOFEN_H__

class twofen:public fish
{
	int a;
	int b;
public:
	twofen();
	
	int getScore();
    void draw(int k);
	int getX();
	int getY();
};

#endif