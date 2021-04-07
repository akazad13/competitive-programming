#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{

    double m,n,r,t,d;

    while(cin>>t)
    {
        while(t--)
        {cin>>m>>n>>r;

        d=sqrt((m*m)+(n*n));

        printf("%.2lf %.2lf\n",r-d,r+d);
        }


    }

    return 0;
}

