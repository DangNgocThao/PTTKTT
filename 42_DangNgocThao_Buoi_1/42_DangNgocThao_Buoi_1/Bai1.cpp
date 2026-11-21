//mssv: 2001206904
//ho ten: Dang Ngoc Thao
//noi dung: Chia de tri - buoi 1
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define Max 100

void menu();
void nhapMang(int a[],int &n);
void nhapMangRand(int a[],int &n);
void xuatMang(int a[],int n);
void nhapMangDQ(int a[],int n);
void xuatMangDQ(int a[],int n);
int tongMang(int a[],int n);
int tongMangCDT(int a[],int n);
int tongChan(int a[], int n);
int tichVTChan(int a[], int l, int r);
void xuatSo2ChuSo(int a[], int n);
int vtMax(int a[], int l, int r);
int tinhMu(int n, int m);
float tbMang(int a[], int n, int t);
void swap(int& a, int& b);
void sortDQ(int a[], int n);
void copyMang(int a[], int b[], int vt, int n);
void merge(int a[], int b[], int c[], int n);
void sapXepMerge(int a[], int n);
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
			printf("Nhap n: ");
			scanf("%d", &n);
			nhapMangDQ(a, n);
			xuatMangDQ(a, n);
		}break;
		case 3:
		{
			nhapMangRand(a, n);
			xuatMang(a, n);
		}break;
		case 4:
		{
			printf("\nTong mang: %d", tongMang(a, n));
		}break;
		case 5:
		{
			printf("\nTong mang chia de tri: %d", tongMangCDT(a, n));
		}break;
		case 6:
		{
			printf("\nTong cac phan tu chan: %d", tongChan(a, n));
		}break;
		case 7:
		{
			printf("\nTich vi tri chan: %d", tichVTChan(a, 0, n - 1));
		}break;
		case 8:
		{
			printf("\nCac phan tu 2 chu so: ");
			xuatSo2ChuSo(a, n);
		}break;
		case 9:
		{
			printf("\nVi tri co phan tu lon nhat trong mang: %d", vtMax(a, 0, n - 1));
		}break;
		case 10:
		{
			int b, m;
			printf("\nNhap a: ");
			scanf("%d", &b);
			printf("\nNhap n: ");
			scanf("%d", &m);
			printf("\nPhep tinh bang: %d", tinhMu(b, m));
		}break;
		case 11:
		{
			printf("\nPhan tu trung binh cua mang: %.3f", tbMang(a, n, n));
		}break;
		case 12:
		{
			sapXepMerge(a, n);
		}break;
		case 13:
		{
			quicksort(a, 0, n - 1);
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
	printf("\n1.Nhap xuat mang binh thuong");
	printf("\n2.Nhap xuat mang de quy");
	printf("\n3.Khoi tao mang random");
	printf("\n4.Tong mang de quy");
	printf("\n5.Tong cac phan tu chia de tri");
	printf("\n6.Tong cac phan tu chan chia de tri");
	printf("\n7.Tich cac phan tu o vi tri chan chia de tri");
	printf("\n8.Xuat cac phan tu co dung 2 chu so chia de tri");
	printf("\n9.Vi tri cua phan tu lon nhat chia de tri");
	printf("\n10.Tinh a^n chia de tri");
	printf("\n11.Phan tu trung bi chia de tri");
	printf("\n12.Sap xep Merge Sort");
	printf("\n13.Sap xep Quick Sort");
}

void nhapMang(int a[], int& n)
{
	printf("Nhap n: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

void nhapMangRand(int a[], int& n)
{
	printf("Nhap n: ");
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 99;
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

void nhapMangDQ(int a[], int n)
{
	if (n == 0)
		return;
	//srand((unsigned)time(NULL));
	nhapMangDQ(a, n - 1);
	//a[n - 1] = rand() % 100;
	printf("Nhap a[%d]: ", n - 1);
	scanf("%d", &a[n - 1]);
}

void xuatMangDQ(int a[], int n)
{
	if (n == 0)
		return;
	xuatMang(a, n - 1);
	printf("%5d", a[n - 1]);
}

int tongMang(int a[], int n)
{
	if (n == 1)
		return a[0];
	return tongMang(a, n - 1) + a[n - 1];
}

int tongMangCDT(int a[], int n)
{
	if (n == 1)
		return a[0];
	int mid = n / 2;
	int rise = n - mid;
	return tongMangCDT(a, mid) + tongMangCDT(a + mid, rise);
}

int tongChan(int a[], int n)
{
	if (n == 1)
	{
		if (a[0] % 2 == 0)
			return a[0];
		return 0;
	}
	int mid = n / 2;
	int rise = n - mid;
	return tongChan(a, mid) + tongChan(a + mid, rise);
}

int tichVTChan(int a[], int l, int r)
{
	if (l == r)
	{
		if (l % 2 == 0)
			return a[l];
		return 1;
	}
	int mid = (l + r) / 2;
	return tichVTChan(a, l, mid) * tichVTChan(a, mid + 1, r);
}

void xuatSo2ChuSo(int a[], int n)
{
	if (n == 1)
	{
		if (a[0] > 9 && a[0] < 100)
			printf("%5d", a[0]);
		return;
	}
	int mid = n / 2;
	int rise = n - mid;
	xuatSo2ChuSo(a, mid);
	xuatSo2ChuSo(a + mid, rise);
}

int vtMax(int a[], int l, int r)
{
	if (l == r)
		return l;
	int mid = (l + r) / 2;
	int left = vtMax(a, l, mid);
	int right = vtMax(a, mid + 1, r);
	return a[left] > a[right] ? left : right;
}

int tinhMu(int a, int n)
{
	if (n == 1)
		return a;
	int mid = n / 2;
	int rise = n - mid;
	return tinhMu(a, mid) * tinhMu(a, rise);
}

float tbMang(int a[], int n, int t)
{
	if (n == 1)
		return a[0] / (float)t;
	int mid = n / 2;
	int rise = n - mid;
	return tbMang(a, mid, t) + tbMang(a + mid, rise, t);
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void sortDQ(int a[], int n)
{
	if (n == 0)
		return;
	for (int i = 0; i < n; i++)
		if (a[n - 1] < a[i])
			swap(a[n - 1], a[i]);
	sortDQ(a, n - 1);
}

void copyMang(int a[], int b[], int s, int e)
{
	for (int i = 0, j = s; i < e; i++, j++)
		b[i] = a[j];
}

void merge(int a[], int b[], int c[], int n)
{
	int i = 0, j = 0, k = 0;
	for (i = 0, j = 0; j < n / 2 && k < (n - n / 2); i++)
	{
		if (b[j] < c[k])
		{
			a[i] = b[j];
			j++;
		}
		else
		{
			a[i] = c[k];
			k++;
		}
	}
	while (j < n / 2)
	{
		a[i] = b[j];
		i++, j++;
	}
	while (k < n - n / 2)
	{
		a[i] = c[k];
		i++, k++;
	}
}

void sapXepMerge(int a[], int n)
{
	int b[Max / 2], c[Max / 2];
	if (n <= 1)
	{
		printf("\nMang sau khi sap xep tang dan: %d", a[0]);
		return;
	}
	copyMang(a, b, 0, n / 2);
	copyMang(a, c, n / 2, n);
	sortDQ(b, n / 2);
	sortDQ(c, n - n / 2);
	merge(a, b, c, n);
	printf("\nMang sau khi sap xep tang dan: ");
	xuatMang(a, n);
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