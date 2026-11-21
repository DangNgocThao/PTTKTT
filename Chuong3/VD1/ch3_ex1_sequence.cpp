#include <iostream>
using namespace std;
#define maxn 10000
void input(int a[], int& n);
void createtable(int a[], int n);
void result(int a[], int n);
int a[maxn], L[maxn], P[maxn], n;
int main()
{
	input(a, n);
	createtable(a, n);
	result(a, n);
	return 0;
}

void input(int a[], int& n)
{
	FILE* f;
	f = fopen("sequence.inp", "rt");
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}

void createtable(int a[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		int maxLj = 0;
		int maxPi = 0;
		for (int j = i - 1; j >= 1; j--)
			if (a[j] <= a[i] && L[j] > maxLj)
			{
				maxLj = L[j];
				maxPi = j;
			}
		L[i] = maxLj + 1;
		P[i] = maxPi;
	}
}

void result(int a[], int n)
{
	int maxL = 0, pos;
	for (int i = 1; i <= n; i++)
		if (L[i] > maxL)
		{
			maxL = L[i];
			pos = i;
		}
	cout << "result: " << maxL << ": " << endl;;
	int i = pos;
	while (P[i] != 0)
	{
		cout << a[i] << " ";
		i = P[i];
	}
	cout << a[i] << " ";
	cout << endl;
}
/*
sequence.inp
10
2 8 11 3 5 9 10 4 17 6
*/