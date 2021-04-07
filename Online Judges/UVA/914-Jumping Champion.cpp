#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool prime[1000222];

int primeList[80000];

bool comp(int x,int y)
{
    return x>y;
}

void sieve()
{
    int i,j;
    for(i=4;i<=1000200;i+=2)
        prime[i]=1;
    for(i=3;i<=sqrt(1000200);i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=1000200;j+=2*i)
                prime[j]=1;
        }
    }

}


int main()
{

    sieve();
    int i,j=0;

    primeList[j++]=2;
    for(i=3;i<=1000200;i+=2)
    {
        if(prime[i]==0)
            primeList[j++]=i;
    }
    int test;
    long long int up,low;
    cin>>test;
    while(test--)
    {
        int arr1[120]={0};
        int arr2[120];


        j=0;
        cin>>low>>up;
        while(primeList[j]<low)
        {
            j++;
        }
        j++;
        while(primeList[j]<=up)
        {

            arr1[(primeList[j] - primeList[j-1])]++;
                j++;
        }
        for(i=0;i<120;i++)
            arr2[i]=arr1[i];

       sort(arr1,arr1+115,comp);

       if(arr1[0]!=arr1[1])
       {
           for(i=0;i<115;i++)
           {
               if(arr1[0]==arr2[i])
               {
                   printf("The jumping champion is %d\n",i);
                   break;
               }
           }

       }

       else
       {
           printf("No jumping champion\n");
       }

    }
    return 0;
}
