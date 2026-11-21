//Ref: TRR cua tac gia Nguyen Duc Nghia, cai dat:Phan Tan Quoc
#include <iostream>
#include <stdio.h>
#define max 100
using namespace std;

void readfile(int c[max][max], int& n);
void output(int c[max][max], int n);
void permute(int c[max][max], int n, int i);
void result();

int   c[max][max];
int   tourbest[max], b[max], x[100], n, costbest;

int main()
{
	readfile(c, n);
	permute(c, n, 1);
	result();
}

void readfile(int c[max][max], int& n)
{
	FILE* f;
	f = fopen("tsp.inp", "rt"); // file text
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			fscanf(f, "%d", &c[i][j]);
			if (i == j) c[i][j] = INT_MAX;
		}
	fclose(f);
	costbest = INT_MAX;
	for (int i = 1; i <= n; i++) b[i] = 1;
}

void  output(int c[max][max], int n)
{
	int cost = 0;
	for (int i = 1; i < n; i++)
		cost = cost + c[x[i]][x[i + 1]];
	cost = cost + c[x[n]][x[1]];
	if (cost < costbest)
	{
		costbest = cost;
		for (int j = 1; j <= n; j++)
			tourbest[j] = x[j];
	}
}

void permute(int c[max][max], int n, int i)
{
	for (int j = 1; j <= n; j++)
		if (b[j] == 1)
		{
			x[i] = j;
			b[j] = 0;
			if (i == n)  output(c, n);
			else       permute(c, n, i + 1);
			b[j] = 1;
		}
}

void result()
{
	cout << costbest << endl;
	for (int i = 1; i <= n; i++)
		cout << tourbest[i] << " ";
	cout << tourbest[1];
}