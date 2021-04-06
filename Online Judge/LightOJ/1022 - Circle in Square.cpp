#include<stdio.h>
#include<math.h>
int main()
{
    int t,i;
    double r,A_circle,A_cube;

    scanf("%d",&t);
    {
        for(i=1;i<=t;i++)
        {
            scanf("%lf",&r);

            A_cube=4*r*r;
            A_circle=2*acos(0)*r*r;

            printf("Case %d: %.2lf\n",i,A_cube-A_circle);
        }
    }
    return 0;
}
