#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>

using namespace std;


int k;

bool prime[5000020];

int primeList[600000];

bool DePrime[5000020];




void sieve()
{
    int sq=sqrt(5000000);

    for(int i=4;i<=5000000;i+=2)
    {
        prime[i]=1;
    }


    for(int i=3;i<=sq;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=5000000;j+=(2*i))
            {
                prime[j]=1;
            }
        }
    }

    prime[0]=prime[1]=1;

    primeList[0]=2;
    DePrime[2]=1;
    k=1;
    for(int i=3;i<=5000000;i+=2)
    {
        if(prime[i]==0)
        {
            primeList[k++]=i;
            DePrime[i]=1;
        }
    }

}


void DEPrime()
{
    int temp,j;
    int sum;

    for(int i=2;i<=5000000;i++)
    {
        if(DePrime[i]==1)
        {
                continue;
        }

        temp=i;
        j=0;
        sum=0;
        int flag=1;

        int sq=sqrt(temp);

        while(primeList[j]<=sq&&prime[temp]!=0)
        {

            if(temp%primeList[j]==0)
            {
                if(flag)
                    sum+=primeList[j];
                //cout<<"sum: "<<sum<<"  i: "<<i<<endl;
                temp/=primeList[j];
                flag=0;
            }
            else
            {
                j++;
                flag=1;
            }
        }
         //cout<<"sum: "<<sum<<"  i: "<<i<<endl;



        if(prime[temp]==0&&temp!=primeList[j])
            sum+=temp;

        // cout<<"sum: "<<sum<<"  i: "<<i<<endl;


        if(prime[sum]==0)
            DePrime[i]=1;

    }
}



int main()
{

    sieve();
    DEPrime();

    int low,up;

    while(cin>>low)
    {
        if(low==0)
            break;
        cin>>up;
        if(low>up)
            swap(low,up);
        int count=0;

        for(int i=low;i<=up;i++)
        {
            if(DePrime[i]==1)
            {
                //cout<<i<<endl;
                count++;
            }
        }

        cout<<count<<"\n";
    }

    return 0;


}
