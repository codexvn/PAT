#include <iostream>
using namespace std;
int main() {
    char N[1000]={0};
    int count[10]={0};
    cin >>N;
    for (int i = 0;N[i]; ++i) count[N[i]-48]++;
    for (int j = 0; j < 10; ++j)
        if (count[j])
        cout<<char(j+48)<<":"<<count[j]<<endl;
    return 0;
}