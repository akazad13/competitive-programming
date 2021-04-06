#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)

int main()
{
    int test,i,j,Case,n,m;
    double a,b,c,d;
    read(test);
    rep(Case,1,test+1)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

        double temp;
        temp = a;
        a = max(a,c);

        if(temp!=a)
            c=temp;

        double x = (d*d-a*a-c*c-b*b+2*a*c)/(2*(c-a));

        double h = sqrt(b*b-x*x);
        double res = 0.5*h*(a+c);

        printf("Case %d: %.10f\n",Case,res);
    }
    return 0;
}
