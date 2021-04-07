//submitted
#include<iostream>
#include<cstdio>
#include<math.h>

using namespace std;

int main()
{
    //freopen("D:\\Programing code\\ONLINE\\doc\\12578.txt","r",stdin);
    int t;
    double length, width,radius,area_red,area_green;

    while(cin>>t)
    {
        while(t--)
        {
            cin>>length;
            radius=length/5;
            width=(length*3)/5;
            area_red=2*acos(0.0)*radius*radius;
            //printf("%f\n",area_red);
            area_green=(length*width)-area_red;

            printf("%.2lf %.2lf\n",area_red,area_green);
        }
    }
    return 0;
}
