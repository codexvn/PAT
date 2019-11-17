#include<iostream>
using namespace std;
int main()
{
	int N, A, B, A_have = 0, B_have = 0;
	cin >> A >> B >> N;
	int data[4], sum;
	for (int i = 0; i < N; i++)
	{
		cin >> data[0] >> data[1] >> data[2] >> data[3];
		sum = data[0] + data[2];
		if (data[1] == sum && data[3] != sum)
		{
			A_have++;
			if ((A - A_have) == -1)
			{
				cout << 'A' << endl << B_have;
				break;
			}
		}
		else if (data[3] == sum && data[1] != sum)
		{
			B_have++;
			if ((B - B_have) == -1)
			{
				cout << 'B' << endl << A_have;
				break;
			}
		}
	}

}