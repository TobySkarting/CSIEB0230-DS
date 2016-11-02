#include "RStack.h"

int main()
{
	RStack<int> rs(5);
	rs.Push(1);
	rs.Push(2);
	rs.Push(3);
	rs.Push(4);
	rs.Push(5);
	rs.Print();
	rs.Reverse();
	rs.Print();
	rs.Reverse();
	rs.Print();
	return 0;
}
