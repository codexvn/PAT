#include <iostream>

using namespace std;

int main() {
    string A, B, get;
    int count = 0;
    while (true) {
        cin >> get;
        if (get != ".")count++;
        else break;
        if (2 == count)
            A = get;
        else if (14 == count)
            B = get;
    }
    if (count < 2)
        cout << "Momo... No one is for you ..." << endl;
    else if (count < 14)
        cout << A << " is the only one for you..." << endl;
    else cout << A << " and " << B << " are inviting you to dinner..." << endl;
}