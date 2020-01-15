#include<iostream>
using namespace std;
int main()
{
	int K,N=0;
	string trick;
	cin >> K;
	K++;
	while (++N)
	{
		cin >> trick;
		if (trick[0] == 'E')return 0;
		if (N % K == 0)
			cout << trick << endl;
		else switch (trick[0])
		{
		case 'C':cout << "Bu" << endl; break;
		case 'J':cout << "ChuiZi" << endl; break;
		case 'B':cout << "JianDao" << endl; break;
		}
	}
	return 0;
}