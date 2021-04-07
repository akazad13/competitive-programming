#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

bool prime[1060];
int primelist[190];

void sieve()
{
    for(int i=4;i<1050;i+=2)
        prime[i]=1;
    for(int i=3;i<=sqrt(1050);i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<1050;j+=2*i)
                prime[j]=1;
        }
    }
}

int main()
{
    sieve();

    int i,j=1,N,C,count,k,Total;

    for(i=1;i<1050;i++)
    {
        if(prime[i]==0)
        {
            primelist[j++]=i;
        }
    }

    while(cin>>N>>C)
    {
        count=0;
        k=1;
        for(i=1;primelist[i]<=N;i++)
        {
            count++;
        }
        cout<<N<<" "<<C<<":";
        if(count%2==0)
        {
             Total=2*C;
        }
        else if(count%2==1)
        {
             Total=2*C-1;
        }
        if(Total>=count)
        {
            for(i=1;primelist[i]<=N;i++)
                cout<<" "<<primelist[i];
        }
        else if(count%2==0)
        {
            j=(count/2)-(C-1);

            for(i=j;k<=Total;i++)
            {
                cout<<" "<<primelist[i];
                k++;
            }
        }

        else
        {
            j=((count/2)+1)-(C-1);
            for(i=j;k<=Total;i++)
            {
                cout<<" "<<primelist[i];
                k++;
            }
        }
        cout<<"\n\n";
    }

    return 0;
}
