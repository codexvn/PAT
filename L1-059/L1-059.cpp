#include<iostream>
#include <string>
using namespace std;
struct
{
	string get;
	int flag;//逗号的位置
	int last;
}DATA;
int main()
{
	int N;
	cin >> N >> ws;
	for (int i = 0; i < N; i++)
	{
		getline(cin, DATA.get);
		DATA.flag = DATA.get.find(',');
		DATA.last = DATA.get.length() - 1;
		if (DATA.flag < 3)  // 上句未说至少3个字，所以容易导致越界
			cout << "Skipped" << endl;
		else
			if (DATA.get.substr(DATA.last - 3, 3) == "ong" && DATA.get.substr(DATA.flag - 3, 3) == "ong")
			{
				for (int j = 0; j != 3;)
				{
					if (DATA.get[DATA.last] == ' ')
						j++;
					DATA.get.pop_back();
					DATA.last--;
				}
				cout << DATA.get << " qiao ben zhong." << endl;
			}
			else
				cout << "Skipped" << endl;
	}
}