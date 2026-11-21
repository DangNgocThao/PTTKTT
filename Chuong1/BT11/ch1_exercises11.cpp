#include <iostream>
using namespace std;
#define maxn 1000010
void Interchangesort(int a[], int n);
void Bubblesort(int a[], int n);
void Selectionsort(int a[], int n);
void Insertionsort(int a[], int n);
void Shellsort(int a[], int n);
int a[maxn], n;
int main()
{
	FILE* f;
	f = fopen("num.inp", "rt");
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
	long t_star = clock();
	Selectionsort(a, n);
	long t_end = clock();
	cout << (t_end - t_star) / 1000.0;
	cout << endl;
	return 0;
}
void exch(int& x, int& y)
{
	int temp = x; x = y; y = temp;
}
void Interchangesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				exch(a[i], a[j]);
}
void Bubblesort(int a[], int n)
{
	for (int i = 1; i < n; i++)
		for (int j = n - 1; j >= i; j--)
			if (a[j] < a[j - 1])
				exch(a[j], a[j - 1]);
}
void Selectionsort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		exch(a[min], a[i]);// nghia la ai la phan tu nho nhat o buoc chon thu i
	}
}
void Insertionsort(int a[], int n)
{
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i]; j = i - 1;
		while ((j >= 0) && (a[j] > x))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void Shellsort(int a[], int n)
{
	int h = 1;
	while (h < n / 3) h = 3 * h + 1; // 1, 4, 13, 40, 121, 364, 1093, ...
	while (h >= 1)
	{ // h-sort the array.
		for (int i = h; i < n; i++)
		{ // Insert a[i] among a[i-h], a[i-2*h], a[i-3*h]... .
			for (int j = i; j >= h && a[j] < a[j - h]; j -= h)
				exch(a[j], a[j - h]);
		}
		h = h / 3;
	}
}