#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define PI acos(-1.0)
int main()
{


    double length, height, width,degree,volume,q;

    while(cin>>length>>width>>height>>degree)
    {
        degree=degree*(PI/180.0);
        q=length*sqrt((1.0/(cos(degree)*cos(degree)))-1.0);

        if(q<=height){
            volume= width*((length*height)-(0.5*length*q));
        }

        else{
            degree=(90.0*(PI/180.0))-degree;
            volume=width*0.5*height*height*sqrt((1.0/(cos(degree)*cos(degree)))-1.0);
        }

        printf("%0.3lf mL\n",volume);
    }

    return 0;
}
