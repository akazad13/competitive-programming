#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test,n,m;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        int arr[110],a,b;
        cout<<"Case "<<i<<":"<<endl;
        cin>>n>>m;
        for(int k=0;k<n;k++)
            cin>>arr[k];
        while(m--)
        {
            char ch =getchar();
            ch=getchar();
            if(ch=='S')
            {
                cin>>a;
                for(int k=0;k<n;k++)
                    arr[k]+=a;
            }
            else if(ch=='M')
            {
                cin>>a;
                    for(int k=0;k<n;k++)
                    arr[k]*=a;
            }
            else if(ch=='D')
            {
                cin>>a;
                for(int k=0;k<n;k++)
                    arr[k]/=a;
            }

            else if(ch=='P')
            {
                cin>>a>>b;
                swap(arr[a],arr[b]);
            }
            else if(ch=='R')
            {
                for(int k=0;k<n/2;k++)
                    swap(arr[k],arr[n-1-k]);
            }
        }
        for(int k=0;k<n-1;k++)
                cout<<arr[k]<<" ";
            cout<<arr[n-1]<<endl;
    }

    return 0;
}
