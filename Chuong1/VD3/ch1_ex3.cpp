#include <iostream>
#include <conio.h>
#define maxn 1000001
void docfile(int a[], int& n);
void ghifile(int  a[], int n);
long long tichmax(int a[], int n);
int a[maxn];
int n;
void main()
{
    docfile(a, n);
    ghifile(a, n);
    getch();
}
void docfile(int a[], int& n)
{
    FILE* f;
    f = fopen("VD3.INP", "rt");
    fscanf(f, "%d", &n);
    for (int i = 1; i <= n; i++)
        fscanf(f, "%d", &a[i]);
    fclose(f);
}
void ghifile(int a[], int n)
{
    FILE* f;
    f = fopen("VD3.OUT", "wt");
    fprintf(f, "%d", tichmax(a, n));
    fclose(f);
}
void exch(int& x, int& y)
{
    int t = x; x = y; y = t;
}
void quicksort(int a[], int l, int r)
{
    int x = a[(l + r) / 2];
    int i = l;
    int j = r;
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j)
            exch(a[i++], a[j--]);
    } while (i < j);
    if (l < j) quicksort(a, l, j);
    if (i < r) quicksort(a, i, r);
}
long long tichmax(int a[maxn], int n)
{
    quicksort(a, 1, n);
    long long max;
    long long bo1 = a[1] * a[2] * a[n];
    long long bo2 = a[n - 2] * a[n - 1] * a[n];
    max = bo1 > bo2 ? bo1 : bo2;
    return max;
}
/*
VD3.INP
9
5 7 8 9 -9 6 -8 -3 5
*/