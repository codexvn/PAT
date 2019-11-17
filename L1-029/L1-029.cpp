#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << fixed << setprecision(1);
	int H;
	cin >> H;
	cout << (H - 100) * 0.9 * 2;
}