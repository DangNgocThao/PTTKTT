//#include <conio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <stdio.h>
//#include <stack>
//using namespace std;
//
//struct thanhPho
//{
//	char ten[10];
//	int hoanhdo, tungdo;
//};
//
//struct canh
//{
//	char dau[10], cuoi[10];
//	float dodai;
//};
//
//void docFile(char filename[100], thanhPho a[], canh b[],int &n,int &m);
//void xuat(canh b[],int m);
//void thucThi();
//void menu();
//void tangDan(canh b[],int m);
//void swap(canh& a, canh& b);
//int maHoaChu(char x[]);
//int kiemTraBac(int a[][100], int n,canh b);
//int ktChuTrinhThieu(int a[][100], int n, int i);
//void copyMang(int a[][100], int b[][100],int n);
//void dinhKe(int a[][100], int b[], int n, int x,int &m);
//void boCanhXY(int a[][100], int x, int y);
//void chonCanhXY(int a[][100], int x, int y);
//void duyetDuongDi(canh b[], int n, int m);
//
//void main()
//{
//	thucThi();
//}
//
//void menu()
//{
//	printf("\nMenu");
//	printf("\n0.Thoat");
//	printf("\n1.Doc file");
//	printf("\n2.Sap xep tang dan theo do dai");
//	printf("\n3.Tim duong di cua nguoi giao hang");
//}
//
//void thucThi()
//{
//	int n, m, cn;
//	canh b[31], c[31];
//	thanhPho a[31];
//	char filename[100] = "../data/thanhpho.txt";
//	do
//	{
//		menu();
//		printf("\nChon chuc nang: ");
//		scanf("%d", &cn);
//		switch (cn)
//		{
//		case 0:
//		{
//			exit(1);
//		}break;
//		case 1:
//		{
//			docFile(filename, a, b, n, m);
//			xuat(b, m);
//		}break;
//		case 2:
//		{
//			tangDan(b, m);
//			printf("\nMang sau khi sap xep tang dan theo do dai: ");
//			xuat(b, m);
//		}break;
//		case 3:
//		{
//			tangDan(b, m);
//			printf("\nChon cac canh: ");
//			duyetDuongDi(b, n, m);
//		}break;
//		default:
//			break;
//		}
//	} while (1);
//}
//
//void tangDan(canh b[], int m)
//{
//	for (int i = 0; i < m - 1; i++)
//		for (int j = i + 1; j < m; j++)
//			if (b[j].dodai < b[i].dodai)
//				swap(b[i], b[j]);
//}
//
//void swap(canh& a, canh& b)
//{
//	canh c = a;
//	a = b;
//	b = c;
//}
//
//void docFile(char filename[100], thanhPho a[], canh b[], int& n, int& m)
//{
//	FILE* f = fopen(filename, "rt");
//	if (f == NULL)
//		return;
//	m = 0; 
//	int kq, kq1;
//	fscanf(f, "%d\n", &n);
//	for (int i = 0; i < n; i++)
//	{
//		fscanf(f, "%s%d%d\n", a[i].ten, &a[i].hoanhdo, &a[i].tungdo);
//	}
//	for (int i = 0; i < n - 1; i++)
//		for (int j = i + 1; j < n; j++)
//		{
//			strcpy(b[m].dau, a[i].ten);
//			strcpy(b[m].cuoi, a[j].ten);
//			kq = pow(a[i].hoanhdo - a[j].hoanhdo, 2);
//			kq1 = pow(a[i].tungdo - a[j].tungdo, 2);
//			b[m].dodai = sqrt(kq * 1.0 + kq1);
//			m++;
//		}
//	fclose(f);
//}
//
//int maHoaChu(char x[])
//{
//	if (strcmp(x, "a") == 0)
//		return 0;
//	if (strcmp(x, "b") == 0)
//		return 1;
//	if (strcmp(x, "c") == 0)
//		return 2;
//	if (strcmp(x, "d") == 0)
//		return 3;
//	if (strcmp(x, "e") == 0)
//		return 4;
//	if (strcmp(x, "f") == 0)
//		return 5;
//}
//
//int kiemTraBac(int a[][100], int n, canh b)
//{
//	int x = maHoaChu(b.dau), y = maHoaChu(b.cuoi);
//	int dem = 0;
//	for (int i = 0; i < n; i++)
//		if (a[x][i] == 1)
//			dem += 1;
//	if (dem >= 2)
//		return 0;
//	dem = 0;
//	for (int i = 0; i < n; i++)
//		if (a[y][i] == 1)
//			dem += 1;
//	if (dem >= 2)
//		return 0;
//	return 1;
//}
//
//int ktChuTrinhThieu(int a[][100], int n, int i)
//{
//	int b[100][100], y, b1[100], m;
//	copyMang(a, b, n);
//	stack <int>s;
//	s.push(i);
//	while (!s.empty())
//	{
//		y = s.top();
//		dinhKe(b, b1, n, y, m);
//		if (m != 0)
//		{
//			if (i == b1[0])
//				return 0;
//			s.push(b1[0]);
//			boCanhXY(b, y, b1[0]);
//		}
//		else
//			s.pop();
//	}
//	return 1;
//}
//
//void copyMang(int a[][100], int b[][100], int n)
//{
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			b[i][j] = a[i][j];
//}
//
//void dinhKe(int a[][100], int b[], int n, int x, int& m)
//{
//	m = 0;
//	for (int i = 0; i < n; i++)
//		if (a[x][i] == 1)
//		{
//			b[m] = i;
//			m++;
//		}
//}
//
//void boCanhXY(int a[][100], int x, int y)
//{
//	a[x][y] = 0;
//	a[y][x] = 0;
//}
//
//void chonCanhXY(int a[][100], int x, int y)
//{
//	a[x][y] = 1;
//	a[y][x] = 1;
//}
//
//void duyetDuongDi(canh b[], int n, int m)
//{
//	canh c[100]; int m1 = 0, a[100][100], x, y;
//	for (int i = 0; i < m; i++)
//	{
//		x = maHoaChu(b[i].dau), y = maHoaChu(b[i].cuoi);
//		if (kiemTraBac(a, n, b[i]) == 1)
//		{
//			chonCanhXY(a, x, y);
//			if (m1 == n - 1)
//			{
//				c[m1] = b[i];
//				m1++;
//				break;
//			}
//			else
//				if (m1 < n - 1 && ktChuTrinhThieu(a, n, x) == 1)
//				{
//					c[m1] = b[i];
//					m1++;
//				}
//				else boCanhXY(a, x, y);
//		}
//	}
//	xuat(c, m1);
//}
//
//void xuat(canh b[],int m)
//{
//	printf("\nCanh\tDo dai");
//	for (int i = 0; i < m; i++)
//		printf("\n%s%s\t%.2f", b[i].dau, b[i].cuoi, b[i].dodai);
//}