#include <iostream>
using namespace std;
#define maxn 200
#define maxM 10000
int f[maxn][maxM], a[maxn], n, M, result[maxn];
void input(int a[], int& n, int& M)
{
	FILE* f;
	f = fopen("knapsack1.inp", "rt");
	fscanf(f, "%d%d", &n, &M);
	for (int i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

void createtable(int f[][maxM], int a[], int n, int M)
{
	for (int i = 1; i <= M; i++)
		if (i >= a[1])
			f[1][i] = a[1];
		else
			f[1][i] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= M; j++)
			if (j >= a[i])
				f[i][j] = max(f[i - 1][j - a[i]] + a[i], f[i - 1][j]);
			else
				f[i][j] = f[i - 1][j];
}

void reftable(int f[][maxM], int a[], int n, int M)
{
	int max_values = 0;
	int K = n, V = M;
	memset(result, 0, sizeof(result));
	do
	{
		while (f[K][V] == f[K - 1][V]) K--;
		result[K] = 1;
		V = f[K][V] - a[K];
		max_values += a[K];
	} while (V > 0);
	cout << "result: " << max_values << ": " << endl;
	for (int i = 1; i <= n; i++)
		if (result[i])
			cout << i << " ";//a[i]
	cout << endl;
}

int main()
{
	input(a, n, M);
	createtable(f, a, n, M);
	reftable(f, a, n, M);
	return 0;
}
/*
knapsack1.inp
5 12
6  1  8  7  1
*/