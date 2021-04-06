#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 100010

int tree[3*mx];
int arr[mx+10];
int ans;

void make_tree(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node]=arr[start];
        return ;
    }
    int mid = (start+eend)/2;

    make_tree(2*node,start,mid);
    make_tree(2*node+1,mid+1,eend);

    tree[node]=min(tree[2*node],tree[2*node+1]);

}

int query(int node, int start, int eend, int st, int ed)
{
    if(eend<st || start>ed)
        return min(ans,INT_MAX);
    if(start>=st && eend<=ed)
    {
        ans=min(ans,tree[node]);
        return ans;
    }
    int mid = (start+eend)/2;

    query(2*node,start,mid,st,ed);
    query(2*node+1,mid+1,eend,st,ed);

}

int main()
{
    int test,n,qur,st,ed;

    cin>>test;

    for(int Case=1;Case<=test;Case++)
    {
        scanf("%d %d",&n,&qur);

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        make_tree(1,1,n);

        printf("Case %d:\n",Case);

        for(int i=0;i<qur;i++)
        {
            ans=INT_MAX;
            scanf("%d %d",&st,&ed);
            printf("%d\n",query(1,1,n,st,ed));

        }
    }
    return 0;
}
