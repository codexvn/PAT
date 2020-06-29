#include<iostream>
#include<cstdlib>
#include<cstdio>
#define NULL -1
using namespace std;
struct Node {
    int value;
    int previous = NULL, next = NULL;
};
int main() {
    int begin, n,count=0,deleted[100000]={0};
    cin >> begin >> n;
    Node list[100000];  //节点地址是非负的5位整数
    bool flag[10001] = {0};  //不超过10^4,也就是说最大的数是10^4
    for (int i = 0; i < n; ++i) {
        int pre_node_address;
        cin >> pre_node_address;
        cin >> list[pre_node_address].value >> list[pre_node_address].next;
        list[pre_node_address].previous = pre_node_address;
    }
    for (; list[begin].next != NULL;) {
        flag[abs(list[begin].value)] = true;
        if (flag[abs(list[list[begin].next].value)] == false) {
            printf("%05d %d %05d\n",list[begin].previous,list[begin].value,list[begin].next);
            begin = list[begin].next;
        } else {
            deleted[count]=list[begin].next;
            count++;
            list[begin].next = list[list[begin].next].next;
        }
    }
    printf("%05d %d -1\n",begin,list[begin].value);
    if(count!=0){
        for (int i = 0; i <count-1; ++i)
            printf("%05d %d %05d\n",deleted[i] ,list[deleted[i]].value,deleted[i+1]);
        printf("%05d %d -1\n",deleted[count-1], list[deleted[count-1]].value);
    }
    return 0;
}

/*
有几个坑
 1:一开始是用的 cout<<setfill('0'<<setw(5)<<XXXX;结果发现最后两个测试超时，换成printf过了
 2:17-18行原来是合并的,cin >> pre_node_address>> list[pre_node_address].value >> list[pre_node_address].next;
    我自己的gcc10的可以正常运行的,但是判题用的gcc6不能按我期望的行为执行(为什么不换gcc10???)

 */