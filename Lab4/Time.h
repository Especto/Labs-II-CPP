#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Time {
	int h, m, s, number;
	static int count;
public:
	Time();
	Time(const Time &time);
	Time(string);
	Time(int, int, int);
	int getH();
	int getM();
	int getS();
	void printTime();
	string strTime();

	void left();
	Time& operator +=(int);
	Time& operator -(Time);
	~Time();
};

