#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)

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

#define MAX 1000010

struct Node
{
    bool prop,val;
};

Node tree[3*MAX+10];


void update(int node, int start, int eend, int left, int right)
{
    if(start>right ||  eend<left)
        return ;
    if(start>=left && eend<=right)
    {
        tree[node].prop=1;
        tree[node].val=1;
        return ;
    }

    int mid = (start+eend)>>1;

    int nleft = node<<1;

    update(nleft,start,mid,left,right);
    update(nleft+1,mid+1,eend,left,right);

    tree[node].val = (tree[nleft].val&tree[nleft+1].val)|tree[node].prop;

}

int query(int node, int start, int eend, int left,int right, bool car)
{
    if(start>right ||  eend<left)
        return 1;
    if(start>=left && eend<=right)
    {
        return (tree[node].val|car);
    }

    int mid = (start+eend)>>1;

    int nleft = node<<1;

    car|=tree[node].prop;

    return query(nleft,start,mid,left,right,car)&query(nleft+1,mid+1,eend,left,right,car);
}

int main()
{
    int test,i,j,Case,n,q,a,b;
    vector< pi > range;

    read(test);
    rep(Case,1,test+1)
    {
        rep(i,0,3*MAX+5)
        {
            tree[i].val=0;
            tree[i].prop=0;
        }

        read(n);
        range.clear();

        int Max = -1;

        rep(i,0,n)
        {
            read(a); read(b);
            Max = max(Max,max(a,b));
            range.push_back(mp(a,b));
        }
        int cnt=0;

        for(i=n-1;i>=0;i--)
        {
            bool ret = query(1,1,Max,range[i].first,range[i].second,0);
            if(!ret)
            {
                cnt++;
                update(1,1,Max,range[i].first,range[i].second);
            }
        }
        printf("Case %d: %d\n",Case,cnt);

    }
    return 0;
}


