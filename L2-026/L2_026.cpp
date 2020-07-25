#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int Max_level = 0;
vector<int> result;
vector<int> *data;

void DFS(int ID, int level) {
    if (level > Max_level) {
        Max_level = level;
        result.clear();
        result.push_back(ID);
    } else if (level == Max_level)
        result.push_back(ID);
    for (vector<int>::iterator i = data[ID].begin(); i != data[ID].end(); ++i)
        DFS(*i, level + 1);
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    int N, tmp, min = 0;
    cin >> N; //人口总数N
    data = new vector<int>[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> tmp;
        if (tmp != -1)
            data[tmp].push_back(i);
        else
            data[0].push_back(i);   //设id 0为辈分最大的
    } //接收数据
    DFS(data[0][0], 1);  //从祖师爷开始，祖师爷的辈分是1
    cout << Max_level << endl << result[0];
    for (vector<int>::iterator j = result.begin() + 1; j != result.end(); ++j)
        cout << " " << *j;
    return 0;
}
