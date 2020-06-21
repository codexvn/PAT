#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int N;
	char flag;
	cin >> N >> flag;
	int row = sqrt((N + 1) / 2);
	int space = 0;
	for (int i = row; i >= 1; i--, space++)
	{
		for (int k = space; k >= 1; k--)
			cout << " ";
		for (int j = i * 2 - 1; j >= 1; j--)
			cout << flag;
		cout << endl;
	}
	space -= 2;
	for (int i = 2; i <= row; i++, space--)
	{
		for (int k = space; k >= 1; k--)
			cout << " ";

		for (int j = i * 2 - 1; j >= 1; j--)
			cout << flag;
		cout << endl;
	}
	cout << N - 2 * row * row + 1;
	return 0;
}