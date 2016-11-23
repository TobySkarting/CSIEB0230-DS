#include <iostream>
#include "Tree.h"

using namespace std;
int main()
{
	Tree<int> t;
	
	t.root = new TreeNode<int>(1, 0, 0);
	t.root->LeftChild = new TreeNode<int>(2, 0, 0);
	t.root->RightChild = new TreeNode<int>(3, 0, 0);
	t.root->LeftChild->LeftChild = new TreeNode<int>(4, 0, 0);
	t.root->LeftChild->RightChild = new TreeNode<int>(5, 0, 0);
	t.root->LeftChild->LeftChild->LeftChild = new TreeNode<int>(6, 0, 0);
	t.root->LeftChild->LeftChild->RightChild = new TreeNode<int>(7, 0, 0);
	t.root->LeftChild->LeftChild->LeftChild->LeftChild = new TreeNode<int>(8, 0, 0);
	t.root->LeftChild->LeftChild->LeftChild->RightChild = new TreeNode<int>(9, 0, 0);
	
	t.inorder();
	cout << endl;
	t.preorder();
	cout << endl;
	t.postorder();
	cout << endl;

	return 0;
}

