#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define max 10000010

bool prime[max];

int DP[10010];


void sieve()
{
    int i,j;
    for(i=4;i<max-1;i+=2)
        prime[i]=1;

    long long int s=sqrt(max-1);
    for(i=3;i<=s;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<max-1;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[1]=prime[0]=1;
}

bool isprime(long long int n)
{
    if(n%2==0)
        return 0;
    for(int i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
   // freopen("10200.txt","w",stdout);
    sieve();

    DP[0]=1;

    for(int i=1;i<=10000;i++)
    {
        long long int n= (i*i)+i+41;
        //cout<<"i: "<<i<<"  n : "<<n<<endl;
        if(n<max-10)
        {
            if(prime[n]==0)
            {
                DP[i]=DP[i-1]+1;
            }
            else
                DP[i]=DP[i-1];
        }
        else
        {
            if(isprime(n)==1)
            {
                 DP[i]=DP[i-1]+1;
            }
            else
                DP[i]=DP[i-1];
        }
    }

    //cout<<DP[9998]<<" "<<DP[9999]<<endl;


    int low,up;

    while(cin>>low>>up)
    {
        int diff= up-low+1;
        int l;
        if(low==0)
        {
            l= 0;
        }
        else
        {
            l=DP[low-1];
        }

        double res  = (100*(double)(DP[up]-l))/((double)(diff));

        printf("%0.2f\n",res+1e-7);
    }

    return 0;
}

