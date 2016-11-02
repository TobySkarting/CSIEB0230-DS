#include "ChatRoom.h"

ChatRoom::ChatRoom(int MaxSize) : Queue<std::string>(MaxSize)
{
	m_CurrPos = front;
}


ChatRoom::~ChatRoom()
{
}

void ChatRoom::postMessage(const std::string &msg)
{
	Queue::Add(msg);
}

std::string ChatRoom::readMessage()
{
	if (m_CurrPos == rear)
		return "[No More Message.]";
	return Queue::queue[++m_CurrPos];
}

void ChatRoom::deleteMessage()
{
	std::string msg;
	Queue::Delete(msg);
	if (m_CurrPos < front)
		m_CurrPos = front;
}

void ChatRoom::rewind(int count)
{
	m_CurrPos -= count;
	if (m_CurrPos < front)
		m_CurrPos = front;
}

void ChatRoom::rewind(float percentage)
{
	rewind((int)(Queue::MaxSize * percentage));
}
