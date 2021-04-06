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

struct Node
{
    int id,pos,sum;
};

#define Max 100010
Node tree[6*Max];

void tree_clr(int n)
{
    for(int i=0;i<6*n;i++)
    {
        tree[i].id=0;
        tree[i].pos=0;
        tree[i].sum=0;
    }
}

void node_edit(int node, int id,int pos, int sum)
{
    tree[node].id = id;
    tree[node].pos = pos;
    tree[node].sum = sum;

}

void Merge(int node, int left, int right)
{
    tree[node].sum = tree[left].sum+tree[right].sum;
}

void update(int node, int start, int eend, int pos, int val, int id)
{
    if(start==eend)
    {
        node_edit(node,id,pos,val);
        return ;
    }

    int mid= (start+eend)>>1;

    if(pos<=mid)
    {
        update((node<<1),start,mid,pos,val,id);
    }
    else
    {
        update(((node<<1)+1),mid+1,eend,pos,val,id);
    }

    Merge(node,(node<<1),(node<<1)+1);
}

int p;

int query(int node, int start, int eend, int pos)
{
    if(pos>tree[node].sum)
    {
        return -1;
    }

    if(start==eend)
    {
        if(pos!=tree[node].sum)
            return -1;
        p = tree[node].pos;
        return tree[node].id;
    }

    int mid= (start+eend)>>1;
    int left= (node<<1);

    if(pos<=tree[left].sum)
    {
       query(left,start,mid,pos);
    }
    else
    {
        query(left+1,mid+1,eend,pos-tree[left].sum);
    }
}

int main()
{
    int i,j,Case,test;
    int n,q,temp,range;

    read(test);

    rep(Case,1,test+1)
    {
        read(n); read(q);
        tree_clr(n);

        range = n+q;
        rep(i,0,n)
        {
            read(temp);

            update(1,1,range,i+1,1,temp);
        }

        printf("Case %d:\n",Case);

        rep(i,0,q)
        {
            char ch = getchar();
            read(temp);


            if(ch=='a')
            {
                n++;
                update(1,1,range,n,1,temp);
            }
            else
            {
                int ret = query(1,1,range,temp);
                if(ret==-1)
                    printf("none\n");
                else
                {
                    printf("%d\n",ret);
                    update(1,1,range,p,0,0);
                }
            }
        }
    }

    return 0;
}
