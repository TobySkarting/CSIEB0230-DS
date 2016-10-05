#include <iostream>
#include <ctime>

using namespace std;

int SequentialSearch(int *a, const int n, const int x)  //a[0], ..., a[n]
{
	int i = n; a[0] = x;
	while (a[i] != x)
		i--;
	return i;
} // en

char compare(int x, int y)
{
	if (x > y) return '>';
	else if (x < y) return '<';
	else return '=';
}

int BinarySearch(int *a, const int x, const int n)
// Search the sorted array a[0], ..., a[n-1] for x
{
	for (int left = 0, right = n - 1; left <= right;) { // while more elements
		int middle = (left + right) / 2;
		switch (compare(x, a[middle])){
		case '>': left = middle + 1; break; // x > a[middle]
		case '<': right = middle - 1; break; // x < a[middle]
		case '=': return middle; // x == a[middle]
		} // end of switch
	} // end of for
	return -1; // not found
} // end of BinarySearch

typedef int (*SearchFunc)(int *a, const int x, const int n);

void TimeSearch1(SearchFunc searchFunc) {
	int a[1001], n[20], k;
	for (int j = 1; j <= 1000; j++) // initialize a
		a[j] = j;
	for (int j = 0; j < 10; j++) { // initialize n
		n[j] = 10 * j;
		n[j + 10] = 100 * (j + 1);
	}
	cout << " n time" << endl; // print header
	for (int j = 0; j < 20; j++) { // calculate exe time
		clock_t start, stop;
		start = clock(); // start time
		k = searchFunc(a, n[j], 0);
		stop = clock(); // stop time
		double runTime =
			(double)(stop - start) / CLOCKS_PER_SEC;
		cout << " " << n[j] << " " << runTime << endl;
	}
	cout << "Times are in seconds." << endl;
}

void TimeSearch2(SearchFunc searchFunc) {
	int a[1001], n[20], k;
	const long r[20] = { 300000, 300000, 200000,
		200000, 100000, 100000, 100000, 80000, 80000,
		50000, 50000, 25000, 15000, 15000, 10000,
		7500, 7000, 6000, 5000, 5000 };
	for (int j = 1; j <= 1000; j++) // initialize a
		a[j] = j;
	for (int j = 0; j < 10; j++) { // initialize n
		n[j] = 10 * j; n[j + 10] = 100 * (j + 1);
	}
	cout << " n r total runTime" << endl;
	for (int j = 0; j < 20; j++) { // calculate exe time
		clock_t start, stop;
		start = clock(); // start time
		for (long b = 1; b <= r[j]; b++)
			k = searchFunc(a, n[j], 0);
		stop = clock(); // stop time
		double totalTime =
			(double)(stop - start) / CLOCKS_PER_SEC;
		double runTime = totalTime / (double)(r[j]);
		cout << " " << n[j] << " " << r[j] << " "
			<< totalTime << " " << runTime << endl;
	}
	cout << "Times are in seconds." << endl;
}
int main()
{
	TimeSearch1(SequentialSearch);
	TimeSearch2(SequentialSearch);
	TimeSearch1(BinarySearch);
	TimeSearch2(BinarySearch);
	return 0;
}
