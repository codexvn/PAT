#include <iostream>
#include <vector>

using namespace std;

int main() {
    string arr_str;
    char arr_char[11] = {0};
    vector<char> arr, index;
    cin >> arr_str;
    for (int i = 0; i < arr_str.length(); ++i)arr_char[arr_str[i] - '0'] = 1;
    for (int j = 10; j >= 0; --j) if (arr_char[j])arr.push_back(j + '0');//获取所有的单位元素
    for (int j = 0; j <= 11; ++j) {
        for (int k = 0; k < arr.size(); ++k)
            if (arr_str[j] == arr[k]) {
                index.push_back(k + '0');
                break;
            }

    }
    cout << "int[] arr = new int[]{";
    for (int l = 0; l < arr.size() - 1; ++l)cout << arr[l] << ',';
    cout << *(--arr.end());
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    for (int l = 0; l < index.size() - 1; ++l)cout << index[l] << ',';
    cout << *(--index.end());
    cout << "};" << endl;
}