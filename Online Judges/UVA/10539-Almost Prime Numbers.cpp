#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool prime[1000050];

long long int AlmostPrime[80080];

void sieve()
{
    int i,j;

    for(i=4;i<=1000006;i+=2)
    {
        prime[i]=1;
    }

    for(i=3;i<=sqrt(1000006);i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=1000006;j+=2*i)
            {
                prime[j]=1;
            }
        }

    prime[1]=1;

    }
}

int main()
{
    sieve();
    long long int i,j;
    int k=0;
    int count1=0;
    for(int i= 2;i<=32000;i++)
    {
        if(prime[i]==0)
            count1++;
    }

    cout<<count1<<endl;

    for(i=2;i<=1000006;i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=1000000000000;j*=i)
                AlmostPrime[k++]=j;
        }
    }

    //cout<<k<<endl;

    int test;
    long long int low, high;
    int count;

    cin>>test;
    while(test--)
    {
        count=0;
        cin>>low>>high;
        if(low>high)
            swap(low,high);
        for(i=0;i<=80080;i++)
        {
            if(AlmostPrime[i]>=low&&AlmostPrime[i]<=high)
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
