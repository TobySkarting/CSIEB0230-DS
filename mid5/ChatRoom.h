#pragma once
#include <string>
#include "Queue.h"

class ChatRoom : private Queue<std::string>
{
public:
	ChatRoom(int MaxSize = 10);
	~ChatRoom();
	void postMessage(const std::string &msg);
	std::string readMessage();
	void deleteMessage();
	void rewind(int count);
	void rewind(float percentage);
	Boolean IsFull() { return Queue::IsFull(); }
	Boolean IsEmpty() { return Queue::IsEmpty(); }
private:
	int m_CurrPos;

};

