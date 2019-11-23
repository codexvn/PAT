#include <iostream>
using namespace std;
struct OneSchool
{
	int* sitnum;
	int freestudentnum;
	int nextstudent=0;
	bool beflag=false; //无空闲学生学校标记
};
int main()
{
	int N;
	cin >> N;
	auto M = new OneSchool[N];
	for (int i = 0; i < N; i++) //创建学生数组
	{
		cin >> M[i].freestudentnum;
		M[i].freestudentnum *= 10;
		//allstudent += M[i].freestudentnum;
		M[i].sitnum = new int[M[i].freestudentnum];
	}
	int i = 1, flag = -1;
	for (int j = N; j>1; i++)  //设置座位号
	{
		for ((++flag) %= N;! M[flag].freestudentnum; (++flag) %= N) //找到还有未分配座位号的学生的学校
			if (!M[flag].beflag)
			{
				j--;
				M[flag].beflag = true;
				if (j == 1)break;
			}
		if (j != 1)
		{
			M[flag].sitnum[M[flag].nextstudent] = i;
			M[flag].nextstudent++;
			M[flag].freestudentnum--;
			if (!M[flag].freestudentnum)
			{
				j--;
				M[flag].beflag = true;
			}
		}

	}
	for ((++flag) %= N; !M[flag].freestudentnum; (++flag) %= N);//找到最后一个还有未分配座位号的学生的学校
	if (M[flag].freestudentnum == 1)
	{
		M[flag].sitnum[M[flag].nextstudent] = i;
		M[flag].nextstudent++;
		M[flag].freestudentnum--;
	}
	else
		for (; M[flag].freestudentnum;i += 2)
		{

			M[flag].sitnum[M[flag].nextstudent] = i;
			M[flag].nextstudent++;
			M[flag].freestudentnum--;
		}
	for (int n = 0; n < N; n++)
	{
		cout << '#' << n + 1<<endl;
		for (int p = 0; p < M[n].nextstudent; p++)
		{
			cout << M[n].sitnum[p];
			if ((p+1) % 10 == 0)
				cout << endl;
			else
				cout << ' ';
		}
	}
	
}