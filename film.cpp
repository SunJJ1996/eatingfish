#include "film.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <graphics.h>
#include <conio.h>
using namespace std;

film::film()
{
	for(int i=0;i<=5;i++)
	{
		score[i]="0";
		line[i]=0;
	}
}

void film::read()
{
	int i=0;
	char strScore[10];
	ifstream fin;
	fin.open("score.txt");

	while(getline(fin,score[i]))
	{
		i++;
	}
	fin.close();

	outtextxy(645, 250, "TOP.5");

	for(i=0;i<=5;i++)
	{
		line[i]= atoi(score[i].c_str());
	
	}
	
	outtextxy(645, 300, "NO.1");
	itoa(line[0], strScore, 10);
	outtextxy(695, 300, strScore);
	
	outtextxy(645, 330, "NO.2");
	itoa(line[1], strScore, 10);
	outtextxy(695, 330, strScore);
	
	outtextxy(645, 360, "NO.3");
	itoa(line[2], strScore, 10);
	outtextxy(695, 360, strScore);
	
	outtextxy(645, 390, "NO.4");
	itoa(line[3], strScore, 10);
	outtextxy(695, 390, strScore);
	
	outtextxy(645, 420, "NO.5");
	itoa(line[4], strScore, 10);
	outtextxy(695, 420, strScore);
}

int film::write(int sco)
{
	int i=0;
	line[5]=sco;
	ofstream fout;

	for(i=0;i<=4;i++)
	{
		for(int j=i+1;j<=5;j++)
		{
			if(line[i]<=line[j])
			{
				int m=line[j];
				line[j]=line[i];
				line[i]=m;
			}
		}
	}

	fout.open("score.txt"); 
	i=0;
	do
	{
		if(i<=4)
		{
			fout<<line[i]<<endl;
		}
		if(i==5)
		{
			fout<<line[i];
		}
		i++;
	}while(i<=5);
	fout.close();
	return 0;
}
