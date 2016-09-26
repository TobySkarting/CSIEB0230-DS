#include <iostream>

using namespace std;

int compare(int x, int y)
{
	if (x > y) return 1;
	else if (x < y) return -1;
	else return 0;
}

int BinarySearch(int *a, int x, const int n)
// Search the sorted array a[0], ..., a[n-1] for x
{
	int left = 0, right = n - 1;
	while (left <= right) { // while more elements
		int middle = (left + right) / 2;
		switch (compare(x, a[middle])) {
		case 1: left = middle + 1; break; // x > a[middle]
		case -1: right = middle - 1; break; // x < a[middle]
		case 0: return middle; // x == a[middle]
		} // end of switch
	} // end of for
	return -1; // not found
} // end of BinarySearch

int main()
{
	int b[10];
	b[0] = 2; b[1] = 4; b[2] = 5; b[3] = 7; b[4] = 10;
	b[5] = 12; b[6] = 14; b[7] = 15; b[8] = 17; b[9] = 25;

	for (int i = 0; i != 10; ++i)
		cout << b[i] << " in position " << BinarySearch(b, b[i], 10) << endl;
	return 0;
}


