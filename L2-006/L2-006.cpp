#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int *postorder, *inorder;
typedef struct {
    int index;
    int *address;
} Node;
vector<Node> pre;

bool little(Node a, Node b) {
    return a.index < b.index;
}

void PreOrder(int root, int start, int end, int index) {
    if (start > end)
        return;
    int i;
    for (i = start; postorder[root] != inorder[i]; ++i);//找到后序遍历中当前根节点在中序遍历中的下标
    pre.push_back({index, &postorder[root]});
    PreOrder(root - end + i - 1, start, i - 1, 2 * index + 1);
    PreOrder(root - 1, i + 1, end, 2 * index + 2);
}

int main(void) {
    int N;
    cin >> N;
    postorder = new int[N];
    inorder = new int[N];
    for (int j = 0; j < N; ++j) cin >> postorder[j];
    for (int j = 0; j < N; ++j) cin >> inorder[j];//接受数据
    PreOrder(N - 1, 0, N - 1, 0);
    sort(pre.begin(), pre.end(), little);
    for (int k = 0; k < N; ++k) {
        {
            cout << *pre[k].address;
            if (k != N - 1) cout << ' ';
        }

    }
    return 0;
}