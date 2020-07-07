#include <iostream>
#include <vector>
using namespace std;
struct Node{
    vector<int>next;
    bool flag=false;//得道者
    double enlarge=0;//得道者放大倍数
};
vector<Node>data;
int N;
double Z,r, count=0;;
inline void DFS(double value,int i =0){
    double value_tmp=value*(100-r)/100;
    if(data[i].next.size()==0)
        return;
    for( vector<int>::iterator j =data[i].next.begin();j!=data[i].next.end();j++ ){
        if(data[*j].flag==false)
            DFS(value_tmp,*j);
         else{
            count+=value_tmp*data[*j].enlarge;
            DFS(value_tmp*data[*j].enlarge,*j);
        }

    }


}

int main(){
    ios::sync_with_stdio(false);
    cin>>N>>Z>>r;
    data.resize(N);
    for (int i = 0; i <N ; ++i) {
        int tmp;
        cin >>tmp;
        if(tmp==0){
            cin>>data[i].enlarge;
            data[i].flag=true;
        }
        else{
            int tmp2;
            for (int j = 0; j <tmp ; ++j) {
                cin>>tmp2;
                data[i].next.push_back(tmp2); //插入徒弟
            }
        }
    }
    if(N==1 and data[0].flag== true){
        cout<<int(Z*data[0].enlarge)<<endl;
        return 0;
    }
    DFS(Z);
    cout<<int(count)<<endl;
}