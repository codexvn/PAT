#include <iostream>
#include <set>

using namespace std;
int data[10001] = {0};
bool flag[10001] = {false};

int FindBoss(int index) {
    if (data[index] == index)
        return index;
    else {
        data[index] = FindBoss(data[index]);
        return data[index];
    }
}

void Merge(int a, int b) {
    data[FindBoss(b)] = data[FindBoss(a)];
}

set<int> boss;

int main() {
    ios::sync_with_stdio(false);
    for (int i = 1; i < 10001; ++i)
        data[i] = i;
    int N1, N2, tmp1, tmp2;
    cin >> N1;
    for (int j = 0; j < N1; ++j) {
        cin >> N2;
        if (N2 != 0) {
            cin >> tmp1;
            boss.insert(tmp1);
            flag[tmp1] = true;
            for (int i = 1; i < N2; ++i) {
                cin >> tmp2;
                flag[tmp2] = true;
                Merge(tmp1, tmp2);
            }
        }
    }
    int count1 = 0, count2 = 0;
    for (int l = 1; l < 10001; ++l)
        if (flag[l] == true)
            count1++;
    for (set<int>::iterator i = boss.begin(); i != boss.end(); ++i)
        if (*i == FindBoss(*i))
            count2++;
    cout << count1 << " " << count2 << endl;
    cin >> N1;
    for (int k = 0; k < N1; ++k) {
        cin >> tmp1 >> tmp2;
        if (FindBoss(tmp1) == FindBoss(tmp2))
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
}