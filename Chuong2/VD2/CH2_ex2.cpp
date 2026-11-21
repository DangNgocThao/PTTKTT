#include <iostream>
using namespace std;
void move(int n, char start, char finish, char spare);
int d = 0;
int main()
{
	int n;
	cout << "Input number of disk: "; cin >> n;
	move(n, 'A', 'C', 'B');
	cout << "\nTotal number of moves: " << d << endl;
}
void move(int n, char start, char finish, char spare)
{
	if (n == 1)
	{
		cout << "\nMove disk from " << start << " to " << finish;
		d++;
		return;
	}
	else {
		move(n - 1, start, spare, finish);
		move(1, start, finish, spare);
		move(n - 1, spare, finish, start);
	}
}