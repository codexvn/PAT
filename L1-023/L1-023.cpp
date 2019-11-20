#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	stack<char>G, P, L, T;
	string DATA;
	getline(cin, DATA);
	for (int i = 0; i < DATA.length(); i++)
	{
		switch (DATA[i])
		{
		case 'g':
		case 'G':G.push('G'); break;
		case 'p':
		case 'P':P.push('P'); break;
		case 't':
		case 'T':T.push('T'); break;
		case 'l':
		case 'L':L.push('L'); break;
		}
	}
	while (!G.empty() or !P.empty() or !T.empty() or !L.empty())
	{
		if (!G.empty())
		{
			cout << G.top();
			G.pop();
		}
		if (!P.empty())
		{
			cout << P.top();
			P.pop();
		}
		if (!L.empty())
		{
			cout << L.top();
			L.pop();
		}
		if (!T.empty())
		{
			cout << T.top();
			T.pop();
		}
	}
}