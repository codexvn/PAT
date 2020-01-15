#include <iostream>
using namespace std;
int main()
{
	int N, sex, tall, weight;
	cin >> N;
	while (N--)
	{
		cin >> sex >> tall >> weight;
		if (sex == 1)
		{
			if (tall > 130)cout << "ni li hai! ";
			else if (tall == 130) cout << "wan mei! ";
			else cout << "duo chi yu! ";

			if (weight > 27)cout << "shao chi rou!" << endl;
			else if (weight == 27) cout << "wan mei!" << endl;
			else cout << "duo chi rou!" << endl;
		}
		else
		{
			if (tall > 129)cout << "ni li hai! ";
			else if (tall == 129) cout << "wan mei! ";
			else cout << "duo chi yu! ";

			if (weight > 25)cout << "shao chi rou!" << endl;
			else if (weight == 25) cout << "wan mei!" << endl;
			else cout << "duo chi rou!" << endl;
		}

	}
}