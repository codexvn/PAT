#include <cstdio>
using namespace std;
int main()
{
	float wight, tall,result;
	scanf("%f%f", &wight, &tall);
	result = (wight / tall/ tall);
	if (result > 25)
		printf("%.1f\nPANG", result);
	else printf("%.1f\nHai Xing", result);
}