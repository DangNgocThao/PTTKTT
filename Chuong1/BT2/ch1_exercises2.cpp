#include <iostream>
#define maxn 1000001 // 1 trieu
using namespace std;
void docfile(int a[], int& n, int& m);
int xuly(int a[], int n, int m);
int a[maxn], n, m;
int main()
{
	docfile(a, n, m);
	cout << xuly(a, n, m) << endl;
	return 0;
}
void docfile(int a[], int& n, int& m)
{
	FILE* f;
	f = fopen("num.inp", "rt");
	fscanf(f, "%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}
int xuly(int a[], int n, int m)
{
	int d = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] + a[j] == m)
				d++;
	return d;
}