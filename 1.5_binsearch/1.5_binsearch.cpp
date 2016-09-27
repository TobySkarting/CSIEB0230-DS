#include <iostream>

using namespace std;

int BinarySearch(const int *a, const int x, const int n)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (x < a[middle])
			right = middle - 1;
		else if (x > a[middle])
			left = middle + 1;
		else
			return middle;
	}
	return -1;
}

int main()
{
	int array[] = { 2, 3, 4, 6, 7, 9, 11, 13, 14, 15 };
	cout << 2 << " in position " << BinarySearch(array, 2, 10) << endl;
	cout << 9 << " in position " << BinarySearch(array, 9, 10) << endl;
	cout << 15 << " in position " << BinarySearch(array, 15, 10) << endl;
	cout << 10 << " in position " << BinarySearch(array, 10, 10) << endl;
    return 0;
}
