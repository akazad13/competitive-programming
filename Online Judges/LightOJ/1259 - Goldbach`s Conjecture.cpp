#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))

#define lld long long int
#define MAX 10000010
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
    int test,n,count;
    READ(test);

    for(int i=1;i<=test;i++)
    {
        READ(n);
        count=0;
        for(int i=0;primeList[i]<=n/2;i++)
        {
            if(prime[primeList[i]]==false && prime[n-primeList[i]]==false)
            {
               count++;
            }
        }
        printf("Case %d: %d\n",i,count);
    }
    return 0;
}
