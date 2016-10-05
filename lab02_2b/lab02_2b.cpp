#include <iostream>
#include <numeric>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> iv = { 1, 2, 3 };
	cout << accumulate(iv.begin(), iv.end(), 0) << endl;


	vector<string> sv = {"Hello", "World", "from", "NDHU"};
	cout << accumulate(sv.begin(), sv.end(), string()) << endl;

	return 0;
}
