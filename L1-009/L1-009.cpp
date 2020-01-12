#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
struct {
    int integer = 0;
    long long Fen_Zi = 0, Fen_Mu = 0;
} data, result;

long long Gcd(long long a, long long b)
//辗转相除法
{
    if (a < 0)a = abs(a);
    if (b < 0)a = abs(b);
    if (a < b)swap(a, b);
    return b == 0 ? a : Gcd(b, a % b);
}

void Contractresule(void) {
    long long value = Gcd(result.Fen_Zi, result.Fen_Mu);
    result.Fen_Zi /= value;
    result.Fen_Mu /= value;
}

void Contractdata(void) {
    long long value = Gcd(data.Fen_Zi, data.Fen_Mu);
    data.Fen_Zi /= value;
    data.Fen_Mu /= value;
}

int main() {
    int N;
    cin >> N;
    scanf("%ld/%ld", &result.Fen_Zi, &result.Fen_Mu);
    Contractresule();
    for (int i = 1; i < N; ++i) {
        scanf("%ld/%ld", &data.Fen_Zi, &data.Fen_Mu);
        Contractdata();
        result.Fen_Zi = result.Fen_Zi * data.Fen_Mu + result.Fen_Mu * data.Fen_Zi;
        result.Fen_Mu *= data.Fen_Mu;
        result.integer += result.Fen_Zi / result.Fen_Mu;   //及时将整数部分提出来
        result.Fen_Zi %= result.Fen_Mu;
        Contractresule();

    }
    if (result.Fen_Zi == 0)cout << result.integer;
    else {
        if (result.integer != 0)
            cout << result.integer << ' ';
        cout << result.Fen_Zi << '/' << result.Fen_Mu;
    }
    return 0;
};
