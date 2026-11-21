// Tim cay khung nho nhat theo thuat toan Kruskal/2010
// Trinh bay thuat toan: Nguyen Duc Nghia
// Lap trinh: Phan Tan Quoc
#include <iostream>
using namespace std;
#define max 100
struct canh
{
	int dau, cuoi;
	int w;
};
int n, m;
int connect[max][max];
canh c[max];

void readfile()
{
	FILE* f;
	f = fopen("mst2.inp", "rt");
	fscanf(f, "%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		fscanf(f, "%d%d%d", &c[i].dau, &c[i].cuoi, &c[i].w);
	fclose(f);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			connect[i][j] = 0;
	for (int i = 1; i <= n; i++)
		connect[i][i] = 1;
}
void sort()
{
	canh temp;
	for (int i = 1; i <= m - 1; i++)
		for (int j = i + 1; j <= m; j++)
			if (c[i].w > c[j].w)
			{
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
	//for (int i=1;i<=m;i++)
	//cout<<"Canh thu "<<i<<": Noi dinh "<<c[i].dau<<" voi dinh "<<c[i].cuoi<<" co trong so = " <<c[i].w<<endl;
}

void updateconnect(int i, int j)
{
	connect[i][j] = 1;
	connect[j][i] = 1;
	for (int k = 1; k <= n; k++)
		for (int l = 1; l <= n; l++)
			if (connect[k][i] == 1 && connect[j][l] == 1)
			{
				connect[k][l] = 1;
				connect[l][k] = 1;
			}
}

void  kruskal()
{
	int tong = 0, i = 1, socanhchon = 0, dinhdau, dinhcuoi;
	while (socanhchon < n - 1)
	{
		dinhdau = c[i].dau;
		dinhcuoi = c[i].cuoi;
		if (connect[dinhdau][dinhcuoi] == 0)
		{
			socanhchon++;
			updateconnect(dinhdau, dinhcuoi);
			//		cout<<dinhdau<<","<<dinhcuoi<<","<<c[i].w<<endl;
			tong = tong + c[i].w;
		}
		i++;
	}
	cout << "Ket qua:" << tong;
}
int main()
{
	readfile();
	sort();
	kruskal();
	cout << endl;
	return 0;
}