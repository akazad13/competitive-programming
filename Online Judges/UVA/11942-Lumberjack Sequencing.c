#include<stdio.h>
int main()
{
    int N, a[22], b[22],c[22];
    int i,t,j,k,p,q;
    while(scanf("%d",&N)==1)
    {
        for(k=0;k<N;k++)
        {
            p=1;q=1;
           for(i=0;i<10;i++)
           {
               scanf("%d",&a[i]);
               b[i]=a[i];
               c[i]=a[i];
           }
           if(k==0)
           {
               printf("Lumberjacks:\n");
           }

           for(i=0;i<9;i++)
           {
               for(j=i+1;j<10;j++)
               {
                   if(b[i]>b[j])
                   {
                       t=b[i];
                       b[i]=b[j];
                       b[j]=t;
                   }
                   else
                   {
                       t=c[i];
                       c[i]=c[j];
                       c[j]=t;
                   }
               }
           }

           for(i=0;i<10;i++)
           {
               if(a[i]!=b[i])
               {
                  p=0;
               }
               if(a[i]!=c[i])
               {
                  q=0;
               }
           }

           if(p||q)
           printf("Ordered\n");
           else
            printf("Unordered\n");
        }
    }
    return 0;
}
