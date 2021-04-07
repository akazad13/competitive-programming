#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int val,ind;
};

bool cmp(node a, node b)
{

    return a.val<b.val;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int n,b,h,w,p;
    node cost[20];

    int seat[20][20];

    while(scanf("%d %d %d %d",&n,&b,&h,&w)==4)
    {
        for(int i=0;i<h;i++)
        {
            scanf("%d",&p);
            cost[i].val=p;
            cost[i].ind=i;

            for(int j=0;j<w;j++)
            {
                scanf("%d",&seat[i][j]);
            }
        }

        sort(cost,cost+h,cmp);

        bool flag=1;

        int tcost=0;

        for(int i=0;i<h;i++)
        {
            int ind = cost[i].ind;
            if(flag==0)
                break ;

            for(int j=0;j<w;j++)
            {
                if(seat[ind][j]>=n)
                {
                    tcost = n*cost[i].val;
                    flag=0;
                    break;
                }
            }
        }

        if(flag || tcost>b)
        {
            printf("stay home\n");
        }
        else
        {
            printf("%d\n",tcost);
        }
    }

    return 0;
}
