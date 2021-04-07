#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    float f1,f2,money;

    while(cin>>t)
    {
        while(t--)
        {
            cin>>f1>>f2>>money;
            f1=(money/(f1+f2))*f1+(f1-f2)*(money/(f1+f2));
            if(f1>=0)
                cout<<fixed<<setprecision(0)<<f1<<endl;
            else
                cout<<"0"<<endl;
        }
    }
    return 0;
}
