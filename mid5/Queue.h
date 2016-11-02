#include <iostream>
const int DefaultSize = 10;
enum Boolean { FALSE, TRUE };

template <class KeyType>
class Queue
{
	// \fBobjects\fR: A finite ordered list with zero or more elements.
public:
	Queue(int MaxQueueSize = DefaultSize);
	// Create an empty queue whose maximum size is \fIMaxQueueSize\fR

	Boolean IsFull();
	// if number of elements in the queue is equal to the maximum size of
	//   the queue, return TRUE (1); otherwise, return FALSE (0)

	void Add(const KeyType& item);
	// if IsFull(), then QueueFull(); else insert item into the top of the queue.

	Boolean IsEmpty();
	// if number of elements in the queue is equal to 0, return TRUE (1) else return FALSE (0).

	KeyType* Delete(KeyType&);
	// if IsEmpty(), then QueueEmpty(); else remove and return the topmost element of the Queue

	void QueueEmpty() { std::cout << "empty" << std::endl; };
	void QueueFull() { std::cout << "full" << std::endl; };
	void Output();
protected:
	int front;
	int rear;
	KeyType *queue;
	int MaxSize;
};

template <class KeyType>
Queue<KeyType>::Queue(int MaxQueueSize) : MaxSize(MaxQueueSize)
{
	queue = new KeyType[MaxSize];
	front = rear = -1;
}

template <class KeyType>
inline Boolean  Queue<KeyType>::IsFull()
{
	if (rear == MaxSize - 1) return TRUE;
	else return FALSE;
}

template <class KeyType>
inline Boolean  Queue<KeyType>::IsEmpty()
{
	if (front == rear) return TRUE;
	else return FALSE;
}

template <class KeyType>
void Queue<KeyType>::Add(const KeyType& x)
// add x to the queue
{
	if (IsFull()) QueueFull();
	else queue[++rear] = x;
}

template <class KeyType>
KeyType* Queue<KeyType>::Delete(KeyType& x)
// remove and return front element from queue
{
	if (IsEmpty()) { QueueEmpty(); return 0; }
	x = queue[++front];
	return &x;
}

template <class KeyType>
void Queue<KeyType>::Output()
{
	std::cout << "front = " << front << "rear = " << rear << std::endl;
	for (int i = front + 1; i <= rear; i++)
		std::cout << i << ":" << queue[i] << std::endl;
}
