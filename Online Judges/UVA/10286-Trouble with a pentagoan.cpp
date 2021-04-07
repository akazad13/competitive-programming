#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
    double r,a;

    double PI=2*acos(0.0);

    //cout<<PI<<endl;

    while(cin>>r)
    {
        a=(sin(108*PI/180)/sin(63*PI/180))*r;

        printf("%.10f\n",a);
    }

    return 0;
}
