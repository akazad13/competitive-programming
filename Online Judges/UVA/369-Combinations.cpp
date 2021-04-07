#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;

    while(cin>>n>>m,n|m)
    {
        //int i=1;
        double res=1.0;
        int j=1;
        int diff=n-m;

        //cout<<diff<<endl;
        if(diff>m)
        {
           // cout<<"IN IF"<<endl;

            for(int i=diff+1;i<=n;i++)
            {
                res=(res*i)/j;
              //  cout<<res<<endl;
                j++;
            }

        }
        else
        {
          //  cout<<"IN ELSE"<<endl;
            for(int i=m+1;i<=n;i++)
            {
                res=(res*i)/j;
                //cout<<res<<endl;
                j++;
            }
        }

        printf("%d things taken %d at a time is %.0f exactly.\n",n,m,res);
    }

    return 0;
}
