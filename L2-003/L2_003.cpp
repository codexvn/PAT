#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
struct Food{
    double store,sell;
};
int main() {
    double count=0;
    int n,all;
    cin>>n>>all;
    vector<Food>data(n);
    for (int i = 0; i <n ; ++i)
        cin>>data[i].store;
    for (int i = 0; i <n ; ++i)
        cin>>data[i].sell;
    sort(data.begin(),data.end(),[](const Food& a,const Food& b){return (a.sell/a.store)>(b.sell/b.store); });//按价值比降序排序
    for (auto i= data.begin();i!=data.end() and all!=0 ; ++i) {
        if(all>=i->store){
            all-=i->store;
            count+=i->sell;
        }
        else{
            count+=all/i->store*i->sell;
            all=0;
        }
    }
    cout<<fixed<<setprecision(2)<<count;
    return 0;
}