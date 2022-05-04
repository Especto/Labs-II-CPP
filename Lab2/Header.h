#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;


struct Date{unsigned short d, m, y; };
struct Technic{
    char name[20];
    Date dateOfBuy;
    unsigned short guarant;
};
extern Technic a;

void createFile(string);
bool showFile(string);
void enterFile(string);
void outExpired(string, string);
bool guarantee(int, int, int, int);
int JDN(int, int, int);