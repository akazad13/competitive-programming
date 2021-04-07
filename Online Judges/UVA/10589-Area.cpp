#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct CO_Ordinate
{
    double x;
    double y;
};

double dis(CO_Ordinate p1, CO_Ordinate p2)
{
    return sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
}

int main()
{
    int n;
    double a;

    while(cin>>n>>a)
    {
        if(n==0&&a==0)
            break;
        CO_Ordinate Point[5];

        Point[1].x=Point[1].y=0;
        Point[2].x=a;
        Point[2].y=0;
        Point[3].x=0;
        Point[3].y=a;
        Point[4].x=a;
        Point[4].y=a;

        double count=0;

        for(int i=0;i<n;i++)
        {
            cin>>Point[0].x>>Point[0].y;
            if(dis(Point[0],Point[1])<=a&&dis(Point[0],Point[2])<=a&&dis(Point[0],Point[3])<=a&&dis(Point[0],Point[4])<=a)
            {
                count++;
            }
        }

        printf("%.5f\n",((count*a*a)/n));


    }
    return 0;
}
