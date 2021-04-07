#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin>>test;

    while(test--)
    {
        int n;
        int party;

       /* for(int i=6;i<=369;i=i+7)
        {
            arr[i]=1;
            arr[i+1]=1;
        }*/

        cin>>n;

        cin>>party;

         int p[200];

        int arr[4000]={0};


        for(int i=0;i<party;i++)
        {
            cin>>p[i];
        }

        for(int i=0;i<party;i++)
        {
            for(int j=p[i];j<=n;j+=p[i])
            {
               // if(j=6)
                    arr[j]=1;
            }
        }

         for(int i=6;i<=n;i=i+7)
        {
            arr[i]=0;
            arr[i+1]=0;
        }

        int count=0;

       for(int i=1;i<=n;i++)
       {
           if(arr[i]==1)
            {
                //cout<<i<<endl;
                count++;
            }
       }

       cout<<count<<"\n";



    }

    return 0;
}
