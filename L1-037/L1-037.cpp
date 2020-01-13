#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
     cout<<fixed<<setprecision(2);
    int A,B;
    cin>>A>>B;
    if(B==0)
        cout<<A<<'/'<<B<<'='<<"Error"<<endl;
    else if (B>0)
        cout<<A<<'/'<<B<<'='<<(double)A/B;
    else cout<<A<<'/'<<'('<<B<<')'<<'='<<(double)A/B;

}