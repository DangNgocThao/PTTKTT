//TRAVELING SALESMAN PROBLEM_Greedy algorithm2
// Hoc vien xay dung cac thuat toan metaheuristic khac giai bai toan TSP
#include <iostream>
using namespace std;
#define max 1001
void readfile(int c[max][max], int& n);
int  selectnextcity(int c[max][max], int n, int i);
void GTS1(int c[max][max], int n, int starcity);
void GTS2(int c[max][max], int n);

int c[max][max];
int* visit, * tour, n, cost;

int main()
{
	readfile(c, n);
	GTS2(c, n);
}

void readfile(int c[max][max], int& n)
{
	FILE* f;
	f = fopen("tsp2.inp", "rt");
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fscanf(f, "%d", &c[i][j]);
	fclose(f);
}

int selectnextcity(int c[max][max], int n, int i)
{
	int m, min = INT_MAX;
	for (int j = 1; j <= n; j++)
		if (visit[j] == 0 && c[i][j] < min)
		{
			min = c[i][j];
			m = j;
		}
	return m;
}

void GTS1(int c[max][max], int n, int starcity)
{
	visit = (int*)calloc(sizeof(int), max);
	tour = (int*)calloc(sizeof(int), max);
	cost = 0;
	int w, d = 1;
	tour[d] = starcity;
	visit[starcity] = 1;
	int currentcity = starcity;
	for (int i = 1; i <= n; i++)
	{
		w = selectnextcity(c, n, currentcity);
		tour[++d] = w;
		visit[w] = 1;
		cost += c[currentcity][w];
		currentcity = w;
	}
	cost += c[currentcity][starcity];
}

void GTS2(int c[max][max], int n)
{//	int v[max],p=4;
//	v[1]=1;v[2]=3;v[3]=4;v[4]=5;// co the tao ngau nhien
	int costbest = INT_MAX;
	int* tourbest;
	cost = 0;

	for (int k = 2; k <= n; k = k + 2)
	{
		GTS1(c, n, k);//GTS1(c,n,v[k]);
		if (cost < costbest)
		{
			costbest = cost;
			tourbest = tour;
		}
	}

	cout << "result GTS2: " << endl << costbest << endl;
}