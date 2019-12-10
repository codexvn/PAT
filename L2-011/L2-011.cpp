#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int *pre, *order;
typedef  struct
{
    int index;
    int* address;
}Node;
vector<Node>TreeNode;
bool tmp(Node a,Node b)
{
    return a.index<b.index;
}

void post (int root,int start, int end,int index)
{
    if(start>end)
        return;
    int i;
    for (i = start;  pre[root]!=order[i] ; ++i) ;
    TreeNode.push_back({index,&pre[root]});
    post(root+1,start,i-1,2*index+2);
    post(root+1+i-start,i+1,end,2*index+1);
}
int main() {

    int N;
    cin >> N;
    pre = new int[N];
    order = new int[N];
    for (int i = 0; i < N; ++i) cin >> order[i];
    for (int i = 0; i < N; ++i) cin >> pre[i];
    post(0,0,N-1,0);
    sort(TreeNode.begin(),TreeNode.end(),tmp);
    for (int j = 0; j <N ; ++j) {
        cout<<*(TreeNode[j].address);
        if (j!=N-1)
            cout<<' ';
    }

}