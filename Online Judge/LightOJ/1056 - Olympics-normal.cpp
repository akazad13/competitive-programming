#include<iostream>
#include<bits/stdc++.h>

using  namespace std;

int main()
{
    int test;
    double a,b,x;
    cin>>test;

    for(int Case = 1; Case<=test ; Case++)
    {
        scanf("%lf : %lf",&a,&b);
        x = 400.0/(2*(a+sqrt(a*a+b*b)*atan(b/a*1.0)));
        printf("Case %d: %.10f %.10f\n",Case,a*x,b*x);
    }
    return 0;
}

