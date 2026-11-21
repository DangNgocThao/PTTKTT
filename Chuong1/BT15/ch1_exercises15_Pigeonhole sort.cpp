#include <iostream>
using namespace std;
#define maxn 100000010
#define maxk 1000010
void pigeonhole(int a[], int n);
int a[maxn], T[maxk], n, M;
int main()
{
	FILE* f;
	f = fopen("num.inp", "rt");
	fscanf(f, "%d", &n);
	if (n == 10000) M = 32768;
	if (n == 100000 || n == 1000000) M = 100000;
	if (n == 10000000 || n == 100000000) M = 1000000;
	for (int i = 0; i < n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
	long t_star = clock();
	pigeonhole(a, n);
	long t_end = clock();
	cout << (t_end - t_star) / 1000.0;

	cout << endl;
}
void pigeonhole(int a[], int n)// complete
{
	for (int k = 0; k <= M; k++)	T[k] = 0;
	for (int i = 0; i < n; i++)	T[a[i]]++;
	int i = 0;
	for (int k = 0; k <= M; k++)
		while (T[k] > 0)
		{
			a[i++] = k;
			T[k]--;
		}
}