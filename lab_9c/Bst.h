#pragma once
#include <iostream>

template <class Type>
class Element {
public:
	Type key;
};

template <class Type>
class BstNode {
	template <typename T> friend class BST;
public:
	Type GetKey()
	{
		return data.key;
	}
public:
	Element<Type> data;
	BstNode *LeftChild, *RightChild;
	void display(int i);
	void treeprint(int i);
};

template <class Type>
class BST {
public:
	BST(BstNode<Type> *init = 0) { root = init; };

	//   BST& operator=(const BST&);
	void Add(Type data);
	bool Insert(const Element<Type>& x);
	//   bool Delete(const Element<Type>&);
	BstNode<Type>* Search(BstNode<Type>*, const Element<Type>&);
	BstNode<Type>* Search(const Element<Type>&);
	BstNode<Type>* IterSearch(const Element<Type>&);

	void treeprint() { cout << "\n"; root->treeprint(1); }

	void display() {
		cout << "\n";
		if (root) root->display(1);
		else cout << "0\n";
	};
	Element<Type>* Split(Type i, BST& B, BST& C, Element<Type> &x);
	BstNode<Type>* SearchByRank(int rank);
	BstNode<Type>* RankInOrder(BstNode<Type> *node, int &rank);
	void Delete(Type key);
public:
	BstNode<Type> *root;
};

template <class Type>
void BstNode<Type>::display(int i)
{
	cout << "Position " << i << ": data.key " << data.key << "\n";
	if (LeftChild) LeftChild->display(2 * i);
	if (RightChild) RightChild->display(2 * i + 1);
};

template <class Type>
Element<Type>* BST<Type>::Split(Type i, BST<Type>& B, BST<Type>& C,
	Element<Type> &x)
	// Split the binary search tree with respect to key @i@
{
	if (!root) { B.root = C.root = 0; return 0; } // empty tree
	BstNode<Type> *Y = new BstNode<Type>; BstNode<Type> *L = Y;
	BstNode<Type> *Z = new BstNode<Type>; BstNode<Type> *R = Z;
	BstNode<Type> *t = root;
	while (t)
		if (i == t->data.key) {  // split at @t@
			L->RightChild = t->LeftChild;
			R->LeftChild = t->RightChild;
			x = t->data;
			B.root = Y->RightChild; delete Y;
			C.root = Z->LeftChild; delete Z;
			return &x;
		}
		else if (i < t->data.key) {
			R->LeftChild = t;
			R = t; t = t->LeftChild;
		}
		else {
			L->RightChild = t;
			L = t; t = t->RightChild;
		}
		L->RightChild = R->LeftChild = 0;
		B.root = Y->RightChild; delete Y;
		C.root = Z->LeftChild; delete Z;
		return 0;
}

template<class Type>
inline BstNode<Type>* BST<Type>::SearchByRank(int rank)
{
	return RankInOrder(root, rank);
}

template<class Type>
inline BstNode<Type>* BST<Type>::RankInOrder(BstNode<Type> *node, int & rank)
{
	if (node == NULL)
		return NULL;
	BstNode<Type> *result;
	result = RankInOrder(node->LeftChild, rank);
	if (result != NULL)
		return result;
	if (--rank == 0)
		return node;
	result = RankInOrder(node->RightChild, rank);
	if (result != NULL)
		return result;
	return NULL;
}

template<class Type>
inline void BST<Type>::Delete(Type key)
{
	BstNode<Type> *currentNode = root;
	BstNode<Type> *parentNode = root;
	while (currentNode != NULL)
		if (key < currentNode->data.key)
		{
			parentNode = currentNode;
			currentNode = currentNode->LeftChild;
		}
		else if (key > currentNode->data.key)
		{
			parentNode = currentNode;
			currentNode = currentNode->RightChild;
		}
		else
		{
			BstNode<Type> **pChild;
			if (parentNode->LeftChild == currentNode)
				pChild = &parentNode->LeftChild;
			else if (parentNode->RightChild == currentNode)
				pChild = &parentNode->RightChild;

			if (currentNode->LeftChild == NULL && currentNode->RightChild == NULL)
			{
				*pChild = NULL;
				delete currentNode;
			}
			else if (currentNode->LeftChild != NULL && currentNode->RightChild == NULL)
			{
				*pChild = currentNode->LeftChild;
				delete currentNode;
			}
			else if (currentNode->LeftChild == NULL && currentNode->RightChild != NULL)
			{
				*pChild = currentNode->RightChild;
				delete currentNode;
			}
			else
			{
				BstNode<Type> **pNode;
				for (BstNode<Type> **pNode = &currentNode->LeftChild; (*pNode)->RightChild != NULL; pNode = &(*pNode)->RightChild);
				currentNode->data.key = (*pNode)->data.key;
				delete *pNode;
				*pNode = (*pNode)->LeftChild;
			}
			break;
		}
}

template <class Type>
void BstNode<Type>::treeprint(int l)
{
	if (this) {
		(this->RightChild)->treeprint(l + 1);
		for (int i = 1; i <= l; i++) cout << "   ";
		cout << this->data.key << "\n";
		(this->LeftChild)->treeprint(l + 1);
	};
};

template <class Type>
BstNode<Type>* BST<Type>::Search(BstNode<Type>* b, const Element<Type> &x)
{
	if (!b) return 0;
	if (x.key == b->data.key) return b;
	if (x.key < b->data.key) return Search(b->LeftChild, x);
	return Search(b->RightChild, x);
};

template <class Type>
BstNode<Type>* BST<Type>::Search(const Element<Type>& x)
{
	return Search(root, x);
}

template <class Type>
BstNode<Type>* BST<Type>::IterSearch(const Element<Type>& x)
{
	for (BstNode<Type> *t = root; t; )
	{
		if (x.key == t->data.key) return t;
		if (x.key < t->data.key) t = t->LeftChild;
		else t = t->RightChild;
	}
	return 0;
}

template<class Type>
inline void BST<Type>::Add(Type data)
{
	Element<Type> element;
	element.key = data;
	Insert(element);
}

template <class Type>
bool BST<Type>::Insert(const Element<Type>& x)
{
	BstNode<Type> *p = root;  BstNode<Type> *q = 0;
	while (p) {
		q = p;
		if (x.key == p->data.key) return false; //x.key is already in t
		if (x.key < p->data.key) p = p->LeftChild;
		else p = p->RightChild;
	};

	p = new BstNode<Type>;
	p->LeftChild = p->RightChild = 0; p->data = x;
	if (!root) root = p;
	else if (x.key < q->data.key) q->LeftChild = p;
	else q->RightChild = p;
	return true;
}
