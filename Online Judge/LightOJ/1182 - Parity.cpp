#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   int arr[36];

   for(int i=1;i<=31;i++)
   {
       arr[i]=pow(2,(i-1));
   }

    int test,n,count,i;

    cin>>test;

    for(int Case=1;Case<=test;Case++)
    {
        cin>>n;

        count=0;
        i=31;

        while(n>0)
        {
            if(n-arr[i]>=0)
            {
                count++;
                n-=arr[i];
            }
            i--;
        }
        if(count%2==0)
            cout<<"Case "<<Case<<": even"<<endl;
        else
            cout<<"Case "<<Case<<": odd"<<endl;
    }
    return 0;
}

