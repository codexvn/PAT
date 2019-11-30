#include <iostream>
#include <iomanip>
#include <set>
using namespace std;
struct MyStruct
{
	int* set;
	int length;
};
int main()
{
	int N, set_A, set_B;
	cin >> N;
	cout << fixed << setprecision(2);
	set<int>* DATA = new set<int>[N];
	for (int i = 0; i < N; i++)
	{
		int M, get;
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> get;
			DATA[i].insert(get);
		}
	}
	cin >> N;
	for (int m = 0; m < N; m++)
	{
		double Nc = 0, Nt = 0;
		cin >> set_A >> set_B;
		set_A--;
		set_B--;
		for (auto same : DATA[set_A])
			if (DATA[set_B].find(same) != DATA[set_B].end())
				Nc++;
		Nt = DATA[set_A].size() + DATA[set_B].size() - Nc;
		cout << Nc / Nt * 100 << "%" << endl;
	}

}