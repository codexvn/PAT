#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct House {
    int count = 0;
    double area = 0;
} data[10001];
int Boss[10000];

int FindBoss(int ID) {
    if (Boss[ID] == ID)
        return ID;
    else {
        int tmp = FindBoss(Boss[ID]);
        Boss[ID] = tmp;
        return tmp;
    }
}

void Merge(int ID_a, int ID_b) {
    int tmp_ID_a = FindBoss(ID_a);
    int tmp_ID_b = FindBoss(ID_b);
    if (tmp_ID_a < tmp_ID_b)
        Boss[tmp_ID_b] = tmp_ID_a;
    else
        Boss[tmp_ID_a] = tmp_ID_b;
}

int main() {
    bool merged[10000] = {false};
    for (int i = 0; i < 10000; ++i)
        Boss[i] = i;
    int N, ID, ID_father, ID_mother, ID_child_n, ID_child;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> ID >> ID_father >> ID_mother >> ID_child_n;
        merged[ID] = true;
        if (ID_father != -1) {
            merged[ID_father] = true;
            Merge(ID, ID_father);
        }
        if (ID_mother != -1) {
            merged[ID_mother] = true;
            Merge(ID, ID_mother);
        }
        for (int j = 0; j < ID_child_n; ++j) {
            cin >> ID_child;
            merged[ID_child] = true;
            Merge(ID, ID_child);
        }
        cin >> data[ID].count >> data[ID].area;
    }
    struct family_group {
        int count = 0;
        double area = 0;
        double avg_count = 0;
        double avg_area = 0;
        vector<int> member;
    };
    map<int, family_group> boss_list;
    for (int k = 0; k < 10000; ++k) {
        if (merged[k] == true) {
            int ID_tmp = FindBoss(k);
            boss_list[ID_tmp].member.push_back(k);
            boss_list[ID_tmp].count += data[k].count;
            boss_list[ID_tmp].area += data[k].area;
        }
    }
    for (auto i = boss_list.begin(); i != boss_list.end(); i++) {
        i->second.avg_area = i->second.area / i->second.member.size();
        i->second.avg_count = (double )i->second.count / i->second.member.size();
    }
    vector<map<int, family_group>::iterator> sorted_boss_list;
    for (auto i = boss_list.begin(); i != boss_list.end(); ++i) {
        sorted_boss_list.push_back(i);
    }
    sort(sorted_boss_list.begin(), sorted_boss_list.end(),
         [](const map<int, family_group>::iterator &a,
            const map<int, family_group>::iterator &b) -> bool {
             if ((*a).second.avg_area > (*b).second.avg_area)
                 return true;
             else if ((*a).second.avg_area == (*b).second.avg_area)
                 return (*a).first < (*b).first;
             else
                 return false;
         });
    cout<<sorted_boss_list.size()<<endl;
    for(auto& i:sorted_boss_list )
       printf("%04d %d %.3f %.3f\n",i->first,i->second.member.size(),i->second.avg_count,i->second.avg_area);
    return 0;
}