#include "Functions.h"

using namespace std;

bool isOperation(char symb)
{
	if (symb == '+' || symb == '-' || symb == '*' || symb == '/')
		return true;
	return false;
}