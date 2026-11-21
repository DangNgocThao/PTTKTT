//#include <conio.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//struct hoatdong
//{
//	char ten[50], ngayS[10], ngayE[10], timeS[10], timeE[10];
//	float timeS_mahoa, timeE_mahoa;
//};
//
//void menu();
//void thucThi();
//void docFile(char filename[100], hoatdong a[], int& n);
//void xuat(hoatdong a[], int n);
//void swap(hoatdong& a, hoatdong& b);
//void tangDanTheoNgayE(hoatdong a[], int n);
//void tangDanTheoTime(hoatdong a[], int n);
//int maHoa(char );
//float maHoaTime(char s[]);
//void xuLy(hoatdong a[], int n);
//void xuatMaHoa(hoatdong a[], int n);
//int kt(float s, float f, float s0, float f0);
//void xoaHoatDong(hoatdong a[], int n, hoatdong b[], int& m);
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
//	printf("\n2.Tang dan theo dayE va timeE");
//	printf("\n3.Lap lich");
//}
//
//void thucThi()
//{
//	char filename[100] = "../data/ngaygio.txt";
//	hoatdong a[100], b[50];
//	int n, m, cn;
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
//			docFile(filename, a, n);
//			printf("\nNoi dung::::::::::::::::::::::::::::::::::::::::::::");
//			xuat(a, n);
//		}break;
//		case 2:
//		{
//			printf("\nNoi dung sau khi tang dan theo dayE va timeE::::::::::::::::::::::::::::::::::::::::::::");
//			tangDanTheoNgayE(a, n);
//			tangDanTheoTime(a, n);
//			xuat(a, n);
//		}break;
//		case 3:
//		{
//			tangDanTheoNgayE(a, n);
//			tangDanTheoTime(a, n);
//			xuLy(a, n);
//
//			//printf("\nNoi dung sau khi da ma hoa::::::::::::::::::::::::::::::::::::::::::::");
//			//xuatMaHoa(a, n);
//
//			xoaHoatDong(a, n, b, m);
//			printf("\nNoi dung cac cuoc hop duoc chon::::::::::::::::::::::::::::::::::::::::::::");
//			xuat(b, m);
//		}break;
//		default:
//			break;
//		}
//	} while (1);
//}
//
//void docFile(char filename[100], hoatdong a[], int& n)
//{
//	FILE* f = fopen(filename, "rt");
//	if (f == NULL)
//		return;
//	n = 0;
//	while (!feof(f))
//	{
//		fscanf(f, "\n%[^#]#%[^#]#%[^#]#%[^#]#%s", a[n].ten, a[n].ngayS, a[n].timeS, a[n].ngayE, a[n].timeE);
//		n++;
//	}
//	fclose(f);
//}
//
//void xuat(hoatdong a[], int n)
//{
//	printf("\nTen::\t\t\t\t\tdayS::\t  timeS::   dayE::    timeE::");
//	for (int i = 0; i < n; i++)
//		printf("\n%-40s%-10s%-10s%-10s%-10s", a[i].ten, a[i].ngayS, a[i].timeS, a[i].ngayE, a[i].timeE);
//}
//
//void xuatMaHoa(hoatdong a[], int n)
//{
//	printf("\nTen::\t\t\t\t\ttimeS_mahoa::\t  timeE_mahoa::");
//	for (int i = 0; i < n; i++)
//		printf("\n%-40s%-10.2f\t  %-10.2f", a[i].ten, a[i].timeS_mahoa, a[i].timeE_mahoa);
//}
//
//void swap(hoatdong& a, hoatdong& b)
//{
//	hoatdong c = a;
//	a = b;
//	b = c;
//}
//
//void tangDanTheoNgayE(hoatdong a[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//		for (int j = i + 1; j < n; j++)
//			if (strcmp(a[i].ngayE, a[j].ngayE) > 0)
//				swap(a[i], a[j]);
//	int i = 0;
//	while (strcmp(a[i].ngayE, "Chu nhat") == 0)
//	{
//		a[n] = a[i];
//		n++, i++;
//	}
//	while (strcmp(a[0].ngayE, "Chu nhat") == 0)
//	{
//		for (int i = 0; i < n - 1; i++)
//			a[i] = a[i + 1];
//		n--;
//	}
//}
//
//void tangDanTheoTime(hoatdong a[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//		for (int j = i + 1; j < n; j++)
//			if (strcmp(a[i].ngayE, a[j].ngayE) == 0)
//				if (strcmp(a[i].timeE, a[j].timeE) > 0)
//					swap(a[i], a[j]);
//}
//
//int maHoa(char s)
//{
//	int i = 48;
//	if (s == 't')
//		return 8;
//	while (s < 58)
//	{
//		if (s == i)
//			return i - 48;
//		i += 1;
//	}
//	return 0;
//}
//
//float maHoaTime(char s[])
//{
//	float tongH = 0, tongM = 0; int i;
//	for (i = 0; s[i] != ':'; i++)
//		tongH = tongH * 10 + maHoa(s[i]);
//	for (i += 1; i < strlen(s); i++)
//		tongM = tongM * 10 + maHoa(s[i]);
//	return tongH + tongM / 100 * 1.0;
//}
//
//void xuLy(hoatdong a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int x = strlen(a[i].ngayS) - 1;
//		a[i].timeS_mahoa = maHoa(a[i].ngayS[x]) * 100 + maHoaTime(a[i].timeS);
//		x = strlen(a[i].ngayE) - 1;
//		a[i].timeE_mahoa = maHoa(a[i].ngayE[x]) * 100 + maHoaTime(a[i].timeE);
//	}
//}
//
//int kt(float s, float f, float s0, float f0)
//{
//	if (f <= s0)
//		return 0;
//	if (s >= f0)
//		return 0;
//	return 1;
//}
//
//void xoaHoatDong(hoatdong a[], int n, hoatdong b[], int& m)
//{
//	m = 0;
//	for (int y = 0; y < n;)
//	{
//		b[m] = a[y];
//		for (int i = 0; i < n; )
//		{
//			if (kt(a[i].timeS_mahoa, a[i].timeE_mahoa, b[m].timeS_mahoa, b[m].timeE_mahoa) == 1)
//			{
//				for (int x = i; x < n - 1; x++)
//					a[x] = a[x + 1];
//				n--;
//			}
//			else i++;
//		}
//		m++;
//	}
//}