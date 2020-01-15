#include <cstdio>
using namespace std;
int main()
{
	int N;
	char get[7];
	scanf("%d%*c", &N);
	while (N--)
	{
		scanf("%s", get);
		if (get[0] + get[1] + get[2] == get[3] + get[4] + get[5])
			printf("You are lucky!\n");
		else printf("Wish you good luck.\n");
	}
}