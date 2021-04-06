#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    double AB,BC,AC,ratio;

    int test;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>AB>>AC>>BC>>ratio;

        double res=AB*sqrt((ratio/(1+ratio)));

        printf("Case %d: %lf\n",i,res);
    }
    return 0;
}
