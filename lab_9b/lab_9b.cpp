#include <iostream>
#include "Hier.h"

using namespace std;

int main()
{
	BST bst;
	CompleteBinaryTree cbt(5);
	MaxHeap h(5);
	BinaryTree b;

	cbt.setup();
	b.setup();
	h.setup();
	bst.setup();

	cout << "CompleteBinaryTree inorder:" << endl;
	cbt.inorder();
	cout << endl;
	cout << "CompleteBinaryTree preorder:" << endl;
	cbt.preorder();
	cout << endl;
	cout << "BinaryTree inorder:" << endl;
	b.inorder();
	cout << endl;
	cout << "BinaryTree preorder:" << endl;
	b.preorder();
	cout << endl;
	return 0;
}
