#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

bool sieve[1000010];
int DP[1000010];


int DigitSum(int n)
{
    int  sum=0;

    while(n!=0)
    {
        sum=sum+n%10;
        n=n/10;
    }

    return sum;
}

void prime()
{
    int i,j;
    for(i=4;i<=1000000;i+=2)
        sieve[i]=1;
    for(i=3;i<=1000;i+=2)
    {
        if(sieve[i]==0)
        {
            for(j=i*i;j<=1000000;j+=2*i)
            {
                sieve[j]=1;
            }
        }
    }
    sieve[1]=1;
}

int main()
{
    prime();
    int i,N,up,low,count=0,sum=0;
    for(i=0;i<1000000;i++)
        DP[i]=0;


    for(i=2;i<=1000000;i++)
    {
        if(sieve[i]==0&&sieve[DigitSum(i)]==0)
        {
            DP[i]=1+DP[i-1];
        }
        else
        {
            DP[i]=DP[i-1];
        }


    }



    cin>>N;

    while(N--)
    {
        cin>>low>>up;


        cout<<DP[up]-DP[low-1]<<endl;
    }

    return 0;
}
