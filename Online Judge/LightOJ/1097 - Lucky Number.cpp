#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 1429440

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}


int arr[Max+10];
int tree[3*Max];

void tree_build(int node, int st, int eend)
{
    if(st==eend)
    {
        tree[node]=1&st;

        return ;
    }

    int mid = (st+eend)>>1;

    tree_build(node<<1,st,mid);
    tree_build((node<<1)+1,mid+1,eend);

    tree[node]=tree[node<<1]+tree[(node<<1)+1];

    return ;
}

void update_tree(int node, int start, int eend, int ith)
{
    if(start==eend)
    {
        tree[node]=0;
        return ;

    }

    int mid = (start+eend)>>1;

    if(ith>tree[node<<1])
        update_tree((node<<1)+1,mid+1,eend,ith-tree[node<<1]);
    else
        update_tree((node<<1),start,mid,ith);

    tree[node]=tree[node<<1]+tree[(node<<1)+1];

    return ;
}


int tree_query(int node , int start, int eend, int ith)
{
    if(start==eend)
    {
        return start;

    }

    int mid = (start+eend)>>1;

    if(ith>tree[node<<1])
    {
        return tree_query((node<<1)+1,mid+1,eend,ith-tree[node<<1]);
    }
    else
    {
        return tree_query((node<<1),start,mid,ith);
    }
}

void solve()
{
    arr[1]=1;
    tree_build(1,1,Max);

    int i,j;

    rep(i,2,100001)
    {
        int ith = tree_query(1,1,Max,i);
        arr[i]=ith;
        int lim = (Max/ith)*ith;

        for( ;lim>=ith;lim-=ith)
        {
            update_tree(1,1,Max,lim);
        }
    }
}


int main()
{
    int test,i,j,Case,n;
    solve();
    read(test);

    rep(Case,1,test+1)
    {
        read(n);
        printf("Case %d: %d\n",Case,arr[n]);
    }
    return 0;
}
