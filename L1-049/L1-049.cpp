#include <iostream>
using namespace std;
struct OneSchool
{
	int* sitnum;
	int freestudentnum;
	int nextstudent=0;
	bool beflag=false; //�޿���ѧ��ѧУ���
};
int main()
{
	int N;
	cin >> N;
	auto M = new OneSchool[N];
	for (int i = 0; i < N; i++) //����ѧ������
	{
		cin >> M[i].freestudentnum;
		M[i].freestudentnum *= 10;
		//allstudent += M[i].freestudentnum;
		M[i].sitnum = new int[M[i].freestudentnum];
	}
	int i = 1, flag = -1;
	for (int j = N; j>1; i++)  //������λ��
	{
		for ((++flag) %= N;! M[flag].freestudentnum; (++flag) %= N) //�ҵ�����δ������λ�ŵ�ѧ����ѧУ
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
	for ((++flag) %= N; !M[flag].freestudentnum; (++flag) %= N);//�ҵ����һ������δ������λ�ŵ�ѧ����ѧУ
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