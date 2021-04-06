#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lld long long int
#define max 1001110
int cnt=0;

bool prime[max+100];
int primeList[max];

void sieve()
{
    int i,j;
    for(i=4;i<=max;i+=2)
        prime[i]=1;

    long long int s=sqrt(max);
    for(i=3;i<=s;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=max;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[1]=prime[0]=1;

    for(int i=2;i<max;i++)
    {
        if(prime[i]==0)
        {
            primeList[cnt++]=i;
        }
    }
}


int main()
{
    sieve();
    int test,res,count;
    lld num;

    scanf("%d",&test);

    for(int t=1;t<=test;t++)
    {
        scanf("%lld",&num);
        res = 1;
        for(int i=0;i<cnt && (primeList[i]*primeList[i])<=num;i++)
        {
            count=0;
            while(num%primeList[i]==0)
            {
                count++;
                num/=primeList[i];
            }
            res = res * (count+1);
        }

        if(num!=1)
            res = res*2;


        printf("Case %d: %d\n",t,res-1);
    }

    return 0;
}
