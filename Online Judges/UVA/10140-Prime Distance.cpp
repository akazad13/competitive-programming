#include<iostream>
#include<bits/stdc++.h>

#define max2 10000000
#define lld long long int

bool prime[10000010];


using namespace std;


void seive()
{
    for(int i=4;i<=max2;i+=2)
        prime[i]=1;
    for(int i=3;i<=sqrt(max2);i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=max2;j=j+2*i)
                prime[j]=1;
        }
    }

    prime[0]=prime[1]=1;

}

unsigned int first(int lo,int i)
{
    if(lo%i==0)
            return (unsigned int)max(lo,i*i);
    else
        return (unsigned int)max(lo + (i-lo%i),i*i);
}

int main()
{
    //freopen("10140.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    seive();

    lld up, low;

    while(cin>>low>>up)
    {

        bool Exprime[1000010]={0};

        if(low==1)
        {
            Exprime[low]=1;
        }

        for(lld k=first(low,2);k>=low&&k<=up;k=k+2)
            Exprime[k-low+1]=1;

        int max1 = sqrt(up);
        for(int j=3;j<=max1;j+=2)
        {
            if(prime[j]==0)
            {
                for(lld k=first(low,j);k>=low&&k<=up;k=k+j)
                    Exprime[k-low+1]=1;
            }

        }
        //cout<<1<<endl;



        int close=100000;
        int longest = -1;

        lld close1,close2,long1,long2;
        lld primeList[100000];

        int j=0;

        for(lld i=low;i<=up;i++)
        {
            if(Exprime[i-low+1]==0)
                {
                    primeList[j++]=i;
                }

        }

        int diff=0;

        for(int i=0;i<j-1;i++)
        {
            diff= primeList[i+1]-primeList[i];

            if(diff>longest)
            {
                longest=diff;
                long1=primeList[i];
                long2=primeList[i+1];

            }

            if(diff<close)
            {
                close=diff;
                close1=primeList[i];
                close2=primeList[i+1];
            }
        }

        if(diff==0)
            printf("There are no adjacent primes.\n");
        else
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",close1,close2,long1,long2);


    }

    return 0;
}
