#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define Max 100
#define inputPath "../data/hoatdong.txt";

struct Activity
{
	char name[Max];
	int start, end;
};

void menu();
void thucThi();
void docFile(Activity a[], int& n);
void sapXepHD(Activity a[],int n);
void luuChonHD(Activity a[], int n);
void xuatHD(Activity a[], int n);

void main()
{
	thucThi();
}

void menu()
{
	printf("\nMenu");
	printf("\n0.Thoat");
	printf("\n1.Doc file");
	printf("\n2.Sap xep hoat dong");
	printf("\n3.Lua chon hoat dong");
}

void thucThi()
{
	Activity a[Max];
	int n, cn;
	do
	{
		menu();
		printf("\nChon chuc nang: ");
		scanf("%d", &cn);
		switch (cn)
		{
		case 0:
		{
			exit(1);
		}break;
		case 1:
		{
			docFile(a, n);
			xuatHD(a, n);
		}break;
		case 2:
		{
			sapXepHD(a, n);
			xuatHD(a, n);
		}break;
		case 3:
		{
			printf("\nCac hoat dong duoc chon:");
			luuChonHD(a, n);
		}break;
		default:
			break;
		}
	} while (1);
}

void docFile(Activity a[], int& n)
{
	char t[] = inputPath;
	FILE* f = fopen(t, "rt");
	if (f == NULL)
		return;
	fscanf(f, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%s%d%d\n", a[i].name, &a[i].start, &a[i].end);
	}
	fclose(f);
}

void swap(Activity& a, Activity& b)
{
	Activity t = a;
	a = b;
	b = t;
}

void sapXepHD(Activity a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j].end < a[i].end)
				swap(a[i], a[j]);
		}
	}
}

void luuChonHD(Activity a[], int n)
{
	sapXepHD(a, n);
	Activity output[Max];
	int d = 0, current = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (a[i].start>=current)
		{
			output[d] = a[i];
			d++;
			current = a[i].end;
		}
	}
	xuatHD(output, d);
}

void xuatHD(Activity a[], int n)
{
	printf("\n%-10s%-10s%-10s", "Ten", "Si", "Ei");
	for (int i = 0; i < n; i++)
	{
		printf("\n%-10s%-10d%-10d", a[i].name, a[i].start, a[i].end);
	}
}