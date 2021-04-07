#include<stdio.h>
int main()
{
    int N, a[1000];
    int i,j,k,temp;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        k=0;
        for(i=0;i<N-1;i++)
        {
            for(j=0;j<N-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    k++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",k);
    }
    return 0;
}
