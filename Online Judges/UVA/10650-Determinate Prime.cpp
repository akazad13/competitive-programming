#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool prime[32020];

int primeList[3450];

void sieve()
{
    int i,j;

    for(i=4;i<=32000;i+=2)
    {
        prime[i]=1;
    }

    for(i=3;i<=sqrt(32000);i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=32000;j+=2*i)
            {
                prime[j]=1;
            }
        }

    prime[1]=1;

    }
}

int main()
{
    
    int k;
    vector<int>v;
    sieve();

    int j=0;

    for(int i=1;i<=32000;i++)
    {
        if(prime[i]==0)
            primeList[j++]=i;
    }
    //cout<<j<<endl;
    int count=0;
    for(int i=0;i<j;i++)
    {
        int temp=primeList[i+1]-primeList[i];
        if(temp==(primeList[i+2]-primeList[i+1]))
           {
               //cout<<" I : " <<i<<"  prime: "<<primeList[i]<<endl;
               for(k=i;k<=i+2;k++)
                    v.push_back(primeList[k]);
               for(k=i+3;;k++)
               {
                   if((primeList[k]-primeList[k-1])==temp)
                        v.push_back(primeList[k]);
                   else
                    break;
               }

               count++;

               i=k;
           }
    }

   
    cout<<"count: "<<count<<endl;
    int low, up;

  
}
