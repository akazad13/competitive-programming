#include<stdio.h>
int main()
{
    int n, h[50],i=0,j,k;
    int sum,avg;

    while(scanf("%d",&n)==1)
    {
    	if(n==0)
    	break;
        i++;
        sum=0;
        k=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&h[j]);
            sum+=h[j];
        }
        avg = sum/n;
        for(j=0;j<n;j++)
        {
            if((h[j]-avg)>0)
            {
                k+=(h[j]-avg);
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",i,k);
    }
    return 0;
}
