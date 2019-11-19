#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	cout << fixed << setprecision(2);
	cout << A * B / 10.0;
	return 0;
}