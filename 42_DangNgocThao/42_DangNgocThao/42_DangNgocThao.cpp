//Dang Ngoc Thao - 2001206904
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define Max 100

void thucThi();
void menu();
void nhapMang(int a[], int& n);
void XuatMang(int a[], int n);
int ktSNT(int n);
int demSNT(int a[], int n);
int ktSCP(int n);
void nhapMaTran(float a[][Max], int& n);
void xuatMaTran(float a[][Max], int n);
float timMaxSCP(float a[][Max], int n);

void main()
{
	thucThi();
}

void thucThi()
{
	int cn, a[Max], n, m;
	float b[Max][Max];
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
			nhapMang(a, n);
			XuatMang(a, n);
		}break;
		case 2:
		{
			printf("\nSo so nguyen to trong mang: %d", demSNT(a, n));
		}break;
		case 3:
		{
			nhapMaTran(b, m);
			xuatMaTran(b, m);
		}break;
		case 4:
		{
			float max = timMaxSCP(b, m);
			if (max == INT_MIN)
				printf("Khong co so chinh phuong trong ma tran");
			else
				printf("So chinh phuong trong ma tran: %.2f", max);
		}break;
		default:
			break;
		}
	} while (1);
}

void menu()
{
	printf("\nMenu");
	printf("\n0.Thoat");
	printf("\n1.Nhap xuat mang");
	printf("\n2.Dem so nguyen to trong mang");
	printf("\n3.Nhap ma tran vuong");
	printf("\n4.tim so chinh phuong lon nhat trong ma tran");
}

void nhapMang(int a[], int& n)
{
	printf("\nNhap n: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
}

void XuatMang(int a[], int n)
{
	printf("\nMang: ");
	for (int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}

int ktSNT(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int ktSCP(int n)
{
	if (n <= 1)
		return 0;
	int t = sqrt((double)n);
	if (t * t == n)
		return 1;
	return 0;
}

int demSNT(int a[], int n)
{
	if (n == 1)
		return ktSNT(a[0]);
	int mid = n / 2;
	int l = demSNT(a, mid);
	int r = demSNT(a + mid, n - mid);
	return l + r;
}

void nhapMaTran(float a[][Max], int& n)
{
	printf("\nNhap n: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
}

void xuatMaTran(float a[][Max], int n)
{
	printf("\nMa tran\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%6.1f", a[i][j]);
		}
		printf("\n");
	}
}

float timMaxSCP(float a[][Max], int n)
{
	float max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktSCP((int)a[i][j]) == 1 && a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}
