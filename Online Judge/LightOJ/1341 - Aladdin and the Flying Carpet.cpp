#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lld long long int
#define Max 1000100
bool prime[Max+10];
vector<int>primeList;
int Vsize;

void sieve()
{
    for(int i=4;i<=Max;i+=2)
    {
        prime[i]=true;
    }

    int sqt = sqrt(Max);

    for(int i=3;i<=sqt;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=Max;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }

    for(int i=2;i<=Max;i++)
    {
        if(prime[i]==0)
        {
            primeList.push_back(i);
        }
    }
    Vsize=primeList.size();
}

lld find_no_of_div(lld n)
{
    lld res=1,cnt;
    for(int i=0;i<Vsize && primeList[i]*primeList[i]<=n;i++)
    {
        cnt=0;
        if(n%primeList[i]==0)
        {
            while(n%primeList[i]==0)
            {
                n/=primeList[i];
                cnt++;
            }
            res*=(cnt+1);
        }
    }

    if(n!=1)
        res*=2;

    return res/2;
}

int main()
{
    sieve();
    int test,lim;
    lld n,div;
    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        scanf("%lld %d",&n,&lim);

        printf("Case %d: ",Case);
        if(lim>sqrt(n))
        {
            printf("0\n");
            continue;
        }

        div = find_no_of_div(n);

       int srt= sqrt(n);

        for(int i=1;i<lim;i++)
        {
            if(n%i==0)
            {
                if(n/i!=i)
                    div--;
            }
        }
        printf("%lld\n",div);

    }

    return 0;
}
