#include <iostream>
#include <conio.h>
#define maxn 1000010
using namespace std;
int tonguoc[maxn];
int main() 
{

	int M = 10000;
	for (int i = 1; i < M; i++)
		for (int j = i + i; j < M; j += i)
		//{
			tonguoc[j] += i;
		//	cout << tonguoc[j] << endl;
		//}
	int dem = 0;
	for (int i = 1; i < M; i++)
		if (tonguoc[i] && tonguoc[i] < M && tonguoc[tonguoc[i]] == i && tonguoc[i] != i) 
		{
			cout << i << " " << tonguoc[i] << endl;
			dem++;
			tonguoc[i] = 0;
		}
	cout << endl << dem << endl;
}
/*
10000	5
25000	8
50000	8
75000	10
100000	13
250000	22
500000	28
750000	35
900000	38
1000000	40
*/
