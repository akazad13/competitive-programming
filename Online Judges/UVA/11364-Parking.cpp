#include<stdio.h>

int main()
{
    int test,n,data,i,l,m;

    scanf("%d",&test);

    while(test--)
    {
        l=0;m=500;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&data);
            if(data>l)
                l=data;
            if(data<m)
                m=data;

        }

        printf("%d\n",2*(l-m));
    }

    return 0;
}
