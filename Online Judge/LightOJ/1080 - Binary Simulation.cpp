#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 100010
#define CLEAR(a,n) memset(a,n,sizeof(a))

struct Node
{
    bool prop;
    bool val;
};

Node tree[3*mx+10];
bool arr[mx+10];

void make_tree(int node, int Start, int End)
{
    if(Start==End)
    {
        tree[node].val=arr[Start];
        tree[node].prop=false;
        return ;
    }
    int mid = (Start+End)/2;

    make_tree(2*node,Start,mid);
    make_tree(2*node+1,mid+1,End);
}

bool query(int node, int Start, int End,int ind, bool car)
{
    if(End<ind || Start>ind)
        return 0;
    if(Start>=ind && End<=ind)
    {
       if(tree[node].prop)
            car = !car;
        if(car)
        {
            return !tree[node].val;
        }
        else
            return tree[node].val;
    }
    int mid = (Start+End)/2;

    if(tree[node].prop)
    {
        car = !car;
    }

    bool p1 = query(2*node,Start,mid,ind,car);
    bool p2 = query(2*node+1,mid+1,End,ind,car);

    return (p1|p2);

}

void update(int node,int Start,int End, int st,int en)
{
    if(End<st || Start>en)
        return ;
    if(Start>=st && End<=en)
    {
        tree[node].prop= !tree[node].prop;
        return ;
    }

    int mid = (Start+End)/2;
    update(2*node,Start,mid,st,en);
    update(2*node+1,mid+1,End,st,en);
}

int main()
{
    int test,n,qur,st,en,ind;
    char str[100010],ch,ch1;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        CLEAR(tree,false);
        ch1 = getchar();
        gets(str);

        n = strlen(str);
        for(int i=1;i<=n;i++)
            arr[i]=str[i-1]-'0';

        scanf("%d",&qur);
        make_tree(1,1,n);

        printf("Case %d:\n",Case);
        for(int i=0;i<qur;i++)
        {
            ch1 = getchar();
            ch=getchar();
            if(ch=='I')
            {
                scanf("%d %d",&st,&en);
                update(1,1,n,st,en);
            }
            else if(ch=='Q')
            {
                scanf("%d",&ind);
                printf("%d\n",query(1,1,n,ind,0));
            }
        }

    }
    return 0;
}
