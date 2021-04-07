#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    //freopen("D:\\10812.txt","r",stdin);
    unsigned long int t,s,d,a, b;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>s>>d;
            if(s<d)
                cout<<"impossible"<<endl;
            else if((s+d)%2!=0)
                cout<<"impossible"<<endl;
            else
            {
                a=(s+d)/2;
                b=s-a;
                //if(abs(a-b)==d)
                    cout<<a<<" "<<b<<endl;
                //else
                   // cout<<"impossible"<<endl;
            }
        }

    }
    return 0;
}
