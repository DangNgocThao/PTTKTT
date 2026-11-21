//#include <iostream>
//#include <fstream>
//using namespace std;
//
//#define Max 100
//
//void thucThi();
//void menu();
//void docFile(char a[], int& n, char b[], int& m);
//void xuLy(char a[], int& n, char b[], int& m);
//
//void main()
//{
//	thucThi();
//}
//
//void thucThi()
//{
//	int n, m, cn;
//	char a[Max], b[Max];
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
//			docFile(a, n, b, m);
//			printf("\nchuoi a: %s", a);
//			printf("\nchuoi b: %s", b);
//		}break;
//		case 2:
//		{
//			xuLy(a, n, b, m);
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
//	printf("\n2.Chuoi a co chua chuoi b khong");
//}
//
//void docFile(char a[], int& n, char b[], int& m)
//{
//	ifstream f;
//	f.open("../data/inputB4.txt");
//	f >> a;
//	f >> b;
//	n = strlen(a);
//	m = strlen(b);
//	f.close();
//}
//
//void xuLy(char a[], int& n, char b[], int& m)
//{
//	int dp[Max][Max] = {};
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= m; ++j)
//		{
//			if (a[i - 1] == b[j - 1])
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			else
//				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//		}
//	}
//	if (dp[n][m] == m)
//		printf("\nChuoi %s chua chuoi %s", a, b);
//	else
//		printf("\nChuoi %s khong chua chuoi %s", a, b);
//}