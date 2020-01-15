#include<cstdio>
using namespace std;
int main()
{
	char get;
	int count = 0;
	while (true)
	{
		scanf("%c", &get);
		if (get == '6')
			count++;
		else if (count == 0)
			printf("%c", get);
		else if (count > 3)
		{
			if (count > 9)
				printf("27");
			else
				printf("9");
			count = 0;
			printf("%c", get);
		}
		else
		{
			for (; count != 0; count--)
				printf("6");
			printf("%c", get);
		}
		if (get == '\n')break;
	}
}