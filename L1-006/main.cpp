#include <iostream>
#include <cmath>

using namespace std;
struct {
    unsigned int factor;
    int num;
} maxone;

int main() {
    unsigned long N, sub ;
    cin >> N;
    maxone.num = 0;
    for (unsigned long i = 2; i <= sqrt(N); ++i) {
        sub = 1;
        for (int j = i; sub*j <= N; ++j) {
            sub *= j;
            if (N % sub == 0 && j - i + 1 > maxone.num) {
                maxone.factor = i;
                maxone.num = j - i + 1;
            }
        }
    }

    if (maxone.factor == 0) {
        maxone.num = 1;
        maxone.factor = N;
    }
    cout << maxone.num << endl;
    for (int k = 0; k < maxone.num - 1; ++k) {
        cout << k + maxone.factor << '*';
    }
    cout << maxone.num + maxone.factor - 1;
    return 0;
}