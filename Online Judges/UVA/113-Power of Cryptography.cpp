#include<bits/stdc++.h>

using namespace std;

int main()
{
    double n,p,x;

    while(cin>>n>>p)
    {
        x=(log(p)/n);

        printf("%.0f\n",exp(x));
    }

    return 0;
}
