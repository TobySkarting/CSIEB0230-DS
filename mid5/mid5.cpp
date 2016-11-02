#include <iostream>
#include "ChatRoom.h"
using namespace std;

string boolean_to_str(int b)
{
	return b == 0 ? "FALSE" : "TRUE";
}

int main()
{
	ChatRoom cr(3);
	cr.postMessage("Hello everyone!");
	cr.postMessage("We are in NDHU.");
	cr.postMessage("Nice to meet you :)");

	cout << "IsEmpty? " << boolean_to_str(cr.IsEmpty()) << endl;
	cout << "IsFull? " << boolean_to_str(cr.IsFull()) << endl;

	cout << cr.readMessage() << endl;
	cout << cr.readMessage() << endl;
	cout << cr.readMessage() << endl;
	cout << cr.readMessage() << endl;

	cout << "rewind 1" << endl;
	cr.rewind(1);
	cout << cr.readMessage() << endl;

	cout << "rewind 3" << endl;
	cr.rewind(3);
	cr.deleteMessage();
	cout << cr.readMessage() << endl;
	cout << cr.readMessage() << endl;
	cout << cr.readMessage() << endl;
	cout << cr.readMessage() << endl;

	cout << "rewind 50%" << endl;
	cr.rewind(0.5f);
	cout << cr.readMessage() << endl;
	cout << cr.readMessage() << endl;
	cout << cr.readMessage() << endl;
	cout << cr.readMessage() << endl;

	cout << "IsEmpty? " << boolean_to_str(cr.IsEmpty()) << endl;
	cout << "IsFull? " << boolean_to_str(cr.IsFull()) << endl;
	return 0;
}
