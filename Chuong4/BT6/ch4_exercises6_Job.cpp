// BT6_
//sap xep tang theo di
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct congviec { int p, d; };
const int maxn = 1000010;
congviec a[maxn]; int n, ans;

void readfile()
{
	freopen("Job2.INP", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].p, &a[i].d);
}
bool comp(congviec x, congviec y)
{
	if (x.d == y.d) return x.p > y.p; return x.d < y.d;
}
void solve()
{
	sort(a + 1, a + n + 1, comp);
	int time = 0; ans = n;
	for (int i = 1; i <= n; i++)
		if (time + a[i].p <= a[i].d)
		{
			time += a[i].p;
			ans--;
		}
}
void writefile()
{
	freopen("Job2.OUT", "w", stdout);
	printf("%d\n", ans);
}
int main()
{
	readfile();
	solve();
	writefile();
	return 0;
}
