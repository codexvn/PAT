#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int N;
	double flag, data[20][2];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> data[i][0] >> data[i][1];
		data[i][1] /= 2;
	}
	for (int i = 0; i < N - 1; i++)
	{
		flag = (data[i][0] - 100) * 0.9;
		if (abs(data[i][1] - flag) < flag * 0.1)
			cout << "You are wan mei!" << endl;
		else if (data[i][1] > flag)
			cout << "You are tai pang le!" << endl;
		else 
			cout << "You are tai shou le!" << endl;
	}
	flag = (data[N-1][0] - 100) * 0.9;
	if (abs(data[N-1][1] - flag) < flag * 0.1)
		cout << "You are wan mei!";
	else if (data[N-1][1] > flag)
		cout << "You are tai pang le!";
	else 
		cout << "You are tai shou le!";
}