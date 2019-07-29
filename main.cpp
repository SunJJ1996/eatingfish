#include <graphics.h>
#include <conio.h>
#include<iostream>
#include"fish.h"
#include"1fen.h"
#include"2fen.h"
#include"bigfish.h"
#include"eat.h"
using namespace std;
#define	CMD_LEFT		1
#define	CMD_RIGHT		2
#define	CMD_UP		    3
#define CMD_DOWN        4
#define CMD_QUIT        5
int main()
{
	initgraph(900, 480);
	bigfish a;
	eat e1;

	return e1.eatfish(a);

}