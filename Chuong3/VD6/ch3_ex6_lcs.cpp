#include <iostream>
using namespace std;
#define fi "lcs.inp" 
#define maxmn 200

int	a[maxmn], b[maxmn], p[maxmn];
int	l[maxmn][maxmn];
int m, n;

void input()
{
	FILE* f;
	f = fopen(fi, "rt");
	fscanf(f, "%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		fscanf(f, "%d", &a[i]);
	for (int i = 1; i <= n; i++)
		fscanf(f, "%d", &b[i]);
	fclose(f);
}

int max(int x, int y)
{
	return x > y ? x : y;
}
void createtable()
{
	for (int i = 1; i <= m; i++)	l[i][0] = 0;
	for (int j = 1; j <= n; j++)	l[0][j] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			if (a[i] == b[j]) l[i][j] = l[i - 1][j - 1] + 1;
			else l[i][j] = max(l[i][j - 1], l[i - 1][j]);
		}
}

void reftable()
{
	cout << l[m][n];
	int i = m, j = n;
	//memset(p,sizeof(p),0);
	for (int k = 0; k < maxmn; k++)	p[k] = 0;
	int count = 0;
	while (i > 0 && j > 0)
	{
		if (a[i] == b[j])
		{
			p[++count] = a[i--];
			j--;
		}
		else 	if (l[i][j] == l[i][j - 1]) j--;
		else i--;
	}
	for (i = count; i >= 1; i--)
		cout << p[i] << " ";
	cout << endl;
}

int main()
{
	input();
	createtable();
	reftable();
	return 0;
}
/*
lcs.inp
13 12
3 12 5 6 1 7 61 9 0 10 11 32 4
12 1 4 61 12 0 14 11 10 3 4 32
*/