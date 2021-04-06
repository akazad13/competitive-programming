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

vector< pi > range;
vector<int> quer;

#define Max 250000

struct Node
{
    int prop,val;
};

Node tree[4*Max+10];


void update(int node, int start, int eend, int left, int right)
{
    if(start>right ||  eend<left)
        return ;
    if(start>=left && eend<=right)
    {
        tree[node].prop+=1;
        tree[node].val+=(eend-start+1);
        return ;
    }

    int mid = (start+eend)>>1;
    int nleft = node<<1;

    update(nleft,start,mid,left,right);
    update(nleft+1,mid+1,eend,left,right);

    tree[node].val = tree[nleft].val+tree[nleft+1].val+tree[node].prop*(eend-start+1);

}

int query(int node, int start, int eend, int ind, int car)
{
    if(start>ind ||  eend<ind)
        return 0;
    if(start==ind && eend==ind)
    {
        return tree[node].val+(eend-start+1)*car;
    }

    int mid = (start+eend)>>1;

    int nleft = node<<1;

    car+=tree[node].prop;

    return query(nleft,start,mid,ind,car)+query(nleft+1,mid+1,eend,ind,car);
}

int main()
{
    int test,i,j,Case,n,q,a,b;
    map<int, int > Map;
    map<int, int > :: iterator it;
    read(test);
    rep(Case,1,test+1)
    {
        rep(i,0,4*Max+5)
        {
            tree[i].val=0;
            tree[i].prop=0;
        }

        read(n); read(q);
        Map.clear();
        range.clear();
        quer.clear();

        rep(i,0,n)
        {
            read(a); read(b);
            range.push_back(mp(a,b));
            Map[a]=1;
            Map[b]=1;
        }

        rep(i,0,q)
        {
            read(a);
            Map[a]=1;
            quer.push_back(a);
        }

        int m = 0;
        for(it=Map.begin();it!=Map.end();it++)
        {
            it->second = ++m;
        }
        rep(i,0,n)
        {
            update(1,1,m,Map[range[i].first],Map[range[i].second]);
        }

        printf("Case %d:\n",Case);

        rep(i,0,q)
        {
            printf("%d\n",query(1,1,m,Map[quer[i]],0));
        }
    }

    return 0;
}

