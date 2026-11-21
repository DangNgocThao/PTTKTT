#include <iostream>
#include <conio.h>
void inputarray(int a[], int& n, int& k);
void outputarray(int a[], int n);
void swaparray(int a[], int k, int n);
void process(int a[], int n, int k);
int a[1000001], n, k;
void main()
{
	inputarray(a, n, k);
	process(a, n, k);
	outputarray(a, n);
	getch();
}

void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void swaparray(int a[], int u, int v)
{
	while (u < v)
		swap(a[u++], a[v--]);
}

void process(int a[], int n, int k)
{
	swaparray(a, 1, k);
	swaparray(a, k + 1, n);
	swaparray(a, 1, n);
}

void inputarray(int a[], int& n, int& k)
{
	FILE* f;
	f = fopen("VD2.inp", "rt");
	fscanf(f, "%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}

void outputarray(int a[], int n)
{
	FILE* g;
	g = fopen("VD2.out", "wt");
	for (int i = 1; i <= n; i++)
	{
		fprintf(g, "%6d", a[i]);
		if (i % 10 == 0)
			fprintf(g, "\n");
	}
	fclose(g);
}
/*
VD2.INP
9 3
3 6 5 1 2 7 6 9 8
*/