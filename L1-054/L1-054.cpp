#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	char matrix[101][101] = { 0 }, replace;
	int N;
	scanf("%c%d%*c", &replace, &N);
	for (int i = 0; i < N; i++)
		cin.getline(matrix[i], 101);
	int j;
	for (j = 0; j < N / 2; j++)
	{
		for (int k = 0; k < N; k++)
			if (matrix[j][k] != matrix[N - 1 - j][N - 1 - k])
				goto break_loop;
	}
break_loop:
	if (j == N / 2)
		printf("bu yong dao le\n");
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (matrix[i][j] == '@')
				printf("%c", replace);
			else printf("%c", matrix[i][j]);

		}
		printf("\n");
	}
}