#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << fixed << setprecision(2);
	string N;
	cin >> N;
	int num = 0, len;
	for (auto i : N)
		if (i == '2')
			num++;
	double result;
	if (N[0] == '-')
		result = double(num) / (N.length() - 1) * 1.5;
	else
		result = double(num) / N.length();
	if ((N.back() - 48) % 2 == 0)
		result *= 2;
	cout << result * 100 << '%';
}