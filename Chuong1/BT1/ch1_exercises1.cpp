#include <iostream>
#include <math.h>
#define maxn 1000001
void docfile(int a[], int& n);
int xuly(int a[], int n);
void ghifile(int a[], int n);
int a[maxn], n;
int main()
{
	docfile(a, n);
	ghifile(a, n);
	return 0;
}
void docfile(int a[], int& n)
{
	FILE* f;
	f = fopen("num.inp", "rt");
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}
int xuly(int a[], int n)
{
	int max = 0, d = 1;
	for (int i = 1; i < n; i++)
		if (a[i] <= a[i + 1])
			d++;
		else
		{
			if (d > max) max = d;
			d = 1;
		}
	return d > max ? d : max;
}
void ghifile(int a[], int n)
{
	FILE* f;
	f = fopen("num.out", "wt");
	fprintf(f, "%d", xuly(a, n));
	fclose(f);
}