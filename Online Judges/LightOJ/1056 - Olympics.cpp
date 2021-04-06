#include<iostream>
#include<bits/stdc++.h>

using  namespace std;

double len,width;

void bin_search(double a, double b)
{
    double mid,low,up,res;
    low = 0.0;
    up = 400.0;

    while(low<up)
    {

        mid = (low+up)/2.0;
        res = mid*(2*a + 2*sqrt(a*a+b*b)*atan(b/a*1.0));

        if(fabs(res-400.0)<.00000001 && fabs(res-400.0)>=0.0)
        {
            len = a*mid;
            width = b*mid;
            return ;
        }

        else if(res>400)
            up = mid;
        else
            low = mid;
    }
}

int main()
{
    int test;
    double a,b;
    cin>>test;

    for(int Case = 1; Case<=test ; Case++)
    {
        scanf("%lf : %lf",&a,&b);
        bin_search(a,b);
        printf("Case %d: %.10f %.10f\n",Case,len,width);

    }
    return 0;
}
