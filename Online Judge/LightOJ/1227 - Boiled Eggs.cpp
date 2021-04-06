#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int test,i,j,count,sum;
    int arr[100];

    scanf("%d",&test);

    int n,p,q;

    for(i=1;i<=test;i++)
    {
        scanf("%d %d %d",&n,&p,&q);
        count=0;
        sum=0;

        for(j=0;j<n;j++)
            scanf("%d",&arr[j]);

         for(j=0;j<n;j++)
         {
             sum+=arr[j];
             if(sum<=q&&count<p)
             {
                 count++;
             }
         }

         printf("Case %d: %d\n",i,count);
    }

    return 0;
}

