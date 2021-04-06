#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    double n;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%lf",&n);
        unsigned long long int res = (n/2.0)*(2+(n-1)*4);
        printf("%llu\n",++res);
    }

    return 0;
}
