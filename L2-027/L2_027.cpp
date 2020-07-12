#include <iostream>
#include <set>
using namespace  std;
struct Node{
    string email;
    int grades;
    friend bool operator < (const Node& a, const Node& b){
        if(a.grades!=b.grades)
        return !(a.grades<b.grades);
        else{
            return a.email<b.email;
        }
    }
}tmp;
multiset<Node>data;
int main() {
    ios::sync_with_stdio(false);
    int N,G,K,count=0;
    cin>>N>>G>>K;
    for (int i = 0; i <N ; ++i) {
        cin>>tmp.email >>tmp.grades;
        data.insert(tmp);
    }
    for (multiset<Node>::iterator j = data.begin(); j !=data.end() ; ++j) {
        if(j->grades>=G)
            count+=50;
        else if(j->grades>=60)
            count+=20;
    }
    cout<<count<<endl;
    int i=1,pre_grades=data.begin()->grades,same_grades=-1;
    for (multiset<Node>::iterator j = data.begin(); j !=data.end(); ++j)
    {
        if(j->grades!=pre_grades)
        {
            i=i+same_grades+1;
            pre_grades=j->grades;
            same_grades=0;
            if(i>K)
                break;
        } else{
            same_grades++;
        }
        cout<<i<<" "<<j->email<<" "<<j->grades<<endl;
    }

    return 0;
}
