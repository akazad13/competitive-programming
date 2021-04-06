#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)

double bin_search(double l,double w)
{
    double lower = 0;
    double upper = w/2.0-.0001;
    double mid1,mid2,vol1,vol2,temp=0.0;


    while(lower<upper)
    {
        mid1 = (2*lower+upper)/3.0;
        mid2 = (2*upper+lower)/3.0;

        vol1 = (l-2.0*mid1)*(w-2.0*mid1)*mid1;
        vol2 = (l-2.0*mid2)*(w-2.0*mid2)*mid2;

        if(fabs(vol1-vol2)<.00000001)
            return vol1;
        else if(vol1>0 && vol1<temp)
            lower=mid1;
        else
            upper=mid2;
        printf("%f\n",vol1);

    }
}


int main()
{
    int test;
    double l,w;
    read(test);

    for(int Case = 1;Case<=test;Case++)
    {
        scanf("%lf %lf",&l,&w);

        double ret = bin_search(l,w);
        cout<<ret<<endl;
    }
    return 0;

}





