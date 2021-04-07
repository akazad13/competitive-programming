#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

bool sieve[18000008];
//int primeFact[10000001];
long int primeList[10000009];

void LPD(long long int n)
{
        long long int  m = -1;
        long long int j=1;
        int counter =0;
        long long int num = n;
        for(int i=2;i<=sqrt(num);i=primeList[j++])
        {
           // cout<<"i = "<<(i*i)<<endl;
            while(n%i==0)
            {
                if(m!=i)
                {
                    counter++;
                }
                m = i;
                n /= i;
            }
        }
        if(n != 1 && counter!= 0)
        {
            m = n;
            counter++;
        }
        if(counter > 1)
        {
            printf("%lld\n",m);
        }
        else
        {
            printf("-1\n");
        }
        return ;
    }



void prime()
{
    int i,j;
    for(i=4;i<=18000000;i+=2)
        sieve[i]=1;
    for(i=3;i<=sqrt(18000000);i+=2)
    {
        if(sieve[i]==0)
        {
            for(j=i*i;j<=18000000;j+=2*i)
            {
                sieve[j]=1;
            }
        }
    }
    sieve[0]=1;
    sieve[1]=1;
}


int main()
{
   // int count=0;
    long long lim=0;
    prime();
    for(long int i=1;i<=18000000;i++)
    {
        if(sieve[i]==0)
        {
            primeList[lim++]=i;
           // count++;
        }

    }
    //cout<<count<<endl;


    long long int num;

    while(scanf("%lld",&num)==1)
    {
        if(num==0)
            break;
         else if(num<0)
            num=-num;
        LPD(num);
    }
    return 0;
}

