#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	string get;
	int A_INT = -1, B_INT = -1;
	getline(cin, get);
	bool A_is_integer = true, B_is_integer = true;
	int length = get.length(), i = 0;
	for (i = 0; i < length; i++)
	{
		if (get[i] == ' ')
		{
			i++;
			break;
		}
		if (get[i] < '0' or get[i]>'9')
		{
			A_is_integer = false;
			continue;
		}

	}
	if (A_is_integer)
		sscanf(get.c_str(), "%d", &A_INT);

	for (int j = i; j < length; j++)
	{
		if (get[i] == ' ')
		{
			B_is_integer = false;
			break;
		}
		if (get[j] < '0' or get[j]>'9')
		{
			B_is_integer = false;
			continue;
		}
	}

	if (B_is_integer)
		sscanf(&get[i], "%d", &B_INT);

	if (A_is_integer and A_INT >= 1 and A_INT <= 1000)
		cout << A_INT;
	else
		cout << "?";


	cout << " + ";

	if (B_is_integer and B_INT >= 1 and B_INT <= 1000)
		cout << B_INT;
	else
		cout << "?";

	cout << " = ";

	if (A_is_integer and A_INT >= 1 and A_INT <= 1000 and B_is_integer and B_INT >= 1 and B_INT <= 1000)
		cout << A_INT + B_INT;
	else
		cout << "?";


}