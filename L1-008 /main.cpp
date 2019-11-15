#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int A, B, Sum = 0;
    cin >> A >> B;
    for (int i = A, j = 0; i <= B; ++i, ++j %= 5) {
        Sum += i;
        cout << setw(5) << setiosflags(ios::right) << i;
        if (j == 4)cout << endl;
    }
    if ((B - A + 1) % 5 != 0) cout << endl;
    cout << "Sum = " << Sum;
    return 0;
}