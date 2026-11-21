#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <iostream>
using namespace std;

#define Max 100

struct MonHoc
{
	char ten[Max];
	int batDau, ketThuc;
};

void menu();
void thucThi();
void docFile(MonHoc a[],int &n);
void xuat(MonHoc a[],int n);
void swap(MonHoc &a,MonHoc&b);
void xepTheoKetThuc(MonHoc a[],int n);
void xoaMonHoc(MonHoc a[],int &n,int j);
void xuLy(MonHoc a[],int &n);

void main()
{
	thucThi();
}

void menu()
{
	printf("\nMenu");
	printf("\n0.Thoat");
	printf("\n1.Doc file");
	printf("\n2.Xep theo thoi gian ket thuc");
	printf("\n3.Xep lich 1 phong");
}

void thucThi()
{
	MonHoc a[Max];
	int cn,n;
	do
	{
		menu();
		printf("\nChon chuc nang: ");
		scanf("%d",&cn);
		switch (cn)
		{
		case 0:
			{
				exit(1);
			}break;
		case 1:
			{
				docFile(a,n);
				xuat(a,n);
			}break;
		case 2:
			{
				xepTheoKetThuc(a,n);
				xuat(a,n);
			}break;
		case 3:
			{
				xepTheoKetThuc(a,n);
				xuLy(a,n);
				xuat(a,n);
			}break;
		default:
			break;
		}
	} while (1);
}

void docFile(MonHoc a[],int &n)
{
	ifstream in;
	in.open("../data/Input.txt");
	if (in)
	{
		in>>n;
		for (int i = 0; i < n; i++)
		{
			in>>a[i].ten;
			in>>a[i].batDau;
			in>>a[i].ketThuc;
		}
	}
	in.close();
}

void xuat(MonHoc a[],int n)
{
	printf("\n%-15s%-20s%s","Ten mon","Thoi gian bat dau","Thoi gian ket thuc");
	for (int i = 0; i < n; i++)
	{
		printf("\n%-15s%-20d%d",a[i].ten,a[i].batDau,a[i].ketThuc);
	}
}

void swap(MonHoc &a,MonHoc&b)
{
	MonHoc t=a;
	a=b;
	b=t;
}

void xepTheoKetThuc(MonHoc a[],int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(a[i].ketThuc > a[j].ketThuc)
				swap(a[i], a[j]);
		}
	}
}

void xoaMonHoc(MonHoc a[],int &n,int j)
{
	if(j>=n)
		j=n-1;
	for (int i = j; i < n-1; i++)
	{
		a[i]=a[i+1];
	}
	--n;
}

void xuLy(MonHoc a[],int &n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if(a[i].ketThuc >= a[j].batDau)
			{
				xoaMonHoc(a,n,j);
				j--;
			}
		}
	}
}