#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()

{
    int t,a,b,c,i;

    while(cin>>t)
    {
        for(i=1;i<=t;i++)
        {
            cin>>a>>b>>c;
            if(a>b)
            {
                if(b>c)
                    cout<<"Case "<<i<<": "<<b<<endl;
                else
                {
                    if(a>c)
                        cout<<"Case "<<i<<": "<<c<<endl;
                    else
                        cout<<"Case "<<i<<": "<<a<<endl;
                }
            }
            else
            {
                if(a>c)
                    cout<<"Case "<<i<<": "<<a<<endl;
                else
                {
                    if(b>c)
                        cout<<"Case "<<i<<": "<<c<<endl;
                    else
                        cout<<"Case "<<i<<": "<<b<<endl;
                }
            }
        }
    }
    return 0;
}
