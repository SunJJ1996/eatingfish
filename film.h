#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;

class film
{
public:
	string score[6];
	int line[6];

	film();
	void read();
    int write(int soc);
};
