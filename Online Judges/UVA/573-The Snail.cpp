#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        if(a==0)
            break;
        double start=0.0;
        double ff = (b*d/100);
       // start-=c;
        int count=0;
        bool flag=1;
        while(1)
        {
           count++;
           if(b>0)
            start+=b;
           b-=ff;

           if(start>a)
            break;

           start-=c;

            if(start<0)
            {
                flag=0;
                break;
            }

        }

        if(flag==1)
        {
            cout<<"success on day "<<count<<endl;
        }
        else
        {
            cout<<"failure on day "<<count<<endl;
        }
    }

    return 0;
}
