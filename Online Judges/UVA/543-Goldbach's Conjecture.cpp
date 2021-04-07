#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

bool sieve[1000006];
//int primeFact[1000050];
//int primeList[80000];




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
    //long int count=0;
    int num,i;
    /*int j=0;
    for(int i=1;i<=1000000;i++)
    {
        if(sieve[i]==0)
        {
            primeList[j++]=i;
        }

    }*/

    while(cin>>num,num)
    {
        for(i=2;i<num/2+1;i++)
        {
            if(sieve[i]==0&&sieve[num-i]==0)
            {
                cout<<num<<" = "<<i<<" + "<<(num-i)<<endl;
                break;
            }
        }
    }
    return 0;

}
