#include <iostream>
#include <conio.h>
using namespace std;
void docfile(int a[], int &n);
void algorithm(int a[], int n);
int a[1000001], n;
void main()
{
	docfile(a, n);
	algorithm(a, n);
	getch();
}
void docfile(int a[], int &n)
{
	FILE* f;
	f = fopen("VD1.inp", "rt");
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}
int max(int a,int b)
{
	return a > b ? a : b;
}

void algorithm(int a[], int n)
{
	int maxsofar = 0;
	int maxendinghere = 0;
	for (int i = 1; i <= n; i++)
	{
		maxendinghere = max(maxendinghere + a[i], 0);
		maxsofar = max(maxsofar, maxendinghere);
	}
	cout << maxsofar << endl;
}
/*
VD1.INP
7
4 -5 6 -4 2 3 -7
*/
