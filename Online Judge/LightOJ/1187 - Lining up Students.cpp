#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define Clear(a,b) memset(a,b,sizeof(a))

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

#define MAX 100010


int tree[3*MAX];

void build(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node]=1;
        return ;
    }

    int mid = (start+eend)>>1;

    int left = node<<1;
    int right = left+1;

    build(left,start,mid);
    build(right,mid+1,eend);

    tree[node]=tree[left]+tree[right];
}

void update(int node, int start, int eend, int val)
{
    if(start>val || eend<val)
    {
        return ;
    }

    if(start==val && eend==val)
    {
        tree[node]=0;
        return ;
    }

    int mid = (start+eend)>>1;

    int left = node<<1;
    int right = left+1;

    update(left,start,mid,val);
    update(right,mid+1,eend,val);

    tree[node]=tree[left]+tree[right];
}

int query(int node, int start, int eend, int pos)
{
    if(start==eend)
    {
        return start;
    }

    int mid = (start+eend)>>1;

    int left = node<<1;
    int right = left+1;

    if(pos<=tree[left])
    {
        query(left,start,mid,pos);
    }
    else
    {
        query(right,mid+1,eend,pos-tree[left]);
    }
}


int main()
{
    int test,i,j,Case,n,m;

    read(test);
    rep(Case,1,test+1)
    {
        read(n);

        stack<int> stk;

        rep(i,0,3*MAX)
            tree[i]=0;
        build(1,1,n);

        for(int i=0;i<n;i++)
        {
            read(m);
            stk.push(m);
        }
        int ret=0;
        int pp=n;
        while(!stk.empty())
        {
            int p = stk.top();
            stk.pop();
            ret = query(1,1,n,pp-p);
            pp-=1;
            update(1,1,n,ret);

        }
        printf("Case %d: %d\n",Case,ret);
    }

    return 0;
}
