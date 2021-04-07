#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 32
struct box
{
    int len, wid, hi;
};

box tempData[Max];
box data[3*Max+1];
int dp[3*Max+1];
int sol[3*Max+1];

box fix(int hight, int side1, int side2)
{
    box p;
    p.hi = hight;

    if(side1>=side2)
    {
        p.len = side1;
        p.wid = side2;
    }
    else
    {
        p.len = side2;
        p.wid = side1;
    }

    return p;
}

bool cmp(box a, box b)
{
    if(a.len*a.wid==b.len*b.wid)
        return 1;
    return (a.len*a.wid)>(b.len*b.wid);
}

void solve(int n)
{

    int cnt=0;

    for(int i=0;i<n;i++)
    {
        box ret = fix(tempData[i].len,tempData[i].hi,tempData[i].wid);

        data[cnt++]=ret;

        ret  = fix(tempData[i].wid,tempData[i].len,tempData[i].hi);
        data[cnt++]=ret;

        ret  = fix(tempData[i].hi,tempData[i].len,tempData[i].wid);
        data[cnt++]=ret;
    }

    sort(data,data+cnt,cmp);

    for(int i=0;i<cnt;i++)
    {
        sol[i]=i;
        dp[i]=data[i].hi;
    }

    for(int i=1;i<cnt;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(data[i].len<data[j].len && data[i].wid<data[j].wid)
            {
                if(dp[j]+data[i].hi>dp[i])
                {
                    dp[i]=dp[j]+data[i].hi;
                    sol[i]=j;

                }
            }
        }
    }

    int Maxi = INT_MIN;
    int ind = -1;

    for(int i=0;i<cnt;i++)
    {
        if(dp[i]>Maxi)
        {
            ind = i;
            Maxi = dp[i];
        }
    }

    printf("%d\n",Maxi);

    /*printf("%d %d %d\n",data[ind].len,data[ind].wid,data[ind].hi);

    do
    {
        ind = sol[ind];
         printf("%d %d %d\n",data[ind].len,data[ind].wid,data[ind].hi);

    }while(ind!=sol[ind]);

    printf("\n");*/


}

int main()
{

    int n;
    int cnt=1;

    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&tempData[i].len,&tempData[i].wid,&tempData[i].hi);
        }

        printf("Case %d: maximum height = ",cnt++);

        solve(n);

    }

    return 0;
}

