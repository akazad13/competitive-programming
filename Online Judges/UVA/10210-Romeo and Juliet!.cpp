#include<iostream>
#include<cstdio>
#include<cmath>

#define PI acos(-1.0)

using namespace std;

int main(){

    double x1,x2,y1,y2,theta,alpha,dis,result;

    while(cin>>x1>>y1>>x2>>y2>>theta>>alpha){
        dis=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
        result=dis*((1/tan(theta*PI/180))+(1/tan(alpha*PI/180)));

        printf("%.3lf\n",result);
    }


    return 0;


}
