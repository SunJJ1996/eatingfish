#include"fish.h"
#include"bigfish.h"
#ifndef __ONEFEN_H__
#define __ONEFEN_H__
class onefen:public fish
{
	int a;
	int b;
public:
	onefen();

	int getScore();
    void draw(int k);
	int getX();
	int getY();
	void setx(int m);
	void sety(int n);
};

#endif