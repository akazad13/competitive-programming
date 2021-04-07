#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 1000010

bool prime[max];

void sieve()
{
    int i,j;
    for(i=4;i<=max;i+=2)
        prime[i]=1;

    long long int s=sqrt(max);
    for(i=3;i<=s;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=max;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[1]=prime[0]=1;
}

int main()
{
    sieve();

    int num;

    while(cin>>num,num)
    {
        printf("%d:\n",num);
        int flag=1;
        for(int i=num-2;i>=num/2;i-=2)
        {
            if(prime[i]!=0)
            {
                i++;
            }
            else
            {
                if(prime[num-i]==0)
                {
                    printf("%d+%d\n",num-i,i);
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("NO WAY!\n");
        }
    }

    return 0;

}
