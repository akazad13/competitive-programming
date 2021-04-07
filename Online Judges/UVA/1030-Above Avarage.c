#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int C,n,grade[1000],i,j,sum;
    float k,avg;

    while(scanf("%d",&C)==1)
    {
        while(C--)
        {
            j=0;
            sum=0;
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%d",&grade[i]);
                sum+=grade[i];
            }
            avg = sum/ n;
            for(i=0;i<n;i++)
            {
                if(grade[i]>avg)
                    j++;
            }
            k = (j/(float) n)*100;
            printf("%.3f%%\n",k);
        }
    }
    return 0;
}
