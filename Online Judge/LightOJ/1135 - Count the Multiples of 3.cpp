#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 100010

struct node{

    int a, b, c;
    int prop;
};

int arr[Max];
node tree[3*Max+10];

void tree_build(int node, int st, int eend)
{
    if(st==eend)
    {
        tree[node].a=1;
        tree[node].b=0;
        tree[node].c=0;
        tree[node].prop=0;

        return ;
    }

    int mid = (st+eend)>>1;

    tree_build(node<<1,st,mid);
    tree_build((node<<1)+1,mid+1,eend);

    tree[node].a = tree[node<<1].a+tree[(node<<1)+1].a;
    tree[node].b = tree[node<<1].b+tree[(node<<1)+1].b;
    tree[node].c = tree[node<<1].c+tree[(node<<1)+1].c;

    return ;
}

void update_tree(int node, int start, int eend, int L, int R)
{
    if(eend<L || start>R)
        return ;
    if(start>=L && eend<=R)
    {

        tree[node].prop=(tree[node].prop+1)%3;
        int temp1 = tree[node].a;
        int temp2 = tree[node].b;
        int temp3 = tree[node].c;
        tree[node].a=temp3;
        tree[node].b=temp1;
        tree[node].c=temp2;
        return ;

    }

    int mid = (start+eend)>>1;

    update_tree(node<<1,start,mid,L,R);
    update_tree((node<<1)+1,mid+1,eend,L,R);

    if(tree[node].prop==1)
    {
        tree[node].a = tree[node<<1].c+tree[(node<<1)+1].c;
        tree[node].b = tree[node<<1].a+tree[(node<<1)+1].a;
        tree[node].c = tree[node<<1].b+tree[(node<<1)+1].b;
    }

    else if(tree[node].prop==2)
    {
        tree[node].a = tree[node<<1].b+tree[(node<<1)+1].b;
        tree[node].b = tree[node<<1].c+tree[(node<<1)+1].c;
        tree[node].c = tree[node<<1].a+tree[(node<<1)+1].a;
    }
    else
    {
        tree[node].a = tree[node<<1].a+tree[(node<<1)+1].a;
        tree[node].b = tree[node<<1].b+tree[(node<<1)+1].b;
        tree[node].c = tree[node<<1].c+tree[(node<<1)+1].c;
    }

    return ;
}

node ans;

void tree_query(int node , int start, int eend, int L, int R,int car)
{
    if(eend<L || start>R)
        return ;
    if(start>=L && eend<=R)
    {
        if(car==0)
        {
            ans.a += tree[node].a;
            ans.b += tree[node].b;
            ans.c += tree[node].c;
        }
        else if(car==1)
        {
            ans.a += tree[node].c;
            ans.b += tree[node].a;
            ans.c += tree[node].b;

        }

        else if(car==2)
        {
            ans.a += tree[node].b;
            ans.b += tree[node].c;
            ans.c += tree[node].a;
        }

        return ;

    }

    int mid = (start+eend)>>1;

    tree_query(node<<1,start,mid,L,R,(car+tree[node].prop)%3);
    tree_query((node<<1)+1,mid+1,eend,L,R,(car+tree[node].prop)%3);

    return ;
}


int main()
{

    int test,i,j,Case,n,q;
    int L, R, choice;
    read(test);
    rep(Case,1,test+1)
    {
        read(n);

        for(int i=0;i<3*n;i++)
        {
            tree[i].a=tree[i].b=tree[i].c=tree[i].prop=0;
        }

        read(q);
        tree_build(1,1,n);

        printf("Case %d:\n",Case);

        rep(i,0,q)
        {
            read(choice);read(L);read(R);
            L++;
            R++;
            if(choice==0)
            {
                update_tree(1,1,n,L,R);
            }
            else
            {
                ans.a=0;
                ans.b=0;
                ans.c=0;
                ans.prop=0;

                tree_query(1,1,n,L,R,0);

                printf("%d\n",ans.a);
            }
        }
    }

    return 0;
}

