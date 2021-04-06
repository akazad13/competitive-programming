#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros

#define READ(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))

#define lld long long
#define PI acos(-1.0)

#define MAX 110
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

int arr[105][105];

int main()
{
    seive();
    CLEAR(arr,0);
    int n;
    for(int i=2;i<=100;i++)
    {
        n=i;
        for(int j=0;primeList[j]*primeList[j]<=n;j++)
        {
            if(n%primeList[j]==0)
            {
                while(n%primeList[j]==0)
                {
                    arr[i][primeList[j]]++;
                    n/=primeList[j];
                }
            }
        }
        if(n>1)
            arr[i][n]++;
    }

    for(int i=2;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        {
            arr[i][j]+=arr[i-1][j];
        }
    }

    int test;
    int num;

    READ(test);

    for(int i=1;i<=test;i++)
    {
        READ(num);
        printf("Case %d: %d =",i,num);

        for(int j=2;j<100;j++)
        {
            if(arr[num][j]>0)
            {
                if(j==2)
                    printf(" %d (%d)",j,arr[num][j]);
                else
                    printf(" * %d (%d)",j,arr[num][j]);
            }
        }

        printf("\n");
    }
    return 0;
}


