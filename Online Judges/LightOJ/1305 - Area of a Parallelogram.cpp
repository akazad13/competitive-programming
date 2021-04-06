#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    int a1,a2,b1,b2,c1,c2,d1,d2;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        cin>>a1>>a2;
        cin>>b1>>b2;
        cin>>c1>>c2;

        d1=a1+c1-b1;
        d2=a2+c2-b2;

        int area = 0.5 *(((a1*b2)+(b1*c2)+(c1*d2)+(d1*a2))-((a2*b1)+(b2*c1)+(c2*d1)+(d2*a1)));

        if(area<0)
            area=area*(-1);

        printf("Case %d: %d %d %d\n",i,d1,d2,area);
    }
    return 0;
}
