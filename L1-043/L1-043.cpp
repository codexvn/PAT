#include<iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
struct onebook
{
	int begin_time = -1;
	bool in_used = false;
};
int main()
{
	int N, bookid, time, S, F;
	char operate;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		onebook* book = new onebook[1001];
		int count = 0, allusetime = 0;//½èÊéÊý
		do
		{
			scanf("%d %c %d:%d", &bookid, &operate, &S, &F);
			if (!bookid)
				break;
			if (operate == 'S')
			{
					book[bookid].begin_time = S * 60 + F;
					book[bookid].in_used = true;
			}
			else
				if (book[bookid].in_used)
				{
					book[bookid].in_used = false;
					allusetime += S * 60 + F - book[bookid].begin_time;
					book[bookid].begin_time = -1;
					count++;
				}
		} while (true);
		if (allusetime)
			cout << fixed << setprecision(0) << count << ' ' << allusetime / (double)count;
		else
			cout << 0 << ' ' << 0;
		if (i != N)
			cout << endl;
	}
}