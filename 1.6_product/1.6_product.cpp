#include <iostream>
#include <numeric>

using namespace std;

int Product(int *a, int n)
{
	return accumulate(a, a + n, 1, multiplies<int>());
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	cout << Product(arr, 5) << endl;
    return 0;
}
