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

struct node
{
    int L,R,ind;
};

int arr[100005];
int fre[100005];
int maxi[100005];

node query[50002];
int res[50002];
int block,n;
int ans;



bool compare(node x, node y)
{
    // Different blocks, sort by block.
    if ((x.L/block) != (y.L/block))
        return (x.L/block) < (y.L/block);

    // Same block, sort by R value
    return (x.R < y.R);
}

void add(int pos)
{
    fre[arr[pos]]++;
    maxi[fre[arr[pos]]]++;
    if(ans<fre[arr[pos]])
    {
        ans = fre[arr[pos]];
    }

}

void Remove(int pos)
{
    maxi[fre[arr[pos]]]--;
    if(ans==fre[arr[pos]] && maxi[ans]==0)
        ans--;
    fre[arr[pos]]--;
}

void Mo(int m)
{
    block = (int) sqrt(n);

    sort(query,query+m,compare);

    int curL=0;
    int curR=0;
    int i;
    Clear(fre,0);
    Clear(maxi,0);

    ans=0;


    rep(i,0,m)
    {
        int L = query[i].L;
        int R = query[i].R;

        while(curL<L)
        {
            Remove(curL);
            curL++;
        }
        while(curL>L)
        {
            add(curL-1);
            curL--;
        }

        while(curR<=R)
        {
            add(curR);
            curR++;
        }
        while(curR>R+1)
        {
            Remove(curR-1);
            curR--;
        }

        res[query[i].ind] = ans;

    }
    rep(i,0,m)
        printf("%d\n",res[i]);
}


int main()
{
    //freopen("input.txt","r",stdin);

    int test,Case,i,j,m,c,p,q;

    read(test);

    rep(Case,1,test+1)
    {
        printf("Case %d:\n",Case);

        read(n);
        read(c);
        read(m);

        rep(i,0,n)
            read(arr[i]);

        rep(i,0,m)
        {
            read(p);
            read(q);
            query[i].L=p-1;
            query[i].R=q-1;
            query[i].ind=i;
        }

        Mo(m);
    }
    return 0;
}



