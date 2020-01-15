#include <iostream>
using  namespace std;
int main()
{
	int N;
	cin >> N;
	char name[4];
	int a, b; //a:呼吸;b:脉搏
	while (N--)
	{
		cin >> name >> a >> b;
		if (a < 15 or a>20 or b < 50 or a>70)
			cout << name << endl;
	}
}