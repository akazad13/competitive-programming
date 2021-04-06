//https://www.hackerrank.com/challenges/insertion-sort/problem
// using segment tree to count the current position after putting the number from sorted list in its actual position in the given array

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 200010
#define ll long long int

struct Node
{
    ll prop;
    ll sum;
};

Node tree[3*mx+10];
struct P
{
    ll val,pos;
} arr[mx+10];

bool cmp(P a, P b)
{
    if(a.val==b.val)
        return a.pos<b.pos;
    return a.val<b.val;
}

void build(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node].sum=arr[start].pos;
        tree[node].prop=0;
        return ;
    }
    int mid = (start+eend)>>1;
    int l = node<<1;
    int r = l+1;

    build(l,start,mid);
    build(r,mid+1,eend);

    tree[node].sum=tree[l].sum+tree[r].sum;
    return;
}

ll query(int node, int start, int eend, int st, int ed, ll car)
{
    if(eend<st || start>ed)
        return 0;
    if(start>=st && eend<=ed)
    {
        return tree[node].sum+(eend-start+1)*car;
    }
    int mid = (start+eend)>>1;
    int l = node<<1;
    int r = l+1;

    ll p1 = query(l,start,mid,st,ed,car+tree[node].prop);
    ll p2 = query(r,mid+1,eend,st,ed,car+tree[node].prop);

    return p1+p2;

}

//int m;

void update(int node,int start,int eend, int st,int en,ll x)
{
    if(eend<st || start>en)
        return ;
    if(start>=st && eend<=en)
    {
        //cout<<"t"<<tree[node]<<endl;
        tree[node].prop+=x;
        tree[node].sum+=(abs(start-eend)+1)*x;

        return ;
    }

    int mid = (start+eend)>>1;
    int l = node<<1;
    int r = l+1;

    update(l,start,mid,st,en,x);
    update(r,mid+1,eend,st,en,x);
    tree[node].sum=tree[l].sum+tree[r].sum +tree[node].prop*(eend-start+1ll);

}

int main()
{
   // freopen("in.txt","r",stdin);
    int test,n,qur,st,en,p;
    ll x;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        for(int i=0;i<=3*mx;i++)
        {
            tree[i].sum=0;
            tree[i].prop=0;
        }

        scanf("%d",&n);

        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i].val);
            arr[i].pos=i;
        }

        build(1,1,n);

        sort(arr+1,arr+n+1,cmp);

        ll ans=0;

        for(int i=1;i<=n;i++)
        {
           ll pos = query(1,1,n,arr[i].pos,arr[i].pos,0ll);

            if(pos==i)
                continue;

            ans += pos-i;
            update(1,1,n,1,arr[i].pos-1,1ll);
        }
        printf("%lld\n",ans);
    }


    return 0;

}
© 2018 GitHub, Inc.
