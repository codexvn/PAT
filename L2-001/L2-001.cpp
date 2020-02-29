#include <iostream>
#include <vector>
#include <climits>

using namespace std;
struct Node {
    int end;
    int value;
};

inline void PrintPre(int n, const int pre[500]) {
    if (pre[n] != n) {
        PrintPre(pre[n], pre);
        cout << " " << n;
    } else
        cout << n;
}

int main() {
    int N, M, S, D;
    int way_count[500], help_data[500], help_count[500], pre[500], dis[500], book[500] = {0};
    //way_count源点到达此点的最短路径的条数,默认为1   help_count:保存最短路径下最多能召集到的救援队 pre:保存最短路径走法
    //dis:保存Dijkstra用到的数据,book:保存是估计值还是确定值
    cin >> N >> M >> S >> D;
    fill(way_count, way_count + 500, 1);
    fill(dis, dis + 500, INT_MAX);
    fill(pre, pre + 500, S);
    vector<vector<Node>> adjacency(N);
    for (int i = 0; i < N; ++i) {
        cin >> help_data[i];
        help_count[i] = help_data[i];
    }
    int a, b, c;
    for (int j = 0; j < M; ++j) {  //创建邻接表保存路径长度
        cin >> a >> b >> c;
        adjacency[a].push_back(Node{b, c});
        adjacency[b].push_back(Node{a, c});
        if (a == S)
            dis[b] = c;
        else if (b == S)
            dis[a] = c;
    }
    book[S] = 1;//S->S的最短路径已经是确定的了
    dis[S] = 0;
    for (int k = 0; k < N - 1; ++k) { //确定所有的最短路径最多只要N-1次
        int flag;
        for (int i = 0, min = INT_MAX; i < N; ++i) {
            if (min > dis[i] and book[i] == 0) {
                min = dis[i];
                flag = i;
            }
        }
        book[flag] = 1; //flag对应的dis中的数据已经由估计值变为确定值
        if (flag == D)//此时已经已经获得S->Ｄ的题目要求所有结果，直接break
            break;
        vector<Node>::iterator start = adjacency[flag].begin(), end = adjacency[flag].end();
        for (; start != end; ++start) {
            if (book[start->end] == 1)
                continue;
            if (dis[start->end] > dis[flag] + start->value) {  //中转值减小
                dis[start->end] = dis[flag] + start->value;
                way_count[start->end] = way_count[flag];//+1?+flag?
                help_count[start->end] = help_data[start->end] + help_count[flag];
                pre[start->end] = flag;

            } else if (dis[start->end] == dis[flag] + start->value) { //中转值不变
                way_count[start->end] += way_count[flag];//+1?+flag?
                if (help_count[start->end] < help_data[start->end] + help_count[flag]) {
                    help_count[start->end] = help_data[start->end] + help_count[flag];
                    pre[start->end] = flag;
                }
            }
        }
    }
    cout << way_count[D] << " " << help_count[D] + help_data[S] << endl;
    PrintPre(D, pre);
}