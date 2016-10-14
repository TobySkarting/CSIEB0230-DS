#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial p;
	Polynomial q;

	Term e;
	cout << "start" << endl;

	e.Init(3, 14); p.Add(e);
	e.Init(2, 8); p.Add(e);
	e.Init(1, 0); p.Add(e);
	cout << "p" << endl << p << endl;

	e.Init(-3, 14); q.Add(e);
	e.Init(-2, 8); q.Add(e);
	e.Init(-1, 0); q.Add(e);
	cout << "q" << endl << q << endl;

	Polynomial u = p + p;
	cout << "u = p + p" << endl << u << endl;

	Polynomial m = p.Multiply(q);
	cout << "m = p * q" << endl << m << endl;
    return 0;
}

