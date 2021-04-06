#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define CLEAR(a,b) memset(a,b,sizeof(a))

#define lld long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}


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

        res*=(2*count+1);
      }

      if(n!=1)
        res*=(2+1);
      return ((res+1)/2);

}
int main()
{
    seive();
    int test;
    lld num;
    read(test);

    for(int Case=1;Case<=test;Case++)
    {
        read(num);
        printf("Case %d: %lld\n",Case,num_div(num));

    }
    return 0;
}


