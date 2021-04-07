#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define R 6440
using namespace std;

int main()
{
    double distance, degree;
    char ch[4];

    while(cin>>distance>>degree>>ch)
    {

        if(strcmp(ch,"min")==0)
        {
            degree= degree/60;
        }
        if(degree>180)
            degree=360-degree;
        printf("%.6lf ",(R+distance)*((degree*acos(-1))/180));
        printf("%.6lf\n",sqrt(((2*(R+distance)*(R+distance))*(1-cos(degree*acos(-1)/180)))));
    }

    return 0;
}
