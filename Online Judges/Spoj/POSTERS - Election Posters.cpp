#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

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

int tree[3*MAX+10];

void pushdown(int id)
{
    if(tree[id])
    {
        int left = id<<1;
        int right = left+1;
        tree[left] = tree[right] = tree[id];
        tree[id]=0;
    }
}

void update(int node, int start, int eend, int left, int right,int color)
{
    if(start>right ||  eend<left)
        return ;
    if(start>=left && eend<=right)
    {
        tree[node]=color;
        return ;
    }

    int mid = (start+eend)>>1;

    pushdown(node);

    int nleft = node<<1;

    update(nleft,start,mid,left,right,color);
    update(nleft+1,mid+1,eend,left,right,color);

}

set<int> S;

void query(int node, int start, int eend)
{
    if(tree[node])
    {
        S.insert(tree[node]);
        return ;
    }

    if(eend==start)
        return ;
    int mid = (start+eend)>>1;
    int nleft = node<<1;

    query(nleft,start,mid);
    query(nleft+1,mid+1,eend);

}

int main()
{
    //freopen("in.txt","r",stdin);

    int test,i,j,Case,n,q,a,b;
    vector< pi > range;
    map<int, int> Map;
    map<int, int> :: iterator  it;
    read(test);
    rep(Case,1,test+1)
    {
        rep(i,0,3*MAX+5)
        {
            tree[i]=0;
        }

        read(n);
        range.clear();
        S.clear();
        Map.clear();

        rep(i,0,n)
        {
            read(a); read(b);
            range.push_back(mp(a,b));
            Map[a]=1;
            Map[b]=1;
        }

        int cnt=0;

        for(it=Map.begin();it!=Map.end();it++)
        {
            Map[it->first] = ++cnt;
        }

        for(i=0;i<n;i++)
        {
            update(1,1,cnt,Map[range[i].first],Map[range[i].second],i+1);
        }

        query(1,1,cnt);


        printf("%d\n",S.size());

    }

    return 0;
}




