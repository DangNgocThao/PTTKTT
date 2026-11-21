#include <iostream>
using namespace std;
int max(int x, int y);
void readfile();
void findpath();
void result();
int f[1000][1000];
int a[1000][1000], n;
int main()
{
	readfile();
	findpath();
	result();
	return 0;
}

void readfile()
{
	FILE* fi;
	fi = fopen("triangle.inp", "rt");
	fscanf(fi, "%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			fscanf(fi, "%d", &a[i][j]);
	fclose(fi);
}

int max(int x, int y)
{
	if (x > y) return x;
	return y;
}
void findpath()
{
	f[1][1] = a[1][1];
	for (int i = 2; i <= n; i++)
		f[i][1] = f[i - 1][1] + a[i][1];
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= i; j++)
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
}

void result()
{
	int m = INT_MIN;
	for (int i = 1; i <= n; i++)
		if (f[n][i] > m)
			m = f[n][i];
	cout << m << endl;
}
/*
triangle.inp
5
7
3 8	
8 1 0 	
2 7 4 4
4 5 2 6 5
*/