#include <iostream>
using namespace std;
int main()
{
	int A = 0, B = 0, N, tmp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp % 2)
			A++;
		else
			B++;
	}
	cout << A << ' ' << B;
}