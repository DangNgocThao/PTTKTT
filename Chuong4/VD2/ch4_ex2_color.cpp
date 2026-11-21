// c1.	1 2 1 2 3 1 3 2 4 1
// c2.	1 2 3 2 1 4

// dau phai thuat toan 2 ????
#include <iostream>
#include <stdio.h>
#include <ehdata_values.h>
#include <iomanip>

void readfile();
void output();
void process();

const int max = 501;
int dinh[max];
int mau[max][max];
int c[max][max];
int n;

int main()
{
	readfile();
	process();
	output();
}

void output()
{
	int max = 1;
	for (int i = 1; i <= n; i++)
	{
		std::cout << dinh[i] << "  ";
		if (dinh[i] > max) max = dinh[i];
	}
	std::cout << std::endl;
	std::cout << "sac so: " << max;
}

void process()
{
	for (int i = 1; i <= n; i++)
	{
		int j = 1;
		while (mau[i][j] == 0) j++;// tim mau dau tien trong danh sach mau- la j
		for (int k = 1; k <= n; k++)
			if (c[i][k] == 1) mau[k][j] = 0;//cam to mau j cho cac dinh k ke voi i
		dinh[i] = j;//to dinh i boi mau j
	}
}

void readfile()
{
	FILE* f;
	f = fopen("color2.inp", "rt");
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fscanf(f, "%d", &c[i][j]);
	fclose(f);

	for (int i = 1; i <= n; i++)
	{
		dinh[i] = 0;// cac dinh chua to mau
		for (int j = 1; j <= n; j++)
			mau[i][j] = j;//lap bang mau cho moi dinh
	}
}