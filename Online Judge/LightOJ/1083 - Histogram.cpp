#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 30000

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

struct Node
{
    int val;
    int ind;
};

Node tree[4*Max+10];
int arr[Max];

void tree_build(int node, int st, int eend)
{
    if(st==eend)
    {
        tree[node].val=arr[st];
        tree[node].ind=st;
        return ;
    }

    int mid = (st+eend)>>1;

    tree_build(node<<1,st,mid);
    tree_build((node<<1)+1,mid+1,eend);

    if(tree[node<<1].val<=tree[(node<<1)+1].val)
    {
        tree[node].val = tree[node<<1].val;
        tree[node].ind = tree[node<<1].ind;
    }
    else
    {
        tree[node].val = tree[(node<<1)+1].val;
        tree[node].ind = tree[(node<<1)+1].ind;
    }

    return ;
}

Node p;

Node tree_query(int node , int start, int eend, int L, int R)
{
    if(eend<L || start>R)
        return p;
    if(start>=L && eend<=R)
    {
        return tree[node];

    }

    int mid = (start+eend)>>1;

    Node t1 = tree_query(node<<1,start,mid,L,R);
    Node t2 = tree_query((node<<1)+1,mid+1,eend,L,R);

    if(t1.val<=t2.val)
    {
        return t1;
    }
    else
    {
        return t2;
    }
}


int query(int start, int eend, int n)
{
    if(start==eend)
        return arr[start];
    if(start>eend)
        return 0;

    Node ret1 = tree_query(1,1,n,start,eend);
    int res = ret1.val*(eend-start+1);

    int ind = ret1.ind;

    int t1 = query(start,ind-1,n);
    int t2 = query(ind+1,eend,n);

    res = max(res,max(t1,t2));

    return res;
}

int main()
{
    int test,i,j,Case,n,q;
    int L, R;
    p.val=41343242;
    read(test);
    rep(Case,1,test+1)
    {
        read(n);

        for(int i=0;i<3*n;i++)
        {
            tree[i].val=0;
            tree[i].ind=0;
        }

        rep(i,1,n+1)
            read(arr[i]);

        tree_build(1,1,n);

        int ret = query(1,n,n);

        printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}



