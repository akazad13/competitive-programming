#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define lld long long int

lld temp;

lld Mod_expo(lld n, lld k)
{
    if(k==0)
        return 1ll;
    if(k%2==1)
        return (((n%1000)*(Mod_expo(n,k-1)%1000))%1000);

    temp = Mod_expo(n,k/2)%1000;

    return (temp*temp)%1000;

}

int main()
{
    lld n,k;
    int test;
    double m;
    lld leading, trailing;
    scanf("%d",&test);
    for(int Case=1;Case<=test;Case++)
    {
        scanf("%lld %lld",&n,&k);

        trailing=1;

        m = (double)k*log10(1.0*n);

        m  = m-floor(m);
        leading = pow(10, 2+m);

        trailing  = Mod_expo(n,k);


        printf("Case %d: %lld %03lld\n",Case,leading,trailing);

    }
    return 0;
}
