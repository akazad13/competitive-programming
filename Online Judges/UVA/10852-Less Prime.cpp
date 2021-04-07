#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool prime[10020];

void sieve()
{
    int i,j;

    for(i=4;i<=10015;i+=2)
    {
        prime[i]=1;
    }

    for(i=3;i<=sqrt(10015);i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=10015;j+=2*i)
            {
                prime[j]=1;
            }
    }

    prime[1]=1;

}
}

int main()
{
    sieve();
    int i;
    int num,test;
    cin>>test;
    while(test--)
    {
        cin>>num;
        num=num/2;
        for(i=num+1;;i++)
        {
            if(prime[i]==0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
