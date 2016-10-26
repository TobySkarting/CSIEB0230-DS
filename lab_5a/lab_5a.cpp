#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> s;
	int x;
	s.Add(5);
	s.Add(7);
	s.Add(9);
	s.Add(10);
	s.Output();
	while (cin >> x)
		cout << s.Search(x) << endl;
	return 0;
}
