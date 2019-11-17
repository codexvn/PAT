#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int hh, mm;
	(cin >> hh).ignore() >> mm;
	if (hh >= 0 && hh <= 12)
		cout << setfill('0') << "Only " << setw(2) << hh << ':' << setw(2) << mm << ".  Too early to Dang.";
	hh = (hh - 12) + (mm % 2);
	for (int i = 0; i < hh; i++)
		cout << "Dang";
}