#pragma once
#include "Bst.h"

template <typename T>
class ForestNode
{
	template <typename U> friend class Forest;
public:
	ForestNode(T data, ForestNode<T> *l = NULL, ForestNode<T> *m = NULL, ForestNode<T> *r = NULL)
		: data(data), LeftNode(l), MiddleNode(m), RightNode(r) {}
private:
	T data;
	ForestNode<T> *LeftNode;
	ForestNode<T> *MiddleNode;
	ForestNode<T> *RightNode;
};

template <typename T>
class ForestNodeIterator
{
public:
	ForestNodeIterator(ForestNode<T> *node)
	{
		m_Node = node;
		m_Stage = 0;
	}
	ForestNode<T> *Begin()
	{
		if (m_Node->LeftNode != NULL)
		{
			m_Stage = 1;
			return m_Node->LeftNode;
		}
		if (m_Node->MiddleNode != NULL)
		{
			m_Stage = 2;
			return m_Node->MiddleNode;
		}
		if (m_Node->RightNode != NULL)
		{
			m_Stage = 3;
			return m_Node->RightNode;
		}
		return NULL;
	}
	ForestNode<T> *Next()
	{
		if (m_Stage <= 0 && m_Node->LeftNode != NULL)
		{
			m_Stage = 1;
			return m_Node->LeftNode;
		}
		if (m_Stage <= 1 && m_Node->MiddleNode != NULL)
		{
			m_Stage = 2;
			return m_Node->MiddleNode;
		}
		if (m_Stage <= 2 && m_Node->RightNode != NULL)
		{
			m_Stage = 3;
			return m_Node->RightNode;
		}
		return NULL;
	}
private:
	ForestNode<T> *m_Node;
	int m_Stage;
};

template <typename T>
class Forest
{
public:
	void SetUp();
	BST<T> * ToBst();
	void AddToBst(BST<T> *bst, ForestNode<T> *);
private:
	ForestNode<T> *Root;
};

template<typename T>
inline void Forest<T>::SetUp()
{
	Root = new ForestNode<T>(5, new ForestNode<T>(2), new ForestNode<T>(7), new ForestNode<T>(8));
	Root->LeftNode->MiddleNode = new ForestNode<T>(3, new ForestNode<T>(0), new ForestNode<T>(1));
}

template<typename T>
inline BST<T>* Forest<T>::ToBst()
{
	BST<T> *bst = new BST<T>;
	AddToBst(bst, Root);
	return bst;
}

template<typename T>
inline void Forest<T>::AddToBst(BST<T>* bst, ForestNode<T>* node)
{
	if (node == NULL)
		return;
	bst->Add(node->data);
	AddToBst(bst, node->LeftNode);
	AddToBst(bst, node->MiddleNode);
	AddToBst(bst, node->RightNode);
}
