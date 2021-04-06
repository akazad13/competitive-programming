#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int bin(int n)
{
    long long int b=0,c=0,p=1;
    while(n>0)
   {
     if(n%2==1)
        {
            for(int k=1;k<=c;k++)
                p=p*10;

            b=b+p;
        }
        p=1;
        c++;
        n=n/2;
    }
    return b;
}

int main()
{
    long long int a,b,c,d;
    long long int m,n,o,p;

    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        long long int num1,num2,num3,num4;
        scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
        scanf("%lld.%lld.%lld.%lld",&m,&n,&o,&p);

        num1=bin(a);
        num2=bin(b);
        num3=bin(c);
        num4=bin(d);
        if(num1==m&&num2==n&&num3==o&&num4==p)
            cout<<"Case "<<i<<": Yes\n";
        else
            cout<<"Case "<<i<<": No\n";
    }
    return 0;
}
