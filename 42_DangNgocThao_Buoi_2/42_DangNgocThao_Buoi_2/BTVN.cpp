//mssv: 2001206904
//ho ten: Dang Ngoc Thao
//noi dung: Chia de tri - buoi 2
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define Max 100

void menu();
void nhapMang(int a[],int &n);
void xuatMang(int a[],int n);
void swap(int &a,int &b);
void daoMang(int a[], int n);
int left(int x, int n);
int right(int x, int n);
int sign(int n);
float soNguyen(int x, int y, int n);
int dem(int x);
int vtMax(int a[], int l, int r);
float tinhTB(int a[], int n);
int phanTuTB(int a[], int n, int l, int r);
void quicksort(int a[], int l, int r);

void thucThi();

void main()
{
	thucThi();
}

void thucThi()
{
	int a[Max], n, cn;
	do
	{
		menu();
		printf("\nChon chuc nang: ");
		scanf("%d", &cn);
		switch (cn)
		{
		case 0:
			exit(1);
		case 1:
		{
			nhapMang(a, n);
			xuatMang(a, n);
		}break;
		case 2:
		{
			daoMang(a, n);
			xuatMang(a, n);
		}break;
		case 3:
		{
			int x, y, demx, demy;
			do
			{
				printf("\nNhap x va y co cung tong so phan tu la chan: ");
				scanf("%d %d", &x, &y);
				demx = dem(x);
				demy = dem(y);
			} while (demx != demy || demx % 2 != 0);
			printf("\n%.0f", soNguyen(x, y, demx));
		}break;
		case 4:
		{
			printf("\nVi tri co phan tu lon nhat trong mang: %d", vtMax(a, 0, n - 1));
		}break;
		case 5:
		{
			printf("\nPhan tu trung binh cua mang: %d", phanTuTB(a, n, 0, n - 1));
		}break;
		case 6:
		{
			quicksort(a, 0, n - 1);
			printf("\nMang sau khi sap");
			xuatMang(a, n);
		}break;
		default:
			break;
		}
	} while (1);
}

void menu()
{
	printf("\n0.Thoat");
	printf("\n1.Nhap xuat mang");
	printf("\n2.Dao mang");
	printf("\n3.Nhan hai so nguyen lon Karatsuba");
	printf("\n4.Tim vi tri phan tu lon nhat trong mang");
	printf("\n5.Tim phan tu trung binh trong mang");
	printf("\n6.Sap xep so am dung truoc, so duong dung sau");
}

void nhapMang(int a[], int& n)
{
	printf("Nhap n: ");
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 199-99;
	}
}

void xuatMang(int a[], int n)
{
	printf("\nMang: ");
	for (int i = 0; i < n; i++)
	{
		printf("%5d", a[i]);
	}
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void daoMang(int a[], int n)
{
	for (int i = 0; i < n / 2; ++i)
	{
		swap(a[i], a[n - i - 1]);
	}
}

int left(int x, int n)
{
	while (x >= pow(10, n))
		x = x / 10;
	return x;
}

int right(int x, int n)
{
	int y = pow(10, n);
	return x % y;
}

int sign(int n)
{
	if (n == 0)
		return 0;
	else if (n > 0)
		return 1;
	else
		return -1;
}

float soNguyen(int x, int y, int n)
{
	int a, b, c, d, m1, m2, m3;
	int s = sign(x) * sign(y);

	x = abs(x);
	y = abs(y);
	if (n == 1)
		return x * y * s;

	a = left(x, n / 2);
	b = right(x, n / 2);
	c = left(y, n / 2);
	d = right(y, n / 2);

	m1 = soNguyen(a, c, n / 2);
	m2 = soNguyen(a - b, d - c, n / 2);
	m3 = soNguyen(b, d, n / 2);
	return s * (m1 * pow(10, n) + (m1 + m2 + m3) * pow(10, n / 2) + m3);
}

int dem(int x)
{
	int dem = 0;
	while (x != 0)
	{
		dem++;
		x = x / 10;
	}
	return dem;
}

int vtMax(int a[], int l, int r)
{
	if (l == r)
		return l;
	int mid = (l + r) / 2;
	int trai = vtMax(a, l, mid);
	int right = vtMax(a, mid + 1, r);
	return a[trai] > a[right] ? trai : right;
}

float tinhTB(int a[], int n)
{
	float tong = 0;
	for (int i = 0; i < n; i++)
		tong = tong + a[i];
	return tong / n;
}

int phanTuTB(int a[], int n, int l, int r)
{
	float kq = tinhTB(a, n);
	if (l == r)
		return a[l];
	int mid = (l + r) / 2;
	int left = phanTuTB(a, n, l, mid);
	int right = phanTuTB(a, n, mid + 1, r);
	return abs(left - int(kq)) < abs(right - int(kq)) ? left : right;
}

void quicksort(int a[], int l, int r)
{
	int x = a[(l + r) / 2], i = l, j = r;
	do
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i < j);
	if (l < j) quicksort(a, l, j);
	if (i < r) quicksort(a, i, r);
}