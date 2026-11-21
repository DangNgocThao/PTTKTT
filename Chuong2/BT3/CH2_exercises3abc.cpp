#include <iostream>
using namespace std;
#define maxn 10000
void input_array(int a[], int& n);
void output_array(int a[], int n);
void selectionsort(int a[], int l, int r);
void insertionsort(int a[], int l, int r);
void bubblesort(int a[], int l, int r);
int main()
{
	int a[maxn], n;
	input_array(a, n);
	//	selectionsort(a,0,n-1);
	//	insertionsort(a,0,n-1);
	bubblesort(a, 0, n - 1);
	output_array(a, n);
	cout << endl;
	return 0;
}
void input_array(int a[], int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void output_array(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void swap(int& x, int& y)
{
	int t = x; x = y; y = t;
}
void selectionsort(int a[], int l, int r)
{
	if (l == r) return;
	int pos = l;
	for (int j = l + 1; j <= r; j++)
		if (a[j] < a[pos]) pos = j;
	if (l != pos) swap(a[l], a[pos]);
	selectionsort(a, l + 1, r);
}
void insertionsort(int a[], int l, int r)
{
	if (l > r) return;
	int x = a[l], pos = l;
	while (pos > 0 && a[pos - 1] > x)
		a[pos--] = a[pos - 1];
	a[pos] = x;
	insertionsort(a, l + 1, r);
}
void bubblesort(int a[], int l, int r)
{
	if (l == r) return;
	for (int j = 0; j < r; j++) // trong ref ghi la j<=l-1 ?
		if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
	bubblesort(a, l, r - 1);
}