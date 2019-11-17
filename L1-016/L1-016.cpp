#include <iostream>
struct
{
	char ID[19];
	bool flag = false;
}ID[100];
using namespace std;
int main()
{
	int N, count = 0;
	char last, M[] = { '1','0','X','9','8','7','6','5','4','3','2' };
	int base[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	(cin >> N).get();
	cin.widen(1);
	long sum = 0;
	for (int i = 0; i < N; i++, sum = 0)
	{
		cin >> ID[i].ID;
		for (int j = 0; j < 17; j++)
		{
			if (ID[i].ID[j] == 'X')
			{
				ID[i].flag = true;
				break;
			}
			else
				sum += (ID[i].ID[j] - 48) * base[j];
		}
		if (M[sum % 11] != ID[i].ID[17])
			ID[i].flag = true;

	}
	bool allfalse = true;
	for (int i = 0; i < N; i++)
	{
		if (ID[i].flag)
		{
			cout << ID[i].ID << endl;
			allfalse = false;
		}
	}
	if (allfalse)
		cout << "All passed";
	return 0;
}