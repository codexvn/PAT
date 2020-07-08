#include <iostream>
#include <set>
#include <iterator>
using namespace std;
struct Node {
    string name;
    int count = 0;
    set<int> label;
    friend  bool operator <(const Node& a ,const Node&b ){
        if (a.label.size() > b.label.size())
            return true;
        else if (a.label.size() == b.label.size() and a.count < b.count) //标签出现次数平均值最小，也就是count/label.size()，count是一样大，所以这里可以简化
            return true;
        else return false;
    }
}tmp;
multiset<Node>data;
int main() {
    std::ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i,tmp.label.clear()) {
        cin >> tmp.name >> tmp.count;
        for (int j = 0; j < tmp.count; ++j) {
            int tmp2;
            cin >> tmp2;
            tmp.label.insert(tmp2);
        }
        data.insert(tmp);
    }
    int print_count=1;
    cout<<data.begin()->name;
    auto  i = data.begin();
    for (++i;i!=data.end() and print_count<3;++i){
            cout<<" " <<i->name;
            print_count++;
        }
      while (print_count<3){
          cout<<" -";
          print_count++;
      }
    return 0;
}
