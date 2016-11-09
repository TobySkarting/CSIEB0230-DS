#include <iostream>

template <typename T>
class Queue;

template <typename T>
class QueueNode {
	template <typename U>
	friend class Queue;
	template <typename U>
	friend std::ostream& operator<<(std::ostream&, QueueNode<U>);
	template <typename U>
	friend std::ostream& operator<<(std::ostream&, Queue<U>);
private:
	T data;
	QueueNode *llink;
	QueueNode *rlink;
	QueueNode(const T &d = 0, QueueNode *l = NULL, QueueNode *r = NULL) : data(d), llink(l), rlink(r) {};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, QueueNode<T> n)
{
	os << n.data << std::endl;
	return os;
}

template <typename T>
class Queue {
	template <typename U>
	friend std::ostream& operator<<(std::ostream&, Queue<U>);
private:
	QueueNode<T> *front, *rear;
	void QueueEmpty() {};
public:
	Queue() { front = rear = NULL; };
	~Queue() {}
	bool IsEmpty();
	bool IsFull();
	void AddFront(const T);
	void AddRear(const T);
	T* DeleteFront(T&);
	T* DeleteRear(T&);
	void Reverse();
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Queue<T> l)
{
	QueueNode<T> *temp = l.front;
	while (temp)
	{
		os << (*temp);
		temp = temp->rlink;
	}
	return os;
}

template <typename T>
bool Queue<T>::IsEmpty()
{
	return front == NULL && rear == NULL;
}

template <typename T>
bool Queue<T>::IsFull()
{
	return false;
}

template <typename T>
void Queue<T>::AddFront(const T y)
{
	if (IsEmpty())
	{
		front = rear = new QueueNode<T>(y, NULL, NULL);
	}
	else
	{
		QueueNode<T> *node = new QueueNode<T>(y, NULL, front);
		front->llink = node;
		front = node;
	}
}

template <typename T>
void Queue<T>::AddRear(const T y)
{
	if (IsEmpty())
	{
		front = rear = new QueueNode<T>(y, NULL, NULL);
	}
	else
	{
		QueueNode<T> *node = new QueueNode<T>(y, rear, NULL);
		rear->rlink = node;
		rear = node;
	}
}

template <typename T>
T* Queue<T>::DeleteFront(T& retvalue)
// delete the first node in queue and return a pointer to its data
{
	if (front == NULL) { QueueEmpty(); return 0; };
	QueueNode<T> *x = front;
	retvalue = front->data; // get data
	front = front->rlink;      // delete front node
	if (front != NULL)
		front->llink = NULL;
	delete x; // free the node
	return &retvalue;
}

template <typename T>
T* Queue<T>::DeleteRear(T& retvalue)
// delete the first node in queue and return a pointer to its data
{
	if (rear == NULL) { QueueEmpty(); return 0; };
	QueueNode<T> *x = rear;
	retvalue = rear->data; // get data
	rear = rear->llink;      // delete front node
	if (rear != NULL)
		rear->rlink = NULL;
	delete x; // free the node
	return &retvalue;
}

template <typename T>
void Queue<T>::Reverse()
{
	QueueNode<T> *l = front, *r = rear;
	while (l != r)
	{
		std::swap(l->data, r->data);
		l = l->rlink;
		r = r->llink;
	}
}


using namespace std;

int main()
{
	int retvalue;
	Queue<int> s;
	s.AddFront(20);
	s.AddFront(35);
	s.AddRear(45);
	cout << s << endl;
	cout << "Reversed" << endl;
	s.Reverse();
	cout << s << endl;
	cout << "DeleteRear: " << *s.DeleteRear(retvalue) << endl;
	cout << s << endl;
	cout << "DeleteFront: " << *s.DeleteFront(retvalue) << endl;
	cout << s << endl;
	cout << "DeleteFront: " << *s.DeleteFront(retvalue) << endl;
	cout << s << endl;
	return 0;
}
