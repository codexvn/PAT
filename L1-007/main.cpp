#include <iostream>

using namespace std;

int main() {
    char pinyin[11][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "fu"};
    string get;
    cin >> get;
    if (get[0] == '-')
        cout << pinyin[10];
    else cout << pinyin[get[0] - 48];
    int length = get.length();
    for (int j = 1; j < length; ++j) {
        cout << ' ' << pinyin[get[j] - 48];
    }
    return 0;
}