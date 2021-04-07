#include<stdio.h>
#include<math.h>
int main()
{
    int h,m;
    double diff_deg,H_deg,M_deg;
    while(scanf("%d:%d",&h,&m)==2)
    {
        if(h==0 && m==00)
            break;
        H_deg=h*30 + m*0.5;
        M_deg=m*6;
        diff_deg= fabs(H_deg - M_deg);
        if(diff_deg>180)
            diff_deg=360-diff_deg;
        printf("%.3lf\n",diff_deg);
    }
    return 0;
}
