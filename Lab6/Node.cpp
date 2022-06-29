#include "Node.h"

Node::Node()
{
	this->key = ' ';
	left = NULL;
	right = NULL;
}
Node::Node(char key)
{
	this->key = key;
	left = NULL;
	right = NULL;
}

void Node::setKey(char key)
{
	this->key = key;
}
char Node::getKey()
{
	return key;
}