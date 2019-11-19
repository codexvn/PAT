#include <iostream>
#include "iomanip"
using namespace std;
int main() {
	int yyyy, mm, dd;
	((cin >> mm).ignore() >> dd).ignore() >> yyyy;

	cout << setfill('0') << setw(4) << yyyy << '-' << setw(2) << mm << '-' << setw(2) << dd;

	return 0;
}