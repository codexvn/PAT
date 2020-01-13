#include <cstdio>
#include <set>
using namespace std;
int main()
{
    int y,n;
    scanf("%d%d",&y,&n);
    set<int>my_set;
    for (int j=0;;j++)
    {
        my_set.clear();
        int y_copy=y+j;
        for (int i = 0; i <4 ; ++i) {
            my_set.insert(y_copy%10);
            y_copy/=10;
        }
        if(my_set.size()==n)
        { printf("%d %04d",j,y+j);
            break;
        }
    }
}