#include<iostream>
#include<bits/stdc++.h>

#define PI acos(-1.0)

using namespace std;

int main()
{
    int a,b,v,deg,t;
    double h,V;

    while(cin>>a>>b)
    {
        cin>>v>>deg>>t;
        if(!a&&!b&&!v&&!deg&&!t)
            break;


        h= (a+v*t*cos(deg*PI/180.0))/(2*a);

        V= (b+v*t*sin(deg*PI/180.0))/(2*b);



        printf("%.0f %.0f\n",floor(h),floor(V));
    }

    return 0;
}
