#include <iostream>
#include "Forest.h"
#include "Bst.h"
using namespace std;

int main()
{
	Forest<int> forest;
	forest.SetUp();
	BST<int> *bst = forest.ToBst();
	bst->display();
	bst->treeprint();
	delete bst;
	return 0;
}
