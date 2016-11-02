#include <iostream>
#include <string>
#include "LRUBuffer.h"
using namespace std;

string boolean_to_str(int b)
{
	return b == 0 ? "FALSE" : "TRUE";
}

int main()
{
	LRUBuffer<int> ib(3);
	cout << "IsEmpty? " << boolean_to_str(ib.IsEmpty()) << endl;
	cout << "IsFull? " << boolean_to_str(ib.IsFull()) << endl;

	ib.Add(4);
	ib.Add(5);
	ib.Add(6);
	ib.Output();

	cout << "IsEmpty? " << boolean_to_str(ib.IsEmpty()) << endl;
	cout << "IsFull? " << boolean_to_str(ib.IsFull()) << endl;
	
	cout << "Test 4: " << boolean_to_str(ib.Test(4)) << endl;
	ib.Output();

	int temp;
	cout << "Deleted: " << *ib.Delete(temp) << endl;
	ib.Output();

	cout << "IsEmpty? " << boolean_to_str(ib.IsEmpty()) << endl;
	cout << "IsFull? " << boolean_to_str(ib.IsFull()) << endl;

	LRUBuffer<string> sb(3);
	cout << "IsEmpty? " << boolean_to_str(sb.IsEmpty()) << endl;
	cout << "IsFull? " << boolean_to_str(sb.IsFull()) << endl;

	sb.Add("s1");
	sb.Add("s2");
	sb.Add("s3");
	sb.Output();

	cout << "IsEmpty? " << boolean_to_str(sb.IsEmpty()) << endl;
	cout << "IsFull? " << boolean_to_str(sb.IsFull()) << endl;

	cout << "Test s4: " << boolean_to_str(sb.Test("s1")) << endl;
	sb.Output();

	string tempS;
	cout << "Deleted: " << *sb.Delete(tempS) << endl;
	sb.Output();

	cout << "IsEmpty? " << boolean_to_str(sb.IsEmpty()) << endl;
	cout << "IsFull? " << boolean_to_str(sb.IsFull()) << endl;

	return 0;
}
