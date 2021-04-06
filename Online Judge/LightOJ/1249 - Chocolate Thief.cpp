#include<stdio.h>

struct Stdata
{
    int length, width, height;
    long int volume;
    char Name[20];
};

int main()
{
    struct Stdata FindTheif[100],temp;
    int t,n,i,j,k;
    scanf("%d",&t);
    {
        for(j=1;j<=t;j++)
        {
            scanf("%d",&n);

            for(i=0;i<n;i++)
             {
                scanf("%s %d %d %d",FindTheif[i].Name,&FindTheif[i].length,&FindTheif[i].width,&FindTheif[i].height);

                FindTheif[i].volume= FindTheif[i].length*FindTheif[i].width*FindTheif[i].height;
             }

             for(i=0;i<n-1;i++)
             {
                 for(k=i+1;k<n;k++)
                 {
                     if(FindTheif[i].volume>FindTheif[k].volume)
                     {
                         temp=FindTheif[i];
                         FindTheif[i]=FindTheif[k];
                         FindTheif[k]=temp;
                     }
                 }
             }
             if(FindTheif[0].volume==FindTheif[n-1].volume)
                printf("Case %d: no thief\n",j);
             else
             {
                 printf("Case %d: %s took chocolate from %s\n",j,FindTheif[n-1].Name,FindTheif[0].Name);
             }
        }
    }
    return 0;
}
