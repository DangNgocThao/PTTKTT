////mssv: 2001206904
////ho ten: Dang Ngoc Thao
////noi dung: Chia de tri - buoi 2
//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//
//#define Max 10
//
//void thucThi();
//void menu();
//void nhapMaTran(int a[][Max],int n);
//void xuatMaTran(int a[][Max],int n);
//void chiNho(int x[][Max],int n,int a[][Max],int b[][Max],int c[][Max],int d[][Max]);
//void toHop(int x[][Max],int n,int a[][Max],int b[][Max],int c[][Max],int d[][Max]);
//void cong2MaTran(int a[][Max],int b[][Max],int c[][Max],int n);
//void tru2MaTran(int a[][Max],int b[][Max],int c[][Max],int n);
//void nhan2MaTran(int a[][Max],int b[][Max],int c[][Max],int n);
//void reduction(float a[][Max], int n, int pivot, int col);
//void chia2MaTran(int a[][Max],int b[][Max],float c[][Max],int n);
//void Strassen(int a[][Max],int b[][Max],int n,int c[][Max]);
//
//void main()
//{
//	thucThi();
//}
//
//void thucThi()
//{
//	int a[Max][Max], b[Max][Max], c[Max][Max], n, cn;
//	do
//	{
//		menu();
//		printf("\nChon chuc nang: ");
//		scanf("%d", &cn);
//		switch (cn)
//		{
//		case 0:
//			exit(1);
//		case 1:
//		{
//			do
//			{
//				printf("Nhap cap ma tran chan: ");
//				scanf("%d", &n);
//			} while (n % 2 != 0);
//			nhapMaTran(a, n);
//			xuatMaTran(a, n);
//			nhapMaTran(b, n);
//			xuatMaTran(b, n);
//			Strassen(a, b, n, c);
//			xuatMaTran(c, n);
//		}break;
//		default:
//			break;
//		}
//	} while (1);
//}
//
//void menu()
//{
//	printf("\n0.Thoat");
//	printf("\n1.Nhan ma tran Strassen");
//}
//
//void nhapMaTran(int a[][Max], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			a[i][j] = rand() % 10;
//		}
//	}
//}
//void xuatMaTran(int a[][Max], int n)
//{
//	printf("\nMa tran:\n");
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%5d", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//void chiNho(int x[][Max], int n, int a[][Max], int b[][Max], int c[][Max], int d[][Max])
//{
//	for (int i = 0; i < n / 2; i++)
//	{
//		for (int j = 0; j < n / 2; j++)
//		{
//			a[i][j] = x[i][j];
//		}
//	}
//	for (int i = 0; i < n / 2; i++)
//	{
//		for (int j = n / 2; j < n; j++)
//		{
//			b[i][j - n / 2] = x[i][j];
//		}
//	}
//	for (int i = n / 2; i < n; i++)
//	{
//		for (int j = 0; j < n / 2; j++)
//		{
//			c[i - n / 2][j] = x[i][j];
//		}
//	}
//	for (int i = n / 2; i < n; i++)
//	{
//		for (int j = n / 2; j < n; j++)
//		{
//			d[i - n / 2][j - n / 2] = x[i][j];
//		}
//	}
//}
//
//void toHop(int x[][Max], int n, int a[][Max], int b[][Max], int c[][Max], int d[][Max])
//{
//	for (int i = 0; i < n / 2; i++)
//	{
//		for (int j = 0; j < n / 2; j++)
//		{
//			x[i][j] = a[i][j];
//		}
//	}
//	for (int i = 0; i < n / 2; i++)
//	{
//		for (int j = n / 2; j < n; j++)
//		{
//			x[i][j] = b[i][j - n / 2];
//		}
//	}
//	for (int i = n / 2; i < n; i++)
//	{
//		for (int j = 0; j < n / 2; j++)
//		{
//			x[i][j] = c[i - n / 2][j];
//		}
//	}
//	for (int i = n / 2; i < n; i++)
//	{
//		for (int j = n / 2; j < n; j++)
//		{
//			x[i][j] = d[i - n / 2][j - n / 2];
//		}
//	}
//}
//
//void cong2MaTran(int a[][Max], int b[][Max], int c[][Max], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			c[i][j] = a[i][j] + b[i][j];
//		}
//	}
//}
//void tru2MaTran(int a[][Max], int b[][Max], int c[][Max], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			c[i][j] = a[i][j] - b[i][j];
//		}
//	}
//}
//void nhan2MaTran(int a[][Max], int b[][Max], int c[][Max], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			int t = 0;
//			for (int k = 0; k < n; k++)
//			{
//				t += a[i][k] * b[k][j];
//			}
//			c[i][j] = t;
//		}
//	}
//}
//
//void reduction(float a[][Max], int n, int pivot, int col)
//{
//	int i, j;
//	float factor;
//	factor = a[pivot][col];
//
//	for (i = 0; i < 2 * n; i++) {
//		a[pivot][i] /= factor;
//	}
//
//	for (i = 0; i < n; i++) {
//		if (i != pivot) {
//			factor = a[i][col];
//			for (j = 0; j < 2 * n; j++) {
//				a[i][j] = a[i][j] - a[pivot][j] * factor;
//			}
//		}
//	}
//}
//
//void chia2MaTran(int a[][Max], int b[][Max], float c[][Max], int n)
//{
//	float copy[Max][Max];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			copy[i][j] = b[i][j];
//
//	for (int i = 0; i < n; i++)
//		reduction(copy, n, i, i);
//
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			float t = 0;
//			for (int k = 0; k < n; k++)
//				t += a[i][k] * copy[k][j];
//			c[i][j] = t;
//		}
//}
//
//void Strassen(int a[][Max], int b[][Max], int n, int c[][Max])
//{
//	if (n == 2)
//	{
//		nhan2MaTran(a, b, c, n);
//		return;
//	}
//	else
//	{
//		int a11[Max][Max], a12[Max][Max], a21[Max][Max], a22[Max][Max], b11[Max][Max], b12[Max][Max], b21[Max][Max], b22[Max][Max];
//		int mtkq11[Max][Max], mtkq12[Max][Max], mtkq2[Max][Max], mtkq3[Max][Max], mtkq4[Max][Max], mtkq5[Max][Max], mtkq61[Max][Max], mtkq62[Max][Max], mtkq71[Max][Max], mtkq72[Max][Max];
//		int P1[Max][Max], P2[Max][Max], P3[Max][Max], P4[Max][Max], P5[Max][Max], P6[Max][Max], P7[Max][Max];
//		chiNho(a, n, a11, a12, a21, a22);
//		chiNho(b, n, b11, b12, b21, b22);
//		cong2MaTran(a11, a22, mtkq11, n / 2);
//		cong2MaTran(b11, b22, mtkq12, n / 2);
//		cong2MaTran(a21, a22, mtkq2, n / 2);
//		tru2MaTran(b12, b22, mtkq3, n / 2);
//		tru2MaTran(b21, b11, mtkq4, n / 2);
//		cong2MaTran(a11, a12, mtkq5, n / 2);
//		tru2MaTran(a21, a11, mtkq61, n / 2);
//		cong2MaTran(b11, b12, mtkq62, n / 2);
//		tru2MaTran(a12, a22, mtkq71, n / 2);
//		cong2MaTran(b21, b22, mtkq72, n / 2);
//
//		Strassen(mtkq11, mtkq12, n / 2, P1);
//		Strassen(mtkq2, b11, n / 2, P2);
//		Strassen(a11, mtkq3, n / 2, P3);
//		Strassen(a22, mtkq4, n / 2, P4);
//		Strassen(mtkq5, b22, n / 2, P5);
//		Strassen(mtkq61, mtkq62, n / 2, P6);
//		Strassen(mtkq71, mtkq72, n / 2, P7);
//
//		int C11[Max][Max], C12[Max][Max], C21[Max][Max], C22[Max][Max];
//		int M1[Max][Max], M2[Max][Max], M3[Max][Max];
//		int M5[Max][Max], M6[Max][Max];
//		cong2MaTran(P1, P4, M1, n / 2);
//		tru2MaTran(M1, P5, M2, n / 2);
//		cong2MaTran(M2, P7, C11, n / 2);
//
//		cong2MaTran(P3, P5, C12, n / 2);
//		cong2MaTran(P2, P4, C21, n / 2);
//		cong2MaTran(P1, P3, M5, n / 2);
//		tru2MaTran(M5, P2, M6, n / 2);
//		cong2MaTran(M6, P6, C22, n / 2);
//		toHop(c, n, C11, C12, C21, C22);
//	}
//}