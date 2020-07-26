#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;
struct Node_pop {
    bool is_girl;
    int ID;
    int count = 1;
};
struct Node {
    bool flag[1001] = {false};
    map<int, Node_pop> pop;
};
bool Cmp(const map<int, Node_pop>::iterator &a, const map<int, Node_pop>::iterator &b) {
    if ((*a).second.count == (*b).second.count)
        return (*a).second.ID < (*b).second.ID; //次数相同则按ID升序
    else
        return (*a).second.count > (*b).second.count;
}

int main() {
    std::ios::sync_with_stdio(false);
    int N, M, tmp_pop;
    string tmp;
    cin >> N >> M;
    vector<Node> data(N+1); //保存数据的数组
    for (int i = 0; i < M; ++i) {
        vector<Node_pop> pop_list;
        cin >> tmp_pop;
        for (int j = 0; j < tmp_pop; ++j) {
            cin >> tmp;  //有可能出现+-0，所以使用string来读取数据
            if(tmp.size()==1)
                pop_list.push_back(Node_pop{false,tmp[0]-'0'});
            else
                pop_list.push_back(Node_pop{true,tmp[1]-'0'});
        } //记录每张照片中有哪些人
        for (vector<Node_pop>::iterator j = pop_list.begin(); j!= pop_list.end(); ++j) {
            for (vector<Node_pop>::iterator k =pop_list.begin(); k != pop_list.end(); ++k) {
                if(j==k)
                    continue;
                if (data[j->ID].flag[k->ID] == false)//照片中第一次出现
                {
                    data[j->ID].flag[k->ID]  = true;
                    data[j->ID].pop[k->ID] = *k;
                } else
                    data[j->ID].pop[k->ID].count++; //如果曾经一起出现在同一张照片就直接增加计数器
            }

        }
    }
    string A, B;
    cin >> A >> B;
    Node_pop *pop_A,*pop_B;
    if(A.size()==1)
        pop_A=new Node_pop{false,A[0]-'0'};
    else
        pop_A=new Node_pop{true,A[1]-'0'};
    if(B.size()==1)
        pop_B=new Node_pop{false,B[0]-'0'};
    else
        pop_B=new Node_pop{true,B[1]-'0'};
    vector<map<int, Node_pop>::iterator> A_sort,B_sort;
    for(map<int, Node_pop>::iterator i = data[pop_A->ID].pop.begin();i!=data[pop_A->ID].pop.end();++i) {
        if(((*i).second.is_girl == false) ^ (A.size() == 1))
            A_sort.push_back(i);
    }
    for(map<int, Node_pop>::iterator   i = data[pop_B->ID].pop.begin();i!=data[pop_B->ID].pop.end();++i) {
        if(((*i).second.is_girl == false) ^ (B.size() == 1))
            B_sort.push_back(i);
    }
    sort(A_sort.begin(), A_sort.end(), Cmp);
    sort(B_sort.begin(), B_sort.end(), Cmp);
    return 0 ;

}