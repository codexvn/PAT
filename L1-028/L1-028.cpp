#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	unsigned int N, data[10];
	bool is_primenum[10];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> data[i];
	for (int i = 0; i < N; i++)
	{
		is_primenum[i] = true;
		int flag = sqrt(data[i]);
		if (data[i] == 1)
			is_primenum[i] = false;
		for (int j = 2; j < flag; j++)
		{
			if (data[i] % j == 0)
				is_primenum[i] = false;
		}
	}
	for (int i = 0; i < N - 1; i++)
		if (is_primenum[i])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	if (is_primenum[N - 1])
		cout << "Yes";
	else
		cout << "No";
}