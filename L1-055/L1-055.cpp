#include<cstdio>
using namespace std;
int main()
{
	int Pa, Pb, count = 0, tmp;
	scanf("%d%d", &Pa, &Pb);
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &tmp);
		count += tmp;
	}
	if (Pa > Pb)
	{
		if (count == 3)
			printf("The winner is b: %d + %d", Pb, count);
		else 			printf("The winner is a: %d + %d", Pa, 3 - count);
	}
	else if (Pa == Pb) {
		if (count >= 2)
			printf("The winner is b: %d + %d", Pb, count);
		else 			printf("The winner is a: %d + %d", Pa, 3 - count);
	}
	else {
		if (count != 0)
			printf("The winner is b: %d + %d", Pb, count);
		else 			printf("The winner is a: %d + %d", Pa, 3 - count);
	}

}