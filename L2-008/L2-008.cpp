#include <iostream>
#include <string>
using namespace std;
int main()
{
	string GET;
	getline(cin, GET);
	int maxlen = 1;
	for (int i = 0; i < GET.length() - maxlen; i++)
	{
		int Flag, End;//Flag:��ͬ�ַ���λ�ã���λ���ĵ�β��   End:�ҵ����ַ���λ��
		for (Flag = GET.length() - 1; (End = GET.rfind(GET[i], Flag)) != string::npos and End != i; Flag--)
		{
			bool ishuiwen = true;
			Flag = End;
			for (int j = 0; Flag - 2 * j > i; j++)
				if (GET[i + j] != GET[Flag - j])
				{
					ishuiwen = false;
					break;
				}
			if (ishuiwen)
				if (maxlen < Flag - i + 1)
					maxlen = Flag - i + 1;
		}
	}
	cout << maxlen;
}