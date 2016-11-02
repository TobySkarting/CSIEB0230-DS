#include "Stack.h"

template <typename T>
class LRUBuffer : public Stack<T>
{
public:
	LRUBuffer(int MaxStackSize = DefaultSize);
	void Add(const T& item);
	bool Test(const T& item);
	void Output();
};

template <typename T>
LRUBuffer<T>::LRUBuffer(int MaxStackSize = DefaultSize) : Stack<T>(MaxStackSize)
{

}

template <typename T>
void LRUBuffer<T>::Add(const T& item)
{
	if (IsFull())
	{
		StackFull();
		return;
	}
	for (int i = 0; i <= top; i++)
		if (item == stack[i])
		{
			// touch the item
			for (int j = i; j <= top - 1; ++j)
				std::swap(stack[j], stack[j + 1]);
			return;
		}
	Stack<T>::Add(item);
}

template <typename T>
bool LRUBuffer<T>::Test(const T& item)
{
	for (int i = 0; i <= top; i++)
		if (item == stack[i])
		{
			// touch the item
			for (int j = i; j <= top - 1; ++j)
				std::swap(stack[j], stack[j + 1]);
			return true;
		}
	return false;
}

template <typename T>
void LRUBuffer<T>::Output()
{
	for (int i = 0; i <= top; i++)
		cout << stack[i] << " ";
	cout << endl;
}

