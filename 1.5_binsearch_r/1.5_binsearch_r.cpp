#include <iostream>

using namespace std;

int BinarySearch(const int *a, const int x, const int left, const int right)
{
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (x < a[middle])
			return BinarySearch(a, x, left, middle - 1);
		else if (x > a[middle])
			return BinarySearch(a, x, middle + 1, right);
		else
			return middle;
	}
	return -1;
}

int main()
{
	int array[] = { 2, 3, 4, 6, 7, 9, 11, 13, 14, 15 };
	cout << 2 << " in position " << BinarySearch(array, 2, 0, 9) << endl;
	cout << 9 << " in position " << BinarySearch(array, 9, 0, 9) << endl;
	cout << 15 << " in position " << BinarySearch(array, 15, 0, 9) << endl;
	cout << 10 << " in position " << BinarySearch(array, 10, 0, 9) << endl;
	return 0;
}
