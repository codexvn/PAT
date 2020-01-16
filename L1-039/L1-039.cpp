#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N >> ws;
	vector<char>* str;
	str = new vector<char>[N];
	char get = 0;
	while (true)
	{
		for (int i = 0; i < N; i++)
		{
			cin.get(get);
			if (get == '\n')
				goto out_loop;
			str[i].push_back(get);
		}
	}
out_loop:
	for (int i = 0; i < N; i++)
	{
		if (str[i].size() < str[0].size())cout << ' ';
		for (int j = str[i].size() - 1; j >= 0; j--) cout << str[i][j];
		cout << endl;
	}
}