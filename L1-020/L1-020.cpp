#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;
int main()
{
	int DATA[100001]{ 0 }, N, K, M, tmp, * question;
	DATA[100000] = 1;
	cout << setfill('0');
	bool nohandsome = true;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		if (K == 1)
		{
			cin.ignore(INT_MAX, '\n');
			continue;
		}

		for (int j = 0; j < K; j++)
		{
			cin >> tmp;
			DATA[tmp]++;
		}
	}
	cin >> M;
	question = new int[M];
	for (int l = 0; l < M; l++)
	{
		cin >> question[l];
		for (int m = 0; m < l; m++)
			if (question[l] == question[m])
				question[l] = 100000;

	}
	for (int l = 0; l < M; l++)
	{
		if (!DATA[question[l]])
		{
			if (!nohandsome)
				cout << ' ';
			cout << setw(5)<<question[l];
			nohandsome = false;
		}
	}
	if (nohandsome)
		cout << "No one is handsome";
	delete[] question;
}