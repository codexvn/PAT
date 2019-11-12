#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, i;
    char sign;
    cin >> N >> sign;
    i = sqrt((N + 1) / 2.0);
    for (int j = 1; j <= i; ++j) {

        for (int k = 0; k < j - 1; ++k) cout << ' ';
        for (int l = 0; l < 2 * (i - j) + 1; ++l) cout << sign;
        cout << endl;
    }
    for (int j = 2; j <= i; ++j) {
        for (int k = 0; k < i - j; ++k) cout << ' ';
        for (int l = 0; l < 2 * j - 1; ++l) cout << sign;
        cout << endl;
    }
    cout << N - pow(i, 2) * 2 + 1;
    return 0;
}