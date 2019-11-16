#include <iostream>
#include<string>
using namespace std;
int main() {
    string A,B;
    int index;
    getline(cin,A);
    getline(cin,B);
    for (auto i : B) {
        while ((index=A.find(i))!=-1)
            A.erase(index,1);
    }
    cout<<A;
 return 0;
}