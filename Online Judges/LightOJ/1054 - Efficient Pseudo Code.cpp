#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>
#define MA(a,b) map<a,b>

#define lld long long
#define MOD 1000000007
#define PI acos(-1.0)

#define MAX 100010
bool prime[MAX+10];
vector<int>primeList;
int Vsize;

void seive()
{
    for(int i=4;i<=MAX;i+=2)
        prime[i]=1;
    int srt = sqrt(MAX);
    for(int i=3;i<=srt;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=MAX;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[0]=prime[1]=1;

    for(int i=2;i<=MAX;i++)
    {
        if(prime[i]==0)
        {
            primeList.push_back(i);
        }
    }

    Vsize = primeList.size();
}

lld x, y;
void extendedEulid(lld a, lld b)
{
    if(b==0)
    {
        x=a; y=0;
        return ;
    }
    extendedEulid(b,a%b);
    lld x1 = y;
    lld y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}

lld solve(lld n, lld k)
{
    if(k==0)
        return 1;
    if(k%2==1)
        return ((n%MOD)*solve(n,k-1)%MOD)%MOD;
    lld res = solve(n,k/2)%MOD;
    return (res*res)%MOD;
}

int main()
{
    seive();

    int test;
    unsigned long long int res,up;
    long long int n,m;

    READ(test);

    for(int i=1;i<=test;i++)
    {
        scanf("%lld %lld",&n,&m);

        res = 1;

        int sq = sqrt(n);

        for(int j=0;j<Vsize && primeList[j]<=sq;j++)
        {
            int count=0;

            if(n%primeList[j]==0)
            {
                while(n%primeList[j]==0)
                {
                    count++;
                    n/=primeList[j];
                }

                up = (solve(primeList[j],((count*m)+1))+MOD-1)%MOD;

                extendedEulid((primeList[j]-1),MOD);
                res = (res*up)%MOD;
                res = (res*(x+MOD)%MOD)%MOD;
            }
        }
        if(n>1)
        {
             up = (solve(n,(m+1))+MOD-1)%MOD;

            extendedEulid((n-1),MOD);
            res = (res*up)%MOD;

            res = (res*(x+MOD)%MOD)%MOD;
        }
        printf("Case %d: %llu\n",i,res);
    }
    return 0;
}
