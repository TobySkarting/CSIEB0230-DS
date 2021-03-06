#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void grep(const string &pattern, const string &inFileName, const string &outFileName)
{
	ifstream fin(inFileName);
	ofstream fout(outFileName);
	if (!fin)
	{
		cerr << "Error opening " << inFileName << endl;
		return;
	}
	if (!fout)
	{
		cerr << "Error opening " << outFileName << endl;
		return;
	}

	string line;
	while (getline(fin, line))
	{
		if (line.find(pattern) != string::npos)
			fout << line << endl;
	}
}

int main()
{
	grep("food", "input.txt", "output.txt");
	return 0;
}
