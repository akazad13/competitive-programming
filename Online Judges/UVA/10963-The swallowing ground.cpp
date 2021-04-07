#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int i=1;i<=test;i++)
    {
        bool flag=1;
        int column,x,y,val1,val2;
        cin>>column;

        cin>>x>>y;
        val1=abs(x-y);

        for(int j=1;j<column;j++)
        {
            cin>>x>>y;
            val2= abs(x-y);
            if(val1!=val2)
            {
                flag=0;
                //break;
            }

        }
        if(i>1)
            cout<<"\n";
        if(flag)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }


    return 0;
}
