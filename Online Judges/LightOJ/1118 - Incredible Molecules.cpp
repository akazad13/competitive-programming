#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))
const double eps = 1e-8;


#define PI acos(-1.0)

struct Point
{
	double x, y;
};

int main()
{
    int test,i,j,Case,n,m;
    double x1,x2,y1,y2,r1,r2;
    read(test);
    Point ver[4];
    rep(Case,1,test+1)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);

        double R = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

        if(R+eps>=r1+r2)
        {
            printf("Case %d: 0.0\n",Case);
        }
        else if(R<=(r1-r2)+eps)
        {
            printf("Case %d: %.10f\n",Case,PI*r2*r2);
        }
        else if(R<=(r2-r1)+eps)
        {
            printf("Case %d: %.10f\n",Case,PI*r1*r1);
        }
        else
        {



            double x1 = (R*R+r1*r1-r2*r2)/(2*R*r1);
            double x2 = (R*R-r1*r1+r2*r2)/(2*R*r2);

            double deg1 = acos(x1);
            double deg2 = acos(x2);

            double a = (deg1 * r1*r1);
             a+= (deg2 * r2*r2);

             double area = R*r1*sin(deg1);

            printf("Case %d: %.10f\n",Case,a-area);

        }
    }

    return 0;
}

