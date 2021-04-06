#include<iostream>
#include<bits/stdc++.h>

#define PI acos(-1.0)

using namespace std;

int main()
{
    int test;
    double R, n;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>R>>n;
        double res= (R*sin(PI/n))/(1.0+sin(PI/n));
        printf("Case %d: %.10f\n",i,res);
    }

    return 0;
}
