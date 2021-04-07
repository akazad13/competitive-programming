#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

bool sieve[1000010];
int primeFact[1000050];
int primeList[80000];

int fact(int n)
{
    int count=0,m=n;
    int j=0,i;
    for(i=2;i<=m;i=primeList[j])
    {
        if(n<i)
            break;
        if(sieve[n]==0)
        {
            count++;
            break;
        }
        while(n>0&&n%i==0)
        {
            n=n/i;
            count++;
        }

        j++;
    }
    return count;
}

void prime()
{
    int i,j;
    for(i=4;i<=1000005;i+=2)
        sieve[i]=1;
    for(i=3;i<=sqrt(1000005);i+=2)
    {
        if(sieve[i]==0)
        {
            for(j=i*i;j<=1000005;j+=2*i)
            {
                sieve[j]=1;
            }
        }
    }
    sieve[1]=1;
}


int main()
{
   // freopen("test.txt","w",stdout);
    prime();
    int j=0;
    for(int i=1;i<=1000005;i++)
    {
        if(sieve[i]==0)
        {
            primeList[j++]=i;
        }

    }

    primeFact[1]=0;

    for(long int n=2;n<=1000000;n++)
    {
        primeFact[n]=primeFact[n-1]+fact(n);
    }

    long long int num;

    while(cin>>num)
    {
        cout<<primeFact[num]<<endl;
    }
    return 0;
}
