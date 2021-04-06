#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define Max  2010
#define ll long long int

char str[Max];
int arr[Max];

struct Node
{
    int val, ind;
};

Node tree[4*Max];

void build(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node].val=arr[start];
        tree[node].ind = start;
        return ;
    }
    int mid = (start+eend)>>1;

    int l = node<<1;
    int r = l+1;

    build(l,start,mid);
    build(r,mid+1,eend);

    if(tree[l].val<tree[r].val)
    {
        tree[node].val = tree[l].val;
        tree[node].ind = tree[l].ind;
    }
    else
    {
        tree[node].val = tree[r].val;
        tree[node].ind = tree[r].ind;
    }

    return ;

}

Node p;

Node query(int node, int start, int eend, int st, int ed)
{
    if(eend<st || start>ed)
    {
        p.val = INT_MAX;
        return p;
    }
    if(start>=st && eend<=ed)
    {
        return tree[node];
    }
    int mid = (start+eend)>>1;

    int l = node<<1;
    int r = l+1;

    Node t1 = query(l,start,mid,st,ed);
    Node t2 = query(r,mid+1,eend,st,ed);

    if(t1.val<t2.val)
    {
        return t1;
    }
    else
        return t2;

}

int test,n,m;

int histoSolve(int l, int r)
{
    if(l==r)
    {
        return arr[l];
    }

    if(l>r) return 0;

    Node t1 = query(1,1,m,l,r);

    int res = t1.val*(r-l+1);

    int ind = t1.ind;

    int res1 = histoSolve(l,ind-1);
    int res2 = histoSolve(ind+1,r);

    res = max(res,max(res1,res2));
    return res;

}

int main()
{

    si(test);

    for(int Case=1;Case<=test;Case++)
    {
        si(n); si(m);

        memset(arr,0,sizeof(arr));

        int res=0;

        for(int i=0;i<n;i++)
        {
            scanf(" %s",str);

            for(int j=0;j<m;j++)
            {
                if(str[j]=='0')
                    arr[j+1]++;
                else
                    arr[j+1]=0;
            }

            for(int j=0;j<=m;j++)
            {
                tree[i].val=0;
                tree[i].ind=0;
            }

            build(1,1,m);

            res = max(res,histoSolve(1,m));

        }

        printf("Case %d: %d\n",Case,res);

    }

    return 0;
}
