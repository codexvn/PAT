#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int N, M, from, to;
    cin >> N >> M;
    vector<int> *data = new vector<int>[N + 1];
    vector<bool> flag;
    for (int i = 0; i < M; ++i) {
        cin >> from >> to;
        data[from].push_back(to);
        data[to].push_back(from);
    } //接收数据
    int K, Np, v;
    cin >> K;
    for (int j = 0; j < K; ++j, flag.clear()) {
        flag.resize(N + 1, false);
        cin >> Np;
        for (int i = 0; i < Np; ++i) {
            cin >> v;
            flag[v] = true;
        }  //设置已经打下来的城市为true
        bool OK = true;
        for (int k = 1; k <= N; ++k) { //遍历flag数组，查看有没有相连的节点
            if (flag[k] != true) {
                for (vector<int>::iterator i = data[k].begin(); i != data[k].end(); i++) {
                    if (flag[*i] == false) {
                        OK = false;
                        k = N;
                        break;//出现了相邻的城市，跳出循环
                    }
                }
            }
        }
        if (OK == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}