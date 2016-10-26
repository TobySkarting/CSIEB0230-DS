#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int> s(50);
	int MaxSumPerLine, x;
	cout << "MaxSumPerLine: ";
	cin >> MaxSumPerLine;
	cout << "Values: ";
	while (cin >> x)
		s.Add(x);

	int sum = 0;
	while (s.Delete(x) != 0)
	{
		if (sum + x <= MaxSumPerLine)
		{
			sum += x;
		}
		else
		{
			sum = x;
			cout << endl;
		}
		cout << x << " ";
	}

	return 0;
}
