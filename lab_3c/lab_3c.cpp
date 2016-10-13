#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int m, n;
	int map[10][10];
	srand(time(NULL));
	cout << "m n = :";
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = rand() % 10;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	enum direction
	{
		left, up, right, down
	} dir = right;
	
	struct boundary
	{
		int u;
		int d;
		int l;
		int r;
	} bound{ 1, m - 1, 0, n - 1 };

	struct point
	{
		int x;
		int y;
	} p{ 0, 0 };

	int count = 1;
	cout << map[0][0] << " ";
	while (count < m * n)
	{
		if (dir == right)
		{
			while (p.x + 1 <= bound.r)
			{
				cout << map[p.y][++p.x] << " ";
				++count;
			}
			--bound.r;
			dir = down;
		}
		else if (dir == down)
		{
			while (p.y + 1 <= bound.d)
			{
				cout << map[++p.y][p.x] << " ";
				++count;
			}
			--bound.d;
			dir = left;
		}
		else if (dir == left)
		{
			while (p.x - 1 >= bound.l)
			{
				cout << map[p.y][--p.x] << " ";
				++count;
			}
			++bound.l;
			dir = up;
		}
		else if (dir == up)
		{
			while (p.y - 1 >= bound.u)
			{
				cout << map[--p.y][p.x] << " ";
				++count;
			}
			++bound.u;
			dir = right;
		}
	}

	return 0;
}
