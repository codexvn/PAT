#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    int firstAppearance = INT_MAX, okCount = 0, index = 0;
    while (true) {
        getline(cin, input);
        if (input ==".")
            break;
        index++;
        if (input.find("chi1 huo3 guo1") != input.npos) {
            firstAppearance = min(firstAppearance, index);
            okCount++;
        }
    }
    cout << index << endl;
    if(okCount!=0)
    cout<< firstAppearance << " " << okCount<<endl;
    else
        cout<<"-_-#"<<endl;
    return 0;
}
