#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int N; //前来查询的用户数
	char sex;//性别
	float tall;//身高
	cin >> N;
	while (N--)
	{
		cin >> sex >> tall;
		switch (sex)
		{
			//女性
		case 'M':printf("%.2f\n", tall / 01.09); break;
			//男性
		case 'F':printf("%.2f\n", tall * 01.09);
		}
	}
}