

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>

#define lld long long int
#define ulld unsigned long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

//End Macros

#define MAX 100010
bool prime[MAX+10];
vector<int>primeList;
vector<lld> p;
int Vsize;

bool check(lld mask, int i)
{
    return (mask&(1ll<<i));
}

lld cnt;
int n;

lld cal(lld mask)
{
    cnt=0;
    lld lcm=1;
    //cout<<mask<<endl;
    for(int i=0;i<n;i++)
    {
        //cout<<check(mask,i)<<endl;
        if(check(mask,i))
        {
            cnt++;
            lcm= ((lcm*p[i])/__gcd(lcm,p[i]));
          // cout<<mask<<" "<<lcm<<endl;
        }
    }

    if(cnt%2)
        return lcm;
    else
        return -1*lcm;

}

void sieve()
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

    //cout<<"seive OK"<<endl;
}


void Find(int n)
{
    if(n<100000)
    {
        if(prime[n]==0)
        {
            p.push_back(n);
            return ;
        }
    }
    for(int i=0;i<Vsize && primeList[i]*primeList[i]<=n;i++)
    {
        if(n%primeList[i]==0 && n!=1)
        {
            p.push_back(primeList[i]);
            while(n%primeList[i]==0 && n!=1)
                n/=primeList[i];
        }

        if(n<=1)
            break;

        if(n<100000)
        {
            if(prime[n]==0)
            {p.push_back(n);
                n=1;
                break;
            }
        }
    }

    if(n>1)
        p.push_back(n);
    return ;
}


int main()
{
     sieve();
    lld num,res=0,k;

    int test;
    scanf("%d",&test);
    for(int Case = 1;Case<=test;Case++)
    {
        lld res1=0;
        lld res2=0;
        p.clear();
        scanf("%lld %lld",&num,&k);
        Find(num);

        n = p.size();

        for(lld i=1;i<(1ll<<(n));i++){

            lld ret  = cal(i);
            res1+= (num/ret);
            res2+=(num*k)/ret;
       // cout<<res<<endl;
    }

   // cout<<res1<<" "<<res2<<endl;

    printf("%lld\n",((num*k)-res2)-(num-res1));

    }

    return 0;
}

