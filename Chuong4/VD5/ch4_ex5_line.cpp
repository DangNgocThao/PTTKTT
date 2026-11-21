// quicksort sap xep theo b khong giam
// 1104/ 1117/ 1151

// bai1.cpp - Tap cac doan thang khong giao nhau
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct doan { int a, b; };
const int maxn = 1000010;
doan d[maxn]; int n, ans;

void readfile()
{
	freopen("Line2.INP", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &d[i].a, &d[i].b);
}
void quicksort(doan d[], int l, int r)
{
	int i = l, j = r;
	doan tmp;
	int x = d[(l + r) / 2].b;
	while (i <= j)
	{
		while (d[i].b < x) i++;
		while (d[j].b > x) j--;
		if (i <= j)
		{
			tmp = d[i];
			d[i] = d[j];
			d[j] = tmp;
			i++; j--;
		}
	};
	if (l < j) quicksort(d, l, j);
	if (i < r) quicksort(d, i, r);
}
void solve()
{
	quicksort(d, 1, n);
	int maxlast = -2000000000; ans = 0;
	for (int i = 1; i <= n; i++)
		if (maxlast <= d[i].a)
		{
			maxlast = d[i].b;
			ans++;
		}
}
void writefile()
{
	freopen("LINE2.OUT", "w", stdout);
	printf("%d\n", ans);
}
int main()
{
	readfile();
	solve();
	writefile();
	return 0;
}
