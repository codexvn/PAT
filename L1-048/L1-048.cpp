#include <iostream>
#include <vector>
using namespace std;
int main()

{
	vector<vector<int>>A, B;
	int R_a, R_b, C_a, C_b, get;
	cin >> R_a >> C_a;
	for (int i = 0; i < R_a; ++i)
	{
		A.resize(i + 1);
		for (int j = 0; j < C_a; j++)
		{
			cin >> get;
			A[i].push_back(get);
		}
	}
	cin >> R_b >> C_b;
	for (int i = 0; i < R_b; ++i)
	{
		B.resize(i + 1);
		for (int j = 0; j < C_b; j++)
		{
			cin >> get;
			B[i].push_back(get);
		}
	}

	if (C_a != R_b)cout << "Error: "<<C_a<<" != "<<R_b<<endl;
	else
	{
		cout << R_a << ' ' << C_b << endl;
		for (int k = 0; k < R_a; k++) {//计算矩阵的和

			for (int i = 0; i < C_b; ++i)
			{
				int sum = 0;
				for (int j = 0; j < C_a; j++)
					sum += A[k][j] * B[j][i];
				cout << sum;
				if (i != C_b - 1) cout << ' ';
			}
			cout << endl;
		}
	}
}