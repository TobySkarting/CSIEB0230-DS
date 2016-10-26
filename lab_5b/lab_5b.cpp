#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int> s(100);
	s.Add(5);
	s.Add(7);
	s.Add(9);
	s.Add(10);
	s.Output();
	int *deleted = s.MultiDelete(2);
	cout << "deleted items: ";
	for (int i = 0; i < 2; ++i)
		cout << deleted[i] << " ";
	cout << endl;
	s.Output();
	return 0;
}
