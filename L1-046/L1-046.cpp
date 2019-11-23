#include <iostream>
#include<iomanip>
#include<cmath>
using namespace  std;
int main()
{
	int len, x_int, LLL = 0;
	string x, result;
	char shang[2] = {0};
	cin >> x;
	len = x.length();
	x_int = atoi(x.c_str());
	for (int i = 0; i < len; i++)
		++(LLL *= 10);
	if (LLL < x_int)
	{
		len++;
		++(LLL *= 10);
	}
	while (true)
	{
		shang[0] = (LLL / x_int) + '0';
		result.append(shang);
		if (!(LLL % x_int))
			break;
		else
		{
			LLL = (LLL % x_int) * 10 + 1;
			len++;
		}
	}
	cout << result << ' ' << len;
}