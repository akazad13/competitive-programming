//http://www.devskill.com/CodingProblems/ViewProblem/78

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define lld long long


template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

lld F[82];

void fib()
{
    F[0]=1;
    F[1]=1;

    for(int i=2;i<=80;i++)
    {
        F[i] = F[i-1]+F[i-2];
    }
    return ;
}

int solve(int n, lld p)
{
    if(n==0 || n==1)
    {
        return n;
    }

    int ret;

    if(p<=F[n-2]) //Left
    {
        ret = solve(n-2,p);
    }
    else
    {
        ret = solve(n-1,p-F[n-2]);
    }

    return ret;
}

int main()
{


    int test,n;
    lld m;
    fib();
    read(test);

    for(int Case=1;Case<=test;Case++)
    {
        printf("Case %d: ",Case);
        read(n); read(m);

        int ret = solve(n,m);

        if(ret==0)
            printf("a\n");
        else
            printf("b\n");
    }

    return 0;
}



