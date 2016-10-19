#include <iostream>
#include "SparseMatrix.h"

using namespace std;

int main()
{
	int val[8] = { 15, 22, -15, 11, 3, -6, 91, 28 };
	int val2[5] = { 1, 2, 1, 3, 1 };
	int val3[3] = { 1, 1, 1 };
	SparseMatrix<int> a;
	a.Init2(val2);
	SparseMatrix<int> b;
	b.Init3(val3);
	a.Output();
	b.Output();
	SparseMatrix<int> c = a.Multiply(b);
	cout << "a * b = " << endl;
	c.Output();
	SparseMatrix<int> s = a.Add(b);
	cout << "a + b = " << endl;
	s.Output();
    return 0;
}

