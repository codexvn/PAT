#include <iostream>
#include <set>
#include <iterator>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed << setprecision(3);
    multiset<double> k_result, k_data;
    multiset<double>::iterator begin, end;
    double tmp, count;
    int N, k, M;
    cin >> N >> k >> M;
    for (int i = 0; i < N; ++i, k_data.clear()) {
        count = 0;
        for (int j = 0; j < k; ++j) {  //接收数据
            cin >> tmp;
            k_data.insert(tmp);
        }
        begin = k_data.begin();
        begin++;
        end = k_data.end();
        end--;
        for (multiset<double>::iterator l = begin; l != end; l++)
            count += *l;
        k_result.insert(count / (k - 2));
    }
    begin = k_result.begin();
    end = k_result.end();
    advance(begin, N - M);
    end--;
    for (; begin != end; begin++)
        cout << *begin << " ";
    cout << *end;
}