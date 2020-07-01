#include <iostream>
#include <set>
#include <vector>
#include <iomanip>
using namespace std;
struct House{
    int count=0;
    double area;

}data[10001];

int main(){
    cout<<fixed<<setprecision(2);
    vector<set<int>>family_group;
    bool joined_group[10001]={false};
    int N,ID,ID_father,ID_mother,ID_child,N_child;
    cin>>N;
    vector<int>ID_tmp;
    for (int i = 0; i <N ; ++i,ID_tmp.clear()) {
        cin>>ID>>ID_father>>ID_mother>>N_child;
        ID_tmp.push_back(ID);
        if(ID_father!=-1)
        ID_tmp.push_back(ID_father);
        if(ID_mother!=-1)
        ID_tmp.push_back(ID_mother);
        for (int j = 0; j <N_child ; ++j) {
            cin>>ID_child;
            ID_tmp.push_back(ID_child);
        }
        cin>>data[ID].count>>data[ID].area;


        auto k = ID_tmp.begin();
        bool finded_group=false;
        for (; k !=ID_tmp.end(); ++k) {
            if(joined_group[*k]== true and finded_group==false)
            {
                for (auto l = family_group.begin(); l != family_group.end(); ++l)
                {
                    if((*l).find(*k)!=(*l).end())
                    {
                        (*l).insert(ID_tmp.begin(),ID_tmp.end());
                        finded_group=true;
                        break;
                    }

                }
            }
            joined_group[*k]= true;
        }
        if(finded_group== false)
        {
            family_group.push_back(set<int>(ID_tmp.begin(),ID_tmp.end()));
        }
    }
    cout<<family_group.size();
    for (auto j  = family_group.begin();j!= family_group.end(); ++j) {

        int count_this_family=0;
        double area_this_family=0;
        for (auto i = (*j).begin(); i !=(*j).end() ; ++i)
        {
            count_this_family+=data[(*i)].count;
            area_this_family+=data[(*i)].area;
        }
        cout<<*(*j).begin()<<" "<<(*j).size()<<" "<< (double)count_this_family/((*j).size()-(*j).count(-1))<<" "<< area_this_family/((*j).size()-(*j).count(-1))<<endl;
    }
    return 0;
}