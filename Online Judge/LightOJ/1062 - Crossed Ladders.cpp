#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double bin_search(double x, double y, double c)
{
    double low,up,mid,res;
    low = 0;
    up  = min(x,y);

    while(low<up)
    {

        mid = (low+up)/2.0;
        res  = (sqrt((x*x)-(mid*mid))*sqrt((y*y)-(mid*mid)))/(sqrt((x*x)-(mid*mid))+sqrt((y*y)-(mid*mid)));
        if(fabs(res-c)<.00000001)
            return mid;
        else if(res>c)
            low=mid;
        else
            up = mid;
    }
}


int main()
{
    double x,y,c;
    int test;
    cin>>test;

    for(int Case = 1; Case<=test ; Case++)
    {
        scanf("%lf %lf %lf",&x,&y,&c);
        printf("Case %d: %.10f\n",Case,bin_search(x,y,c));
    }
    return 0;
}

