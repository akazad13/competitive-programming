#include<iostream>
#include<bits/stdc++.h>

double Arr[1000010];

using namespace std;

int main()
{
    int test,num,base,j;

    for(j=1;j<1000002;j++)
    {
        Arr[j]=Arr[j-1]+log(j+0.0);
    }

    cin>>test;
    for(int i=1;i<=test;i++)
    {
        cin>>num>>base;

        int digit=0;
        digit=1+floor((Arr[num])/log(base+0.0));

        cout<<"Case "<<i<<": "<<digit<<endl;

    }
    return 0;
}
