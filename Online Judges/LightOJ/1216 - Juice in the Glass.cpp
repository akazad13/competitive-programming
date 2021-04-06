#include<iostream>
#include<bits/stdc++.h>

#define PI acos(-1.0)

using namespace std;

int main()
{
    double r1,r2,h,p;

    int test;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>r1>>r2>>h>>p;

        double R, v;

        R  = (r2*h + p*(r1-r2))/h;

        v= (PI*p*(R*R+R*r2+r2*r2))/3.0;

        printf("Case %d: %.9f\n",i,v);
    }
    return 0;
}
