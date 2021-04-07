#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    double fib[51];
    int n;
    fib[1]=1;
    fib[2]=2;
    for(int i=3;i<=50;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    while(cin>>n,n)
    {

        printf("%.0f\n",fib[n]);
    }

    return 0;
}
