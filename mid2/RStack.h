#pragma once
#include <algorithm>
#include <iostream>
#define MAX_STACK_SIZE 5

template <typename T>
class RStack
{
public:
	RStack(int size);
	bool IsFull();
	bool IsEmpty();
	void Push(T val);
	void Pop();
	void Reverse();
	void Print();
private:
	T m_Data[MAX_STACK_SIZE];
	int m_Top;
	int m_Size;
};

template<typename T>
inline RStack<T>::RStack(int size)
{
	m_Top = -1;
	m_Size = std::min(size, MAX_STACK_SIZE);
}

template<typename T>
inline bool RStack<T>::IsFull()
{
	return m_Top + 1 == m_Size;
}

template<typename T>
inline bool RStack<T>::IsEmpty()
{
	return m_Top == -1;
}

template<typename T>
inline void RStack<T>::Push(T val)
{
	if (IsFull())
		throw "Stack is full.";
	m_Data[++m_Top] = val;
}

template<typename T>
inline void RStack<T>::Pop()
{
	if (IsEmpty())
		throw "Stack is empty.";
	--m_Top;
}

template<typename T>
inline void RStack<T>::Reverse()
{
	int left = 0, right = m_Top;
	while (left < right)
	{
		std::swap(m_Data[left], m_Data[right]);
		++left;
		--right;
	}
}

template<typename T>
inline void RStack<T>::Print()
{
	for (int i = 0; i <= m_Top; ++i)
		std::cout << m_Data[i] << " ";
	std::cout << std::endl;
}
