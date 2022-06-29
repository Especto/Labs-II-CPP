#include "Tree.h"
#include "Functions.h"
using namespace std;

Tree::Tree(string& formula)
{
	int index = 0;
	Root = createTree(formula, index);
}
Node* Tree::createTree(string& formula, int& index)
{
	Node* node = new Node();
	while (index < formula.size()) {
		if (formula[index] == ')') {
			return node;
		}
		if (formula[index] == '(') {
			node->left = createTree(formula, ++index);
			index++;
		}
		if (isalpha(formula[index])) {
			node->setKey(formula[index]);
			return node;
		}
		if (isOperation(formula[index])) {
			node->setKey(formula[index]);
			node->right = createTree(formula, ++index);
			index++;
		}
	}
	return node;
}

void Tree::printTree(Node* node, int level)
{
	if (node != NULL) {
		printTree(node->right, level + 1);
		for (int i = 0; i < level; ++i) {
			cout << "\t";
		}
		cout << "  " << node->getKey() << "\n";
		printTree(node->left, level + 1);
	}
}
void Tree::printTree()
{
	cout << "Tree: \n";
	printTree(Root, 0);
	cout << endl;
}

void Tree::clearMemory(Node* node)
{
	if (node->left == NULL && node->right == NULL) {
		free(node);
		return;
	}
	if (node->left != NULL) {
		clearMemory(node->left);
	}
	if (node->right != NULL) {
		clearMemory(node->right);
	}
}
void Tree::clearMemory()
{
	clearMemory(Root);
}

void Tree::printGivenLevel(Node* node, int level)
{
	
	if (node == NULL)
		return;
	if (level == 1)
		cout << node->getKey() << endl;
	else if (level > 1)
	{
		printGivenLevel(node->left, level - 1);
		printGivenLevel(node->right, level - 1);
	}
}

void Tree::printGivenLevel(int level) {
	cout << "Keys on the " << level << " level:\n";
	printGivenLevel(Root, level);
	cout << endl;
}
