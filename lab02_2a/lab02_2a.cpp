#include <iostream>

using namespace std;

int DivZero(int a, int b, int c)
{
	if (a < 0)
		throw "a is not positive";
	if (b < 0)
		throw "b is not positive";
	if (c == 0)
		throw "c can not be zero";
	return a + b * c + b / c;
}
int main()
{
	try
	{
		cout << DivZero(3, 2, 1) << endl;
	}
	catch (const char *e)
	{
		cout << "Exception in calling DivZero" << endl;
		cout << e << endl;
	}

	try
	{
		cout << DivZero(-1, 2, 1) << endl;
	}
	catch (const char *e)
	{
		cout << "Exception in calling DivZero" << endl;
		cout << e << endl;
	}

	try
	{
		cout << DivZero(3, -1, 1) << endl;
	}
	catch (const char *e)
	{
		cout << "Exception in calling DivZero" << endl;
		cout << e << endl;
	}


	try
	{
		cout << DivZero(3, 2, 0) << endl;
	}
	catch (const char *e)
	{
		cout << "Exception in calling DivZero" << endl;
		cout << e << endl;
	}
	return 0;
}
