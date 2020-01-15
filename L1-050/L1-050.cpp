#include <cstdio>
using namespace std;
int main()
{
	char num[6] = { 'z','z','z','z','z','z' };
	int L, N, a;
	scanf("%d%d", &L, &N);
	N--;
	int L_copy = L - 1;
	while (N != 0)
	{
		a = N % 26;
		N /= 26;
		num[L_copy] -= a;
		L_copy--;
	}
	for (int i = 0; i < L; i++)
	{
		printf("%c", num[i]);
	}


}
