#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include "eat.h"
#include "film.h"
using namespace std;
eat::eat()
{}

int eat::eatfish(bigfish a)
{
	srand(time(NULL));
	int t=GetTickCount();
	char str[] = "your score:";

	fish mea;
	film f;
	mea.menu(t);
	fish *head=new fish;
	int no=rand ()%2;
	int kk=10;
	int k=1;
	int NO=0;
	int score=0;

	bool flag=true;
	fish *s=head;

	
	for(int i=1;i<=10;i++)
	{
		int num=rand ()%2;
		switch(num)
		{
	case 0:
		s->next = new onefen;
	    s		= s->next; 
		s->next = NULL;
		break;
	case 1:
		s->next = new twofen;
	    s		= s->next;
		s->next = NULL;
		break;
		}
	}

	f.read();
	while(flag)
	{
		clearrectangle(0, 0, 640, 480);

		if (!mea.menu(t)) flag = false;	
		if(a.bigmove()) flag = false;
		
		if(k>=4)
		{
			k=1;
		}
	   
		for(fish *d=head->next;d!=NULL;d=d->next)
			{	
				d->draw(k);				
			}
		k++;

		for(fish *c=head;c!=NULL;c=c->next)
		{
		    s=c->next;
		    if(s!=NULL&&s->eaten(a.getX(),a.getY())==1)
			{
				score+=s->getScore();
				s->defen(score);
		 	    c->next=s->next ;
				kk--;				
			}			
		}
		
		
		
		fish *e=head;s=e->next;
		if(s==NULL)
		{
			flag = false;
		}
		Sleep(100);
	}

	f.write(score);

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	char strScore[10];
	itoa(score, strScore, 10);
	outtextxy(222, 240, strcat(str, strScore));
	outtextxy(220, 300, "按任意键退出");
	EndBatchDraw();

	Sleep(1000);

	getch();
	closegraph();

	return 0;
}
