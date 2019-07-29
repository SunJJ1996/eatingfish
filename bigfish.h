#include"fish.h"
#ifndef __BIGFISH_H__
#define __BIGFISH_H__

class bigfish:public fish
{
	
public:
	bigfish();

	int bigmove();
	int getX();
	int getY();
};
#endif


