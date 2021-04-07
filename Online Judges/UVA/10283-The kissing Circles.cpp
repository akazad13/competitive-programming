#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    double R, n, blue, green,r,alpha;

    double PI;

    PI= 2*acos(0.0);

    while(cin>>R>>n)
    {
        if(n<2){
            printf("%.10f %.10f %.10f\n",R,0.0,0.0);
        }
        else{
            r= (R*sin(PI/n))/(1.0+sin(PI/n));
            alpha= (PI/2)-(PI/n);
            double Small_cir_area= PI*r*r*n;

            double a1= alpha*r*r;

            double tringle= sqrt(R*r*r*(R-2*r));

            blue= n*(tringle-a1);
            green=(PI*R*R)- Small_cir_area- blue;

            printf("%.10f %.10f %.10f\n",r,blue,green);
        }
    }

    return 0;
}

/*

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    double R, n, blue, green,r,alpha;

    double PI;

    PI= 2*acos(0.0);

    while(cin>>R>>n)
    {
        if(n<2){
            printf("%.10f %.10f %.10f\n",R,0.0,0.0);
            continue;
        }
            r= (R*sin(PI/n))/(1.0+sin(PI/n));
            alpha= (PI/2)-(PI/n);
            double Small_cir_area= PI*r*r*n;

            double a1= alpha*r*r*0.5;

            double l= sqrt(((R-r)*(R-r))-r*r);

            double tringle= 0.5*l*r;

            blue= 2*n*(tringle-a1);
            green=(PI*R*R)- Small_cir_area- blue;

           printf("%.10f %.10f %.10f\n",r,blue,green);
    }

    return 0;
}

*/
