#include <iostream>

const int DefaultSize = 20;

class MaxPQ {
public:
	virtual void Insert(const int) = 0;
	virtual int* DeleteMax(int&) = 0;
};

class SearchStruct {
public:
	virtual void Insert(const int) = 0;
	virtual int* Delete(int&) = 0;
	virtual bool Search(const int) = 0;
};

class BinaryTree {
public:
	virtual void inorder();
	virtual void preorder();
	virtual void setup();
	BinaryTree() { root = 0; };
protected:
	class BinaryTreeNode {
	public:
		BinaryTreeNode *LeftChild;
		int data;
		BinaryTreeNode *RightChild;
		BinaryTreeNode(int i, BinaryTreeNode *l, BinaryTreeNode *r)
		{
			data = i;
			LeftChild = l;
			RightChild = r;
		}
	};
	BinaryTreeNode *root;
	virtual void inorder(BinaryTreeNode *);
	virtual void preorder(BinaryTreeNode *);
};

void BinaryTree::inorder()
{
	inorder(root);
}

void BinaryTree::inorder(BinaryTreeNode *CurrentNode)
{
	if (CurrentNode) {
		inorder(CurrentNode->LeftChild);
		std::cout << CurrentNode->data;
		inorder(CurrentNode->RightChild);
	}
}

void BinaryTree::preorder()
{
	preorder(root);
}

void BinaryTree::preorder(BinaryTreeNode *CurrentNode)
{
	if (CurrentNode) {
		std::cout << CurrentNode->data;
		inorder(CurrentNode->LeftChild);
		inorder(CurrentNode->RightChild);
	}
}

class CompleteBinaryTree : public BinaryTree
{
public:
	virtual void inorder(); // hides BinaryTree::inorder
	virtual void preorder(); // hides BinaryTree::inorder
	virtual void setup();
	CompleteBinaryTree(int sz = DefaultSize) : MaxSize(sz), n(0) {
		tree = new int[MaxSize + 1];
	};
protected:
	int *tree, MaxSize, n;
	virtual void inorder(int); // hides BinaryTree::inorder
	virtual void preorder(int); // hides BinaryTree::inorder
};

void CompleteBinaryTree::inorder()
{
	inorder(1);
}

void CompleteBinaryTree::inorder(int current)
{
	if (current <= n) {
		inorder(2 * current);
		std::cout << tree[current];
		inorder(2 * current + 1);
	}
}

void CompleteBinaryTree::preorder()
{
	preorder(1);
}

void CompleteBinaryTree::preorder(int current)
{
	if (current <= n) {
		std::cout << tree[current];
		preorder(2 * current);
		preorder(2 * current + 1);
	}
}

class MaxHeap : public MaxPQ, public CompleteBinaryTree
{
public:
	MaxHeap(int sz = DefaultSize) : CompleteBinaryTree(sz) {};
	virtual void Insert(const int);
	virtual int* DeleteMax(int&);
};

class WinnerTree : public CompleteBinaryTree
{
public:
	WinnerTree(int sz = DefaultSize) : CompleteBinaryTree(sz) {};
};

void MaxHeap::Insert(const int i) {}

int* MaxHeap::DeleteMax(int& i) { return &i; }

class BST : public SearchStruct, public BinaryTree
{
public:
	BST() { root = 0; };
	virtual void Insert(const int);
	virtual int* Delete(int&);
	virtual bool Search(const int);
};

void BST::Insert(const int i)
{}

bool BST::Search(const int i)
{
	return true;
}

int* BST::Delete(int& i)
{
	return &i;
}

void BinaryTree::setup()
{
	root = new BinaryTreeNode(10, 0, 0);
	root->LeftChild = new BinaryTreeNode(5, 0, 0);
	root->LeftChild->LeftChild = new BinaryTreeNode(2, 0, 0);
	root->LeftChild->RightChild = new BinaryTreeNode(8, 0, 0);
	root->LeftChild->LeftChild->LeftChild = new BinaryTreeNode(1, 0, 0);
}

void CompleteBinaryTree::setup()
{
	tree[1] = 1; tree[2] = 2; tree[3] = 3;
	tree[4] = 4; tree[5] = 5; n = 5;
}
