#include<iostream>
#include<bits/stdc++.h>

#define PI acos(-1.0)

using namespace std;

int main()
{
    int test;

    double A1,A2,B1,B2,O1,O2;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>O1>>O2;
        cin>>A1>>A2;
        cin>>B1>>B2;

        double OA=sqrt((O1-A1)*(O1-A1)+(O2-A2)*(O2-A2));
        double AB=sqrt((A1-B1)*(A1-B1)+(A2-B2)*(A2-B2));

        double deg = acos(((2.0*OA*OA)-(AB*AB))/(2*OA*OA));
        double ARC;

        ARC = OA*deg;

        printf("Case %d: %.10f\n",i,ARC);
    }

    return 0;

}
