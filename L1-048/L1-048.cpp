#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int R_a, R_b, C_a, C_b;
	cin >> R_a >> C_a;
	int A[100][100];  //所有整数不超过100，也就是说元素个数不超过100*100
	for (int i = 0; i < R_a; i++)
	{
		for (int j = 0; j < C_a; j++)
			cin >> A[i][j];
	}
	cin >> R_b >> C_b;
	int B[100][100];
	for (int i = 0; i < R_b; i++)
	{
		for (int j = 0; j < C_b; j++)
			cin >> B[i][j];
	}

	if (C_a != R_b)cout << "Error: " << C_a << " != " << R_b << endl;
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