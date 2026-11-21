//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <fstream>
//
//using namespace std;
//
//#define Max 100
//
//void docFile(int a[][Max], int& m, int& n);
//void xuat(int a[][Max], int m, int n);
//int maxDuong(int a[][Max], int m, int n);
//void thucThi();
//void menu();
//
//void main()
//{
//	thucThi();
//}
//
//void thucThi()
//{
//	int a[Max][Max];
//	int m, n, cn;
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
//			docFile(a, m, n);
//			xuat(a, m, n);
//		}break;
//		case 2:
//		{
//			printf("\nTong duong di co diem lon nhat la: %d", maxDuong(a, m, n));
//		}break;
//		default:
//			printf("\nChua lam");
//			break;
//		}
//	} while (1);
//}
//
//void menu()
//{
//	printf("\nMenu");
//	printf("\n0.Thoat");
//	printf("\n1.Doc file");
//	printf("\n2.Tim duong di lon nhat");
//}
//
//void docFile(int a[][Max], int& m, int& n)
//{
//	ifstream f;
//	f.open("../data/inputB3.txt");
//	f >> m;
//	f >> n;
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			f >> a[i][j];
//		}
//	}
//	f.close();
//}
//
//void xuat(int a[][Max], int m, int n)
//{
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			printf("%4d", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int maxDuong(int a[][Max], int m, int n)
//{
//	for (int j = 2; j <= n; j++)
//	{
//		for (int i = 1; i <= m; i++)
//		{
//			a[i][j] += max(a[i - 1][j - 1], max(a[i][j - 1], a[i + 1][j - 1]));
//		}
//	}
//
//	int kq = INT_MIN;
//
//	for (int i = 1; i <= m; i++)
//	{
//		kq = max(kq, a[i][n]);
//	}
//	return kq;
//}