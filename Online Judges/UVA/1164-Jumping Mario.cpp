#include<stdio.h>
int main()
{
     short int T,N,high,low,i,j;
     int hight[52];
     while(scanf("%hd",&T)==1)
     {
         for(i=1;i<=T;i++)
         {
            high=0;
            low=0;
            scanf("%hd",&N);
            for(j=0;j<N;j++)
            {
                scanf("%d",&hight[j]);
            }
            if(N>1)
            {
                for(j=0;j<N-1;j++)
                {
                    if(hight[j]<hight[j+1])
                        high++;
                    else if(hight[j]>hight[j+1])
                        low++;
                }
             }
            printf("Case %hd: %hd %hd\n",i,high,low);
         }
     }
}
