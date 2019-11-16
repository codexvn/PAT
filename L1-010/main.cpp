#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A < B)
        if (B < C)
            cout << A << "->" << B << "->" << C;
        else
            if (A < C)
                cout << A << "->" << C << "->" << B;
            else
                cout << C << "->" << A << "->" << B;
    else
        if(A<C)
            cout << B << "->" << A << "->" <<C ;
        else
            if(B<C)
                cout << B << "->" << C << "->" << A;
            else
                cout << C << "->" << B << "->" << A;
    return 0;
}