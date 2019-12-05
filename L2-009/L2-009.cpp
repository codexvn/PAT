#include<iostream>
#include<iomanip>
#include <algorithm>
#include<vector>
using namespace  std;
struct MyStruct
{
	int ID;
	int sent = 0;//发红包的个数
	int get = 0;//收红包的个数
	int sum = 0;//净收入
};
bool sortfunction(struct MyStruct& A, struct MyStruct& B)
{
	if (A.sum > B.sum or (A.sum == B.sum and A.get > B.get) or (A.sum == B.sum and A.get == B.get and A.ID < B.ID))
		return true;
	else return false;
}
int main()
{
	cout << fixed << setprecision(2);
	int N;
	cin >> N;
	vector<struct MyStruct>DATA(N);
	for (int i = 0; i < N; i++)
	{
		//计算净收入
		int K, Ni, Pi, spend = 0;
		cin >> K;
		DATA[i].sent = K;
		DATA[i].ID = i + 1;
		for (int j = 0; j < K; j++)
		{
			cin >> Ni >> Pi;
			DATA[Ni - 1].get++;
			DATA[Ni - 1].sum += Pi;
			spend += Pi;
		}
		DATA[i].sum -= spend;
	}
	sort(DATA.begin(), DATA.end(), sortfunction);
	for (int i = 0; i < N; i++)
		cout << DATA[i].ID << ' ' << DATA[i].sum / 100.0 << endl;
}