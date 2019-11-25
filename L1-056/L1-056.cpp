#include <iostream>
#include <cmath>
using namespace std;
struct onedata
{
	char name[9];
	int num;
};
int main()
{
	int N;
	double avg = 0,min,tmp; 
	cin >> N;
	onedata* DATA = new onedata[N],*win=DATA; //win:Ó®¼Ò
	for (int i = 0; i < N; i++)
	{
		cin >> DATA[i].name >> DATA[i].num;
		avg+= DATA[i].num;
	}
	avg /= 2 * N;
	min = abs(avg - DATA[0].num);
	for (int i = 1; i < N; i++)
	{
		tmp = abs(avg - DATA[i].num);
		if (min>tmp)
		{
			win = &DATA[i];
			min = tmp;
		}
	}
	cout << int(avg) << ' ' << win->name;
}