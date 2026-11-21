//mssv: 2001206904
//ho ten: Dang Ngoc Thao
//noi dung: ki thuat tham lam - buoi 3
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
using namespace std;

#define Max 100

typedef struct products
{
	char name[50];
	int weight;
	double cost;
	int quantity;
	int totalSelect;
	float unitPrice;
}product;

void menu();
void thucThi();
void xuat(product prd[], int n);
void readFileProduct(product prd[], int& n, int& W);
void writeFile(product prd[], int n, int totalWeight, int totalBenefit);
int chiaThuong(int m, int n);
void swap(product& a, product& b);
void sortUnitPrice(product prd[], int n);
void knapsack1(product prd[], int n, int W);
void knapsack2(product prd[], int n, int W);
void knapsack3(product prd[], int n, int W);

void main()
{
	thucThi();
}

void thucThi()
{
	product prd[Max];
	int cn, n, W;
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
			readFileProduct(prd, n, W);
			xuat(prd, n);
		}break;
		case 2:
		{
			sortUnitPrice(prd, n);
			xuat(prd, n);
		}break;
		case 3:
		{
			knapsack1(prd, n, W);
		}break;
		case 4:
		{
			knapsack2(prd, n, W);
		}break;
		case 5:
		{
			knapsack3(prd, n, W);
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
	printf("\n1.nhap File");
	printf("\n2.xep theo unitPrice");
	printf("\n3.giai bai toan balo1");
	printf("\n4.giai bai toan balo2");
	printf("\n5.giai bai toan balo3");
}

void xuat(product prd[], int n)
{
	printf("%-15s%-15s%-15s%-15s%-15s\n", "Name", "Weight", "Cost", "Quatity", "unitPrice");
	for (int i = 0; i < n; i++)
	{
		printf("%-15s%-15d%-15.2lf%-15d%-15.2f\n", prd[i].name, prd[i].weight, prd[i].cost, prd[i].quantity, prd[i].unitPrice);
	}
}

int chiaThuong(int m, int n)
{
	if (m == 0 || n == 1)
		return 1;
	if (n == 0)
		return 0;
	if (m < n)
		return chiaThuong(m, m);
	return chiaThuong(m, n - 1) + chiaThuong(m - n, n);
}

void swap(product& a, product& b)
{
	product t = a;
	a = b;
	b = t;
}

void sortUnitPrice(product prd[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (prd[i].unitPrice < prd[j].unitPrice)
				swap(prd[i], prd[j]);
		}
	}
}

void readFileProduct(product prd[], int& n, int& W)
{
	ifstream in;
	in.open("Products.txt");
	if (in)
	{
		in >> W;
		in >> n;
		for (int i = 0; i < n; i++)
		{
			in >> prd[i].name;
			in >> prd[i].weight;
			in >> prd[i].cost;
			in >> prd[i].quantity;
			prd[i].unitPrice = (float)prd[i].cost / prd[i].weight;
		}
	}
	in.close();
}

void writeFile(product prd[], int n, int totalWeight, int totalBenefit)
{
	ofstream out;
	out.open("outProducts.txt");
	if (out)
	{
		out << "Tong khoi luong ba lo co chua duoc: " << totalWeight << "\n";
		out << "Tong gia tri dat duoc: " << totalBenefit << "\n";
		out << "Vat\tSo luong chon\n";
		for (int i = 0; i < n; i++)
		{
			int t = prd[i].totalSelect;
			if (t > 0)
			{
				out << prd[i].name << "\t";
				out << t << "\n";
			}
		}
	}
	out.close();
}

void knapsack1(product prd[], int n, int W)
{
	sortUnitPrice(prd, n);
	float totalWeight = 0, totalBenefit = 0;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		while (prd[i].weight + totalWeight <= W)
		{
			totalWeight += (float)prd[i].weight;
			totalBenefit += prd[i].cost;
			t++;
		}
		prd[i].totalSelect = t;
	}
	writeFile(prd, n, totalWeight, totalBenefit);
}

void knapsack2(product prd[], int n, int W)
{
	sortUnitPrice(prd, n);
	float totalWeight = 0, totalBenefit = 0;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		while (prd[i].weight + totalWeight <= W && t < prd[i].quantity)
		{
			totalWeight += (float)prd[i].weight;
			totalBenefit += prd[i].cost;
			t++;
		}
		prd[i].totalSelect = t;
	}
	writeFile(prd, n, totalWeight, totalBenefit);
}

void knapsack3(product prd[], int n, int W)
{
	sortUnitPrice(prd, n);
	float totalWeight = 0, totalBenefit = 0;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		if (prd[i].weight + totalWeight <= W && t < prd[i].quantity)
		{
			totalWeight += (float)prd[i].weight;
			totalBenefit += prd[i].cost;
			t++;
		}
		prd[i].totalSelect = t;
	}
	writeFile(prd, n, totalWeight, totalBenefit);
}