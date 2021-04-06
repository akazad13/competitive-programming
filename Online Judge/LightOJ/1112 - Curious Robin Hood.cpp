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

    tree[node]=tree[2*node]+tree[2*node+1];

}

int query(int node, int start, int eend, int st, int ed)
{
    if(eend<st || start>ed)
        return ans+0;
    if(start>=st && eend<=ed)
    {
        ans=ans+tree[node];
        return ans;
    }
    int mid = (start+eend)/2;

    query(2*node,start,mid,st,ed);
    query(2*node+1,mid+1,eend,st,ed);

}

int m;

void update(int node,int start,int eend, int index,int type, int x)
{
    if(eend<index || start>index)
        return ;
    if(start>=index && eend<=index)
    {
        if(type==1)
        {
            m=tree[node];
            tree[node]=0;
            return ;
        }
        else if(type==2)
        {
            tree[node]+=x;
            return ;
        }
    }

    int mid = (start+eend)/2;
    update(2*node,start,mid,index,type,x);
    update(2*node+1,mid+1,eend,index,type,x);
    tree[node]=tree[node*2]+tree[node*2+1];

}

int main()
{
    int test,n,qur,st,ed,caseType,x,ind;

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
            scanf("%d",&caseType);
            if(caseType==1)
            {
                scanf("%d",&ind);
                ind++;
                update(1,1,n,ind,caseType,x);
                printf("%d\n",m);
            }
            else if(caseType==2)
            {
                scanf("%d %d",&ind,&x);
                ind++;
                update(1,1,n,ind,caseType,x);
            }
            else
            {
                scanf("%d %d",&st,&ed);
                st++;ed++;
                ans=0;
                printf("%d\n",query(1,1,n,st,ed));
            }
        }
    }
    return 0;
}
