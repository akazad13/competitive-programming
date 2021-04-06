#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define Clear(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
/***********************************/

int main()
{
    int test,i,j,Case;
    double l,n,c;
    read(test);
    rep(Case,1,test+1)
    {
        scanf("%lf %lf %lf",&l,&n,&c);

        double L  = (1+n*c)*l;

        double low = 0;
        double high = PI/2.0;

        double mid;

        while(high-low>0.0000000001)
        {
            mid = (low+high)/2.0;

            double p = mid*l;
            if(p-L*sin(mid)<0)
                low = mid;
            else
                high = mid;
        }
        double R = L/(2.0*mid);
        R-= (R*cos(mid));

        printf("Case %d: %.10f\n",Case,R);
    }
    return 0;
}

