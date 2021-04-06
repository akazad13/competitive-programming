#include<stdio.h>
int main()
{
    int t,n,i,j,Total;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        Total=0;
        scanf("%d",&n);
        int dust[n];
        for(j=0;j<n;j++)
        {
            scanf("%d",&dust[j]);
            if(dust[j]>0)
            Total+=dust[j];
        }
        printf("Case %d: %d\n",i,Total);
    }
    return 0;
}
