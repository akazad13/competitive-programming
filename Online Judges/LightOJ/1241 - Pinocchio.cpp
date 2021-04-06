#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   int test;

   cin>>test;
   for(int i=1;i<=test;i++)
   {
       int count=0;

       int arr[100];
       arr[0]=2;
       int n;

       cin>>n;

       for(int k=1;k<=n;k++)
       {
           cin>>arr[k];
       }

       for(int k=0;k<n;k++)
       {
           if((arr[k+1]-arr[k])>0)
           {
               if((arr[k+1]-arr[k])%5==0)
                    count+=(arr[k+1]-arr[k])/5;
               else
                    count+=((arr[k+1]-arr[k])/5)+1;
           }
       }

        cout<<"Case "<<i<<": "<<count<<"\n";
   }

    return 0;
}



