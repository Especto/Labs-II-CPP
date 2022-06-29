#pragma once
#include <string>
using namespace std;

class Node
{
	char key;

public:
	Node* left,
		* right;

	Node();
	Node(char key);

	void setKey(char key);
	char getKey();
};