#include <stdio.h>
int main()
{
	int N = 0, get;
	while (++N)
	{
		scanf("%d", &get);
		if (get == 250)
			break;
	}
	printf("%d\n", N);
}