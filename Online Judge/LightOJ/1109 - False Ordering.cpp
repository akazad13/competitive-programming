#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int num,count=0;
};

bool comp (node a,node b)
{
    if(a.count==b.count)
        return a.num>b.num;
    else
        return a.count<b.count;
}

int main()
{
    struct node Data[1002];
    int arr[1002];

    for(int i=1000;i>=1;i--)
    {
        int j=i;
        int k=1;
        Data[1000-i+1].num=i;
        while(k<=(i/2))
        {
            if(i%k==0)
            {
                Data[1000-i+1].count++;
            }
            k++;
        }
        Data[1000-i+1].count++;
    }

    sort(Data+1,Data+1001,comp);

    int test,n;

    cin>>test;

    for(int Case=1;Case<=test;Case++)
    {
        cin>>n;

        cout<<"Case "<<Case<<": "<<Data[n].num<<endl;
    }
    return 0;
}
