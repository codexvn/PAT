#include <iostream>

using namespace std;

int main() {
    short m, n;
    char flag;
    cin >> n >> ws >> flag;
    if (n % 2 == 0)
        m = n / 2;
    else
        m = n / 2 + 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << flag;
        cout << endl;
    }
    return 0;
}