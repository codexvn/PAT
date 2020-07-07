#include <iostream>
#include <set>
using namespace std;
struct Node{
    string name;
    int count;
    friend bool operator < (const Node& a,const  Node& b){
        return a.name<b.name;
    }
}node_tmp;
bool no_quiet=true;
int main(){
    ios::sync_with_stdio(false);
    set<string>data;
    set<Node>quiet;
    int N;
    double count=0;
    cin>>N;
    for (int i = 0; i <N ; ++i) {
        string tmp;
        cin>>tmp;
        data.insert(tmp);
    }
    cin>>N;
    for (int j = 0; j < N; ++j) {
       cin>>node_tmp.name>>node_tmp.count;
       count+=node_tmp.count;
       quiet.insert(node_tmp);
    }
    count/=N;
    for(auto i = quiet.begin();i!=quiet.end();i++){
        if(i->count>count and data.find(i->name)==data.end())
        {
            no_quiet=false;
            cout<<i->name<<endl;
        }
    }
    if(no_quiet== true)
        cout<<"Bing Mei You"<<endl;
}