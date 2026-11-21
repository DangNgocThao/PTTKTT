#include <iostream>
#include <fstream>
using namespace std;
const int maxn = 1000;
int m, n, max_values = 0;
int a[maxn][maxn];
int b[maxn][maxn];

void readfile()
{
	ifstream fi("move.inp");
	fi >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			fi >> a[i][j];
	fi.close();
}

void createtable()
{
	for (int i = 1; i <= m; i++) b[i][1] = a[i][1];
	for (int j = 2; j <= n; j++)
		for (int i = 1; i <= m; i++)
		{
			int m;
			m = max(b[i - 1][j - 1], b[i + 1][j - 1]);
			m = max(m, b[i][j - 1]);
			b[i][j] = a[i][j] + m;
		}
	max_values = b[1][n];
	for (int i = 2; i <= m; i++)
		max_values = max(max_values, b[i][n]);
}

void reftable()
{
	cout << max_values << endl;
}
int main()
{
	readfile();
	createtable();
	reftable();
	return 0;
}
/*
move.inp
4 5
1 3 4 2 10
5 8 2 3 8
7 5 9 4 6
2 9 4 5 7
*/
