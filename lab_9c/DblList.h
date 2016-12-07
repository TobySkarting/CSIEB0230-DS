#pragma once
#include <iostream>

template <typename T> class DblList;

std::ostream& operator<<(std::ostream &os, const DblList<int> &list);

template <typename T>
class DblListNode {
	template <typename U> friend class DblList;
	friend std::ostream& operator<<(std::ostream &os, const DblList<int> &list);
public:
	T data;
	DblListNode *llink, *rlink;
};

template <typename T>
class DblList {
	friend std::ostream& operator<<(std::ostream &os, const DblList<int> &list);
public:
	DblList(size_t size = 5)
	{
		m_Count = 0;
		m_Size = size;
		m_First = new DblListNode<T>();
		m_First->llink = m_First;
		m_First->rlink = m_First;
	}
	~DblList()
	{
		if (!IsEmpty())
			DeleteFront();
		delete m_First;
	}
	void AddFront(T data);
	void AddRear(T data);
	void AddMiddle(T data);
	T DeleteFront();
	T DeleteRear();
	T DeleteMiddle();
	bool IsEmpty();
	bool IsFull();
	bool IsSymmetric();
	void Shift(char dir, int count);
	void Insert(DblListNode<T>*, DblListNode<T>*);
	void Delete(DblListNode<T>*);
protected:
	DblListNode<T> *m_First;  // points to head node
private:
	size_t m_Count;
	size_t m_Size;
};

template<typename T>
inline void DblList<T>::AddFront(T data)
{
	if (IsFull())
	{
		std::cerr << "[ERROR] The list is full." << std::endl;
		return;
	}
	DblListNode<T> *newNode = new DblListNode<T>();
	newNode->data = data;
	Insert(newNode, m_First);
	++m_Count;
}

template<typename T>
inline void DblList<T>::AddRear(T data)
{
	if (IsFull())
	{
		std::cerr << "[ERROR] The list is full." << std::endl;
		return;
	}
	DblListNode<T> *newNode = new DblListNode<T>();
	newNode->data = data;
	Insert(newNode, m_First->llink);
	++m_Count;
}

template<typename T>
inline void DblList<T>::AddMiddle(T data)
{
	if (IsFull())
	{
		std::cerr << "[ERROR] The list is full." << std::endl;
		return;
	}
	DblListNode<T> *node = m_First;
	for (int i = 0; i < m_Count / 2; ++i)
		node = node->rlink;
	DblListNode<T> *newNode = new DblListNode<T>();
	newNode->data = data;
	Insert(newNode, node);
	++m_Count;
}

template<typename T>
inline T DblList<T>::DeleteFront()
{
	if (IsEmpty())
	{
		std::cerr << "[ERROR] The list is empty." << std::endl;
		return T();
	}
	T data = m_First->rlink->data;
	Delete(m_First->rlink);
	--m_Count;
	return data;
}

template<typename T>
inline T DblList<T>::DeleteRear()
{
	if (IsEmpty())
	{
		std::cerr << "[ERROR] The list is empty." << std::endl;
		return T();
	}
	T data = m_First->llink->data;
	Delete(m_First->llink);
	--m_Count;
	return data;
}

template<typename T>
inline T DblList<T>::DeleteMiddle()
{
	if (IsEmpty())
	{
		std::cerr << "[ERROR] The list is empty." << std::endl;
		return T();
	}
	DblListNode<T> *node = m_First;
	for (int i = 0; i < m_Count / 2 + 1; ++i)
		node = node->rlink;
	T data = node->data;
	Delete(node);
	--m_Count;
	return data;
}

template<typename T>
inline bool DblList<T>::IsEmpty()
{
	return m_First == m_First->llink;
}

template<typename T>
inline bool DblList<T>::IsFull()
{
	return (m_Count == m_Size);
}

template<typename T>
inline bool DblList<T>::IsSymmetric()
{
	DblListNode<T> *left, *right;
	left = m_First->llink;
	right = m_First->rlink;
	while (left != right)
	{
		if (left->data != right->data)
			return false;
		left = left->rlink;
		right = right->llink;
	}
	return true;
}

template<typename T>
inline void DblList<T>::Shift(char dir, int count)
{
	m_First->rlink->llink = m_First->llink;
	m_First->llink->rlink = m_First->rlink;
	DblListNode<T> *node = m_First->llink;
	if (dir == 'r')
		for (int i = 0; i < count; ++i)
			node = node->llink;
	else
		for (int i = 0; i < count; ++i)
			node = node->rlink;
	Insert(m_First, node);
}

template <typename T>
void DblList<T>::Insert(DblListNode<T> *p, DblListNode<T> *x)
// insert node @p@ to the right of node @x@
{
	p->llink = x;
	p->rlink = x->rlink;
	x->rlink->llink = p;
	x->rlink = p;
}

template <typename T>
void DblList<T>::Delete(DblListNode<T> *x)
{
	if (x == m_First)
		std::cerr << "Deletion of head node not permitted." << std::endl;
	else
	{
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		delete x;
	}
}
