#include <iostream>

using namespace std;

bool isPerfectNo(int n)
{
	if (n == 6)
		return true;
	if (n == 28)
		return true;
	if (n == 496)
		return true;
	if (n == 8128)
		return true;
	if (n == 33550336)
		return true;
	return false;
}

int main()
{
	int a, b, count = 0;
	cout << "Enter two positive integers: ";
	cin >> a >> b;
	cout << "Perfect numbers within " << a << "~" << b << ":" << endl;
	while (a < b)
	{
		if (isPerfectNo(a))
		{
			cout << a << " ";
			++count;
		}
		++a;
	}
	cout << endl << "There are " << count << " perfect numbers.";
	return 0;
}
