
#ifndef __FISH_H__
#define __FISH_H__
#include<iostream>
#include<string>
using namespace std;
class fish
{
private:
	int score;

public:
	int x,y;
	int m,n;
	int last;

	fish();
	fish(int x,int y);
	int getCommand();
	int keynote;
	int eaten(int m,int n);

	void defen(int sco);

	virtual void draw(int k);

	virtual int getScore();	
	virtual int getX();
	virtual int getY();
	virtual void setx(int m);
	virtual void sety(int n);
	virtual int menu(int t);
	fish * next;	
};
#endif
