#include <iostream>
#include "Bst.h"

using namespace std;

int main()
{
	BST<int> m;
	Element<int> a, b, c, d, e, f, g, h, i, j, k, l;
	a.key = 5; b.key = 3; c.key = 11; d.key = 3; e.key = 15;
	f.key = 2; g.key = 8; h.key = 22; i.key = 20; j.key = 9;
	cout << "\n" << m.Insert(a);
	cout << "\n" << m.Insert(b);
	cout << "\n" << m.Insert(c);
	cout << "\n" << m.Insert(d);
	cout << "\n" << m.Insert(e);
	cout << "\n" << m.Insert(f);
	cout << "\n" << m.Insert(g);
	cout << "\n" << m.Insert(h);
	cout << "\n" << m.Insert(i);
	cout << "\n" << m.Insert(j);
	m.treeprint();

	cout << "Search by rank of 5: " << m.SearchByRank(5)->GetKey() << endl;
	cout << "Delete 15." << endl;
	m.Delete(15);
	m.treeprint();
	return 0;
}
