#include<iostream>
#include<bits/stdc++.h>

using namespace std;


#define Max 10100

bool prime[Max+10];
vector<int> primeList;
int factor[10200];
int Vsize;
vector<int>res;

void sieve()
{
    for(int i=4;i<=Max;i+=2)
        prime[i]=true;

    int sqt = sqrt(Max);

    for(int i=3;i<=sqt;i+=2)
    {
        if(prime[i]==false)
        {
            for(int j=i*i;j<=Max;j+=2*i)
            {
                prime[j]=true;
            }
        }
    }
    prime[0]=prime[1]=0;
    for(int i=2;i<=Max;i++)
    {
        if(prime[i]==false)
        {
            primeList.push_back(i);
        }
    }
    Vsize = primeList.size();
}

void cal(int num)
{
   int cnt;

    for(int i=0;i<Vsize && primeList[i]<=sqrt(num);i++)
    {
        cnt=0;
        if(num%primeList[i]==0)
        {
            while(num%primeList[i]==0)
            {
                num/=primeList[i];
                cnt++;
            }

            if(factor[primeList[i]]<cnt)
                factor[primeList[i]]=cnt;
        }
    }

    if(num!=1)
    {
        if(factor[num]<1)
                factor[num]=1;
    }

}

void multiply(long long int n)
{
    int SIZE = res.size();
    long long int carry=0;
    for(int i=0;i<SIZE;i++)
    {
        carry+=res[i]*n;
        res[i]=carry%10;
        carry/=10;
    }
    while(carry)
    {
        res.push_back(carry%10);
        carry/=10;
    }

}

int main()
{
    sieve();
    int p;

    int test,n,num;
    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        memset(factor,0,sizeof(factor));
        res.clear();
        res.push_back(1);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            cal(num);
        }
        for(int i=2;i<=10000;i++)
        {
            if(factor[i])
            {
                long long int p = round(pow(i,factor[i]));
                multiply(p);
            }
        }

        int S = res.size();

        printf("Case %d: ",Case);

        for(int i=S-1;i>=0;i--)
        {
            printf("%d",res[i]);
        }
        printf("\n");

    }
    return 0;
}
