#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double bin_search(double p, double q, double r, double s, double t,double u)
{
    double low,up,mid,res;
    low = 0;
    up  = 1.0;

    while(low<up)
    {

        mid = (low+up)/2.0;

        res  = p*exp(-1*mid)+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*mid*mid+u;
        if(res<.000001 && res>=0)
            return mid;
        else if(res>0.0)
            low=mid;
        else
            up = mid;
    }

    return -1;
}


int main()
{
    double p,q,r,s,t,u;
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        double res = bin_search(p,q,r,s,t,u);

        if(res!=-1)
            printf("%.4f\n",res);
        else
            printf("No solution\n");
    }

    return 0;

}
