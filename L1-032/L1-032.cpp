#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N;
	char T;//Ìî³äÓÃµÄ×Ö·û
	string Data;
	cin >> N >> T >> ws;
	getline(cin, Data);
	if (Data.length() >= N)
		cout << Data.substr(Data.length() - N);
	else
	{
		int fill = N - Data.length();
		for (int i = 0; i < fill; i++)
			cout << T;
		cout << Data;
	}

		
}