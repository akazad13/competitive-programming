#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define lREAD(a) scanf("%d",&a)
#define llREAD(a) scanf("%lld",&a)
#define READ(a) scanf("%d",&a)
#define lld long long int


#define MAX 10000100
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

lld num_div(lld n)
{
      lld count=0,res=1;

      for(int i=0;i<Vsize && primeList[i]*primeList[i]<=n;i++)
      {
          count=0;
          if(n%primeList[i]==0)
          {
            while(n%primeList[i]==0)
            {
                count++;
                n/=primeList[i];
            }
          }

          if(primeList[i]!=2)
            res*=(count+1);
      }

      if(n!=1 && n!=2)
        res*=2;
      return res-1;

}

int main()
{
    seive();
    int test;
    lld num;
    lREAD(test);

    for(int Case=1;Case<=test;Case++)
    {
        llREAD(num);
        printf("Case %d: %lld\n",Case,num_div(num));

    }
    return 0;
}
