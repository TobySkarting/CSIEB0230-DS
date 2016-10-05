#include <iostream>
#include <numeric>
#include <vector>
using namespace std;



int main()
{
	vector<int> iv = { 1, 2, 3 };
	cout << accumulate(iv.begin(), iv.end(), 0);
	return 0;
}
