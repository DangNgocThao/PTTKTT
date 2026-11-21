#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define Max 100

struct Vat
{
	char ten;
	int tl, gt;
};

struct OBTra
{
	int f, x;
};

void thucThi();
void menu();
int tinhToHop(int n, int k);
void docFile(Vat dsVat[], int& n, int& w);
void xuatFile(Vat dsVat[], int n, int w);
void taoBangTra(OBTra bangTra[][Max], int w, int n, Vat dsVat[]);
void xuatBangTra(OBTra bangTra[][Max], int w, int n, Vat dsVat[]);
void xuLy(OBTra bangTra[][Max], int w, int n, Vat dsVat[]);
OBTra timMaxCot(OBTra bangTra[][Max], int w, int n, int col, int& vtv);

void main()
{
	thucThi();
}

void thucThi()
{
	Vat a[Max];
	OBTra b[Max][Max];
	int n, k, cn, w;
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
			printf("\nNhap n: ");
			scanf("%d", &n);
			printf("Nhap k: ");
			scanf("%d", &k);
			printf("To hop %d chap %d: %d", n, k, tinhToHop(n, k));
		}break;
		case 2:
		{
			docFile(a, n, w);
			xuatFile(a, n, w);
		}break;
		case 3:
		{
			taoBangTra(b, w, n, a);
			xuatBangTra(b, w, n, a);
		}break;
		case 4:
		{
			taoBangTra(b, w, n, a);
			xuLy(b, w, n, a);
		}break;
		default:
			printf("\nChua lam");
			break;
		}
	} while (1);
}

void menu()
{
	printf("\nMenu");
	printf("\n0.Thoat");
	printf("\n1.Tinh to hop");
	printf("\n2.Doc file");
	printf("\n3.Tao bang tra");
	printf("\n4.Bai toan balo quy hoach dong");
}

int tinhToHop(int n, int k)
{
	int a[Max][Max];
	if (k == 0 || k == n)
		return 1;
	else
	{
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				if (i == j || j == 0)
					a[i][j] = 1;
				else
					a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
	return a[n][k];
}

void docFile(Vat dsVat[], int& n, int& w)
{
	ifstream in;
	in.open("../data/input.txt");
	if (in)
	{
		in >> w;
		in >> n;
		for (int i = 0; i < n; i++)
		{
			in >> dsVat[i].ten;
			in >> dsVat[i].tl;
			in >> dsVat[i].gt;
		}
	}
}

void xuatFile(Vat dsVat[], int n, int w)
{
	printf("\nW = %d", w);
	printf("\nn = %d", n);
	printf("\n%-10s%-20s%s", "Ten", "Trong luong", "Gia tri");
	for (int i = 0; i < n; i++)
	{
		printf("\n%-10c%-20d%d", dsVat[i].ten, dsVat[i].tl, dsVat[i].gt);
	}
}

void taoBangTra(OBTra bangTra[][Max], int w, int n, Vat dsVat[])
{
	for (int i = 0; i < n; i++)
	{
		bangTra[i][0].f = bangTra[i][0].x = 0;
	}

	for (int j = 1; j <= w; j++)
	{
		bangTra[0][j].x = j / dsVat[0].tl;
		bangTra[0][j].f = bangTra[0][j].x * dsVat[0].gt;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			int slMax = j / dsVat[i].tl, Fval[Max];
			for (int k = 0; k <= slMax; k++)
			{
				int wTam = j - k * dsVat[i].tl;
				int F = k * dsVat[i].gt + bangTra[i - 1][wTam].f;
				Fval[k] = F;
			}
			int max = Fval[0], vt = 0;
			for (int l = 0; l <= slMax; l++)
			{
				if (Fval[l] > max)
				{
					max = Fval[l];
					vt = l;
				}
			}
			bangTra[i][j].x = vt;
			bangTra[i][j].f = max;
		}
	}
}

void xuatBangTra(OBTra bangTra[][Max], int w, int n, Vat dsVat[])
{
	printf("\n");
	for (int k = 0; k < n; k++)
	{
		for (int v = 0; v <= w; v++)
		{
			printf(" %-4d%-2d|", bangTra[k][v].f, bangTra[k][v].x);
		}
		printf("\n");
	}
}

void xuLy(OBTra bangTra[][Max], int w, int n, Vat dsVat[])
{
	int vtv;
	if (w <= 1)
		return;
	else
	{
		OBTra a = timMaxCot(bangTra, w, n, w, vtv);
		printf("\nLay %d vat %c \nduoc gia tri = %d", a.x, dsVat[vtv].ten, a.f);
		w = w - a.x * dsVat[vtv].tl;
		if (w <= 1)
			return;
		xuLy(bangTra, w, w, dsVat);
	}
}

OBTra timMaxCot(OBTra bangTra[][Max], int w, int n, int col, int& vtv)
{
	OBTra max = bangTra[0][col];
	vtv = 0;
	for (int i = 1; i < n; i++)
	{
		if (bangTra[i][col].f > max.f)
		{
			max = bangTra[i][col];
			vtv = i;
		}
	}
	return max;
}