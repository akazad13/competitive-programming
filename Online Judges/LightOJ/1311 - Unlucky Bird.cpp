#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>

#define lld long long int
#define ulld unsigned long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

int main()
{
    int test;
    double v1,v2,v3,a1,a2,t1,t2,t,d,Bdis;
    read(test);

    for(int Case = 1; Case<=test; Case++)
    {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);

        d = ((v1*v1)/(2.0*a1))+((v2*v2)/(2.0*a2));

        t1 = v1/(a1*1.0);
        t2 = v2/(a2*1.0);
        t  = max(t1,t2);

        Bdis = t*v3;
        printf("Case %d: %.10f %.10f\n",Case,d,Bdis);
    }
    return 0;

}


