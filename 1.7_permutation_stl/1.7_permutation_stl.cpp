#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

void Permutations(char *a, int n)
{
	do
	{
		copy(a, a + n, ostream_iterator<char>(cout, " "));
		cout << endl;
	} while (next_permutation(a, a + n));
}

int main()
{
	char p[] = { 'a', 'b', 'c', 'd', 'e' };
	Permutations(p, 1);
	Permutations(p, 2);
	Permutations(p, 3);
    return 0;
}
