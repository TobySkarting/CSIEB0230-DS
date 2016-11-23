#include <iostream>
#include "Tree.h"

using namespace std;
int main()
{
	Tree<int> t;
	int a, b, c;

	cin >> a >> b >> c;

	t.Insert(a);
	t.Insert(b);
	t.Insert(c);

	t.inorder();
	cout << endl;

	return 0;
}

