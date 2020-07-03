#include <iostream>

using namespace std;
struct POP {
    int ID_father = -1, ID_mother = -1;
    char sex;
    int flag = 0;
} data[100000];

void SetFlag(int ID, int flag, int level = 0) {
    if (level == 5) {
        return;
    } else {
        data[ID].flag = flag;
        if (data[ID].ID_father != -1)
            SetFlag(data[ID].ID_father, flag, level + 1);
        if (data[ID].ID_mother != -1)
            SetFlag(data[ID].ID_mother, flag, level + 1);
    }
}

bool HaveSameFlag(int ID, int flag, int level = 0) {
    bool tmp1, tmp2;
    if (level == 5)
        return false;  //5代内无相同的亲戚
    else {
        if (data[ID].flag == flag)
            return true;    //5代内找到相同的flag
        else {
            if (data[ID].ID_father != -1)
                if( HaveSameFlag(data[ID].ID_father, flag, level + 1)== true)
                    return true;
            if (data[ID].ID_mother != -1)
                if( HaveSameFlag(data[ID].ID_mother, flag, level + 1)== true)
                    return true;
            return false;
        }

    }
}
int main() {
    int N, ID_boy, ID_girl;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int ID_tmp;
        cin >> ID_tmp;
        cin >> data[ID_tmp].sex >> data[ID_tmp].ID_father >> data[ID_tmp].ID_mother;
        data[data[ID_tmp].ID_father].sex='M';//这个地方千万要注意,因为后面不一定会给父母的信息
        data[data[ID_tmp].ID_mother].sex='F';//PTA教我做人
    }
    cin >> N;
    for (int j = 0, flag = 1; j < N; ++j, flag++) {
        cin >> ID_boy >> ID_girl;
        if (data[ID_boy].sex == data[ID_girl].sex)
            cout << "Never Mind" << endl;
        else {
            SetFlag(ID_boy, flag);
            if (HaveSameFlag(ID_girl, flag) == true)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}