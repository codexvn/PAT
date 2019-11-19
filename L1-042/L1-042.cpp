#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	tm time;
	cin >> get_time(&time, "%m-%d-%Y");
	cout << put_time(&time, "%Y-%m-%d");
	return 0;
}