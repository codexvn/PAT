#include <iostream>
using namespace std;
typedef struct student
{
	short gender;
	string name;
}*info;
int main()
{
	int N;
	cin >> N;
	info studentinfo = new student[N];
	for (int i = 0; i < N; i++)
		cin >> studentinfo[i].gender >> studentinfo[i].name;
	info head = studentinfo, badgirl = &studentinfo[N - 1], badboy = badgirl;
	for (int i = 0; i < N / 2; i++)
	{
		if (head->gender)
		{
			while (badgirl->gender)
				badgirl--;
			cout << head->name << ' ' << badgirl->name << endl;
			badgirl--;
			head++;
		}
		else
		{
			while (!badboy->gender)
				badboy--;
			cout << head->name << ' ' << badboy->name << endl;
			badboy--;
			head++;
		}
	}

}