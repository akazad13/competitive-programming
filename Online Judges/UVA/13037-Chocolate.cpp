#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    bool a[100010],b[100010],c[100010];
    int test,l,r,m,n;
    scanf("%d",&test);

    for(int k=1;k<=test;k++)
    {
        for(int i=0;i<=100000;i++)
        {
            a[i]=false;
            b[i]=false;
            c[i]=false;
            //d[i]=0;
            //e[i]=0;
        }
        scanf("%d %d %d",&l,&r,&m);

        for(int i=0;i<l;i++)
        {
            scanf("%d",&n);
            a[n]=true;
        }
        for(int i=0;i<r;i++)
        {
            scanf("%d",&n);
            b[n]=true;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&n);
            c[n]=true;
        }

        printf("Case #%d:\n",k);

        int count;

        count=0;

        for(int i=0;i<=100000;i++)
        {
            if(a[i]==1 && b[i]==0 && c[i]==0)
                {
                   // cout<<i<<endl;
                    count++;
                }
        }
        printf("%d ",count);
        count=0;

        for(int i=0;i<=100000;i++)
        {
            if(b[i]==1 && c[i]==1)
            {
                if(a[i]==0)
                    count++;
            }
        }
        printf("%d\n",count);

        count=0;

        for(int i=0;i<=100000;i++)
        {
            if(b[i]==1 && a[i]==0 && c[i]==0)
                count++;
        }
        printf("%d ",count);
        count=0;

        for(int i=0;i<=100000;i++)
        {
            if(a[i]==1 && c[i]==1)
            {
                if(b[i]==0)
                    count++;
            }
        }
        printf("%d\n",count);

        count=0;

        for(int i=0;i<=100000;i++)
        {
            if(c[i]==1 && b[i]==0 && a[i]==0)
                {//cout<<i<<endl;
                    count++;
                }
        }
        printf("%d ",count);
        count=0;

        for(int i=0;i<=100000;i++)
        {
            if(b[i]==1 && a[i]==1)
            {
                if(c[i]==0)
                    count++;
            }
        }
        printf("%d\n",count);

    }

    return 0;
}


