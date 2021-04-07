#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    double R1,R2,R3;

    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>R1>>R2>>R3;

        double a=R1+R2;
        double b=R1+R3;
        double c=R2+R3;

        double s=(a+b+c)/2.0;

       // cout<<s<<endl;

        double tri = sqrt(s*(s-a)*(s-b)*(s-c));

        double C=acos(((a*a)+(b*b)-(c*c))/(2*a*b));
        double B=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
        double A=acos(((c*c)+(b*b)-(a*a))/(2*c*b));

       // cout<<tri<<endl;

        //cout<<C<<" "<<B<<" "<<A<<endl;

        double res= tri-((.5*R1*R1*C)+(.5*R2*R2*B)+(.5*R3*R3*A));



        printf("%.6f\n",res);
    }

    return 0;
}

