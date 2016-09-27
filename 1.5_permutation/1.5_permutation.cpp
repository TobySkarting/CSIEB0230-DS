#include <iostream>

using namespace std;

void Permutations(char *a, int l, int r)
{
	if (l == r)
	{
		for (int i = 0; i != r; ++i)
			cout << a[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = l; i != r; ++i)
		{
			swap(a[i], a[l]);
			Permutations(a, l + 1, r);
			swap(a[i], a[l]);
		}
	}
}

int main()
{
	char p[3] = { 'a', 'b', 'c' };
	Permutations(p, 0, 1);
	Permutations(p, 0, 2);
	Permutations(p, 0, 3);
    return 0;
}

