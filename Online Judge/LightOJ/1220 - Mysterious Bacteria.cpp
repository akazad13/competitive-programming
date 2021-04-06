#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define lld long long int

#define MAX 1000010
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

int main()
{
    seive();
    int test;
    READ(test);
    lld n;
    int a;
    bool flag;
    int count;

    for(int Case=1;Case<=test;Case++)
    {
        flag=0;
        scanf("%lld",&n);

        if(n<0)
        {
            n=-1*n;
            flag=true;
        }


        a=-76;
        for(lld i=0;i<Vsize && primeList[i]*primeList[i]<=n;i++)
        {
            count=0;

            if(n%primeList[i]==0)
            {
                while(n%primeList[i]==0)
                {
                    n/=primeList[i];
                    count++;
                }
            }

            if(a<0)
            {
                if(count>0)
                    a=count;
            }

            else if(count>0)
            {
                a=__gcd(a,count);
            }
        }
        if(n>1)
            a=__gcd(a,1);
        if(flag)
        {
            while(a%2==0)
            {
                a/=2;
            }
        }
        printf("Case %d: %lld\n",Case,a);
    }
    return 0;
}
