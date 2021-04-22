#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0, pre; i < K; ++i) {
        pre = 0;
        stack<int> myStack;
        int *input = new int[N];
        for (int j = 0; j < N; ++j)cin >> input[j];
        for (int j = 0; j < N; ++j) {
            if (pre + 1 == input[j]) {
                pre++;
                while (true) {
                    if (myStack.empty() == false && myStack.top() == pre + 1) {
                        myStack.pop();
                        pre++;
                    } else
                        break;
                }
            } else {
                myStack.emplace(input[j]);
                if (myStack.size() > M) {
                    break;
                }
            }
        }
        if (pre == N)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
