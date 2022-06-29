#include "Functions.h"
#include "Node.h"
using namespace std;

int main()
{
	string formula = "((a*(b+c))/d)";

	Tree Tree(formula);
	Tree.printGivenLevel(3);
	Tree.printTree();
	Tree.clearMemory();

	return 0;
}