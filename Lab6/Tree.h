#pragma once
#include "Node.h"
using namespace std;

class Tree
{
	Node* createTree(string& formula, int& index);
	void printTree(Node* node, int level);
	void clearMemory(Node* node);
	void printGivenLevel(Node* node, int level);

public:
	Node* Root;

	Tree(string& formula);

	void printTree();
	void clearMemory();
	void printGivenLevel(int level);
};