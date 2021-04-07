#include<iostream>
#include<bits/stdc++.h>


bool arr[5010];

using namespace std;

bool fun(int n)
{
    int a[15]={0};
    while(n!=0)
    {
        a[n%10]++;
        n/=10;
    }

    int flag=1;
    for(int i=0;i<10;i++)
    {
        if(a[i]>1)
        {
            flag=0;
            break;
        }
    }
    if(flag)
        return true;
    else
        return false;

}

int main()
{
    for(int i=1;i<=5000;i++)
    {
        arr[i]=fun(i);
    }

    int n,m;

    while(cin>>n>>m)
    {
        int count=0;
        for(int i=n;i<=m;i++)
        {
            if(arr[i]==true)
                count++;
        }

        cout<<count<<"\n";
    }

    return 0;

}
