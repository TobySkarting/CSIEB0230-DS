#include <iostream>

using namespace std;

void SelectionSort(int *a, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		int smallest_index = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[smallest_index])
				smallest_index = j;
		}
		if (smallest_index != i)
			std::swap(a[i], a[smallest_index]);
	}
}

int main()
{
	int array[] = {9, 4, 8, 0, 7, 3, 6, 1, 5, 2};
	for (int i : array)
		cout << i << " ";
	cout << endl;

	SelectionSort(array, 10);

	for (int i : array)
		cout << i << " ";
	cout << endl;
    return 0;
}

