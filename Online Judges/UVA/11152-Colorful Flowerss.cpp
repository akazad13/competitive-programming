#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, c;
    double sun, voilet, rose, s, rIn, rOut, p, TotalTri;
    const double pi = 2* acos(0);
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        s = (a+b+c)/2.0;
        p = s*(s-a)*(s-b)*(s-c);
        TotalTri = sqrt(p);
        rIn = TotalTri/s;
        rose = pi * pow(rIn,2);
        voilet = TotalTri - rose;
        rOut = (a*b*c)/(4*TotalTri);
        sun = (pi * pow(rOut,2))- TotalTri;
        printf("%.4f %.4f %.4f\n",sun,voilet,rose);
    }
    return 0;
}
