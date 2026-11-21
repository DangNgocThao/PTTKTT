#include <iostream>
using namespace std;
#define maxn 200
#define maxM 10000
int a[maxn], c[maxn], f[maxn][maxM];
int n, M;

void input()
{
	FILE* fi;
	fi = fopen("knapsack2.inp", "rt");
	fscanf(fi, "%d%d", &n, &M);
	for (int i = 1; i <= n; i++)
		fscanf(fi, "%d%d", &a[i], &c[i]);
	fclose(fi);
}

int max(int a, int b)
{
	return a > b ? a : b;
}
void createtable()
{
	for (int i = 1; i <= maxn; i++)
		f[0][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= M; j++)
		{
			if (j < a[i])
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + c[i]);
		}
}

void reftable()
{
	cout << "Max Value : " << f[n][M] << endl;
}

int main()
{
	input();
	createtable();
	reftable();
	return 0;
}
/*
knapsack2.inp
6  12
5  7
1  5
6  3
4  6
9  14
5  8
*/