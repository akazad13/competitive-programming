#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

bool seive[20000009];

long int list1[150000];

int main()
{
    long int pos;

    //bool seive[2000000];
    long int N=20000000;
    long int sq,i,j;

    sq=sqrt(N);

    seive[1]=1;


    for(i=4;i<=N;i=i+2)
    {
        seive[i]=1;
    }

    for(i=3;i<=sq;i=i+2)
    {

        if(seive[i]==0)
        {
            for(j=i*i;j<=N;j+=i)
            {
                seive[j]=1;
            }
        }
    }
    j=1;
    for(i=1;i<=N;i++)
    {
        if(seive[i]==0&&seive[i+2]==0)
        {
            list1[j++]=i;
        }
    }

    while(cin>>pos)
    {


        printf("(%ld, %ld)\n",list1[pos],list1[pos]+2);
    }


    return 0;
}

