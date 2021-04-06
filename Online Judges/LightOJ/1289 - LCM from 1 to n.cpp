#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define llread(a) scanf("%lld",&a)
#define read(a) scanf("%d",&a)
#define write(a) printf("%d\n",a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>
#define MA(a,b) map<a,b>

#define lld long long int
#define uud unsigned int

#define MAX 100000000
uud prime[(MAX/32)+10]={0};
uud primeList[5761456];
int Vsize;


bool Check(int n, int pos)
{
    return  n&(1<<pos);
}
int Set(int n, int pos)
{
    return n= n|(1<<pos);
}


void seive()
{
    for(int i=4;i<=MAX;i+=2)
    {
        prime[i>>5]= Set(prime[i>>5],i&31);
    }
    int srt = sqrt(MAX);
    for(int i=3;i<=srt; i+=2)
    {
        if( Check(prime[i>>5],i&31)==0)
        {
            for(int j=i*i;j<=MAX;j+=(i<<1) )
            {
                prime[j>>5]=Set(prime[j>>5],j&31);
            }
        }
    }
    Vsize=0;
    for(int i=2;i<MAX;i++)
    {
        if( Check(prime[i>>5],i&31)==0)
        {
            primeList[Vsize++]=i;
        }
    }

}

uud dp[5761465]={0};

int main()
{
    seive();

    dp[0]=2;
    for(int i=1;i<Vsize;i++)
        {dp[i]=dp[i-1]*primeList[i];
      //  cout<<dp[i]<<endl;
        }

    int n,test,p,cpy;
    uud res;

    cin>>test;

    for(int Case=1; Case<=test; Case++)
    {
        res=1;
        read(n);
        p = sqrt(n);
        int i,upper;
        for(i=0;i<Vsize && primeList[i]<=p;i++)
        {
            cpy = n/primeList[i];
            while(cpy>=primeList[i])
            {
                cpy/=primeList[i];
                res*=primeList[i];
            }
        }
        cout<<res<<endl;

        if(i<Vsize)
        {
            upper = upper_bound(primeList,primeList+Vsize,n)-primeList;
            res = res* dp[upper-1];
        }

        printf("Case %d: %u\n",Case,res);
    }
    return 0;


}


