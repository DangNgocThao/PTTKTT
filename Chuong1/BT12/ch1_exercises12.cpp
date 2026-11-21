#include <iostream>
using namespace std;
#define maxn 100000001
void quicksort(int a[], int l, int r);
void mergesort(int a[], int n, int l, int r);
void heapsort(int a[], int n);
int a[maxn], n;
int L[maxn], R[maxn];
int main()
{
	FILE* f;
	f = fopen("num.inp", "rt");
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
	long t_star = clock();
	quicksort(a, 0, n - 1);//mergesort(a, n, 0, n-1);heapsort(a,n)
	long t_end = clock();
	cout << (t_end - t_star) / 1000.0;
	cout << endl;
}
void exch(int& x, int& y)
{
	int temp = x; x = y; y = temp;
}

void quicksort(int a[], int l, int r)
{
	int x = a[(l + r) / 2];
	int i = l;
	int j = r;
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
			exch(a[i++], a[j--]);
	} while (i < j);
	if (l < j) quicksort(a, l, j);
	if (i < r) quicksort(a, i, r);
}

void merge(int a[], int n, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	for (int k = 1; k <= n1; k++)
		L[k] = a[l + k - 1];
	for (int k = 1; k <= n2; k++)
		R[k] = a[m + k];
	L[n1 + 1] = INT_MAX;
	R[n2 + 1] = INT_MAX;
	int i = 1, j = 1;
	for (int k = l; k <= r; k++)
		if (L[i] <= R[j])
			a[k] = L[i++];
		else
			a[k] = R[j++];
}

void mergesort(int a[], int n, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergesort(a, n, l, m);
		mergesort(a, n, m + 1, r);
		merge(a, n, l, m, r);
	}
}

void insertheap(int a[], int l, int r)
{
	int j;
	j = l * 2;
	while (j <= r)
	{
		if (j < r)
			if (a[j] < a[j + 1])	j++;
		if (a[j] <= a[l]) 	return;
		exch(a[l], a[j]);
		l = j;
		j = l * 2;
	}
}

void heapsort(int a[], int n)
{
	int l = n / 2;
	int r = n - 1;
	while (l >= 0)
		insertheap(a, l--, r);

	while (r > 0)
	{
		exch(a[0], a[r]);
		r--;
		insertheap(a, 0, r);
	}
}