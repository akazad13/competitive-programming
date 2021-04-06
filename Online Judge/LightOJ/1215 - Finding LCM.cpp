#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define READ(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define lld long long int

#define MAX 1000100
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



int arr1[1000012];
int arr2[1000012];
int arr3[1000012];

lld POW(int a,int b)
{
    lld ans=1;
    for(int i=1;i<=b;i++)
    {
        ans*=(lld)a;
    }

    return ans;
}

int main()
{
    seive();
    int test;
    READ(test);
    lld a,b,n,ans,i;

    for(int Case= 1;Case<=test;Case++)
    {
        scanf("%lld %lld %lld",&a,&b,&n);
        CLEAR(arr1,0);
        CLEAR(arr2,0);
        CLEAR(arr3,0);
        ans=1;

        for(i=0;i<Vsize && primeList[i]*primeList[i]<=a;i++)
        {
            if(a%primeList[i]==0)
            {
               while(a%primeList[i]==0)
               {
                   arr1[primeList[i]]++;
                   a/=primeList[i];
               }
            }
        }

        if(a!=1)
            arr1[a]++;

        for(i=0;i<Vsize && primeList[i]*primeList[i]<=b;i++)
        {
            if(b%primeList[i]==0)
            {
               while(b%primeList[i]==0)
               {
                   arr2[primeList[i]]++;
                   b/=primeList[i];
               }
            }
        }

        if(b!=1)
            arr2[b]++;

        for(i=0;i<Vsize && primeList[i]*primeList[i]<=n;i++)
        {
            if(n%primeList[i]==0)
            {
               while(n%primeList[i]==0)
               {
                   arr3[primeList[i]]++;
                   n/=primeList[i];
               }
            }
        }
        if(n<1000000 && n!=1)
        {
            arr3[n]++;
            n/=n;
        }

        bool flag=0;
        ans=1;

        for(int i=0;i<1000000;i++)
        {
            int m = max(arr1[i],arr2[i]);
            if(m>arr3[i])
            {
                flag=1;
                break;
            }
            else if(m<arr3[i])
            {
                ans*=POW(i,arr3[i]);
            }
        }

        if(flag)
        {
            printf("Case %d: impossible\n",Case);
        }
        else
        {
            printf("Case %d: %lld\n",Case,ans*n);
        }

    }
    return 0;

}
