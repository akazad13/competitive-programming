#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

bool sieve[1000006];

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
    int num,i;
    while(cin>>num,num)
    {
        int count=0;
        for(i=2;i<num/2+1;i++)
        {
            if(sieve[i]==0&&sieve[num-i]==0)
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;

}


