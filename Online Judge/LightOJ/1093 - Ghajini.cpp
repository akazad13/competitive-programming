#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 100010

struct Node
{
    int Max;
    int Min;
};

Node tree[3*mx+20];
int arr[mx+10];
int ans;

void make_tree(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node].Max=arr[start];
        tree[node].Min=arr[start];
        return ;
    }
    int mid = (start+eend)/2;

    make_tree(2*node,start,mid);
    make_tree(2*node+1,mid+1,eend);

    tree[node].Max=max(tree[2*node].Max,tree[2*node+1].Max);
    tree[node].Min=min(tree[2*node].Min,tree[2*node+1].Min);

}

void update(int node,int start,int eend, int index,int x)
{
    if(eend<index || start>index)
        return ;
    if(start>=index && eend<=index)
    {
        tree[node].Max=x;
        tree[node].Min=x;
        return ;
    }

    int mid = (start+eend)/2;
    update(2*node,start,mid,index,x);
    update(2*node+1,mid+1,eend,index,x);
    tree[node].Max=max(tree[2*node].Max,tree[2*node+1].Max);
    tree[node].Min=min(tree[2*node].Min,tree[2*node+1].Min);

}


int main()
{
    int test,n,rem;

    cin>>test;

    for(int Case=1;Case<=test;Case++)
    {
        scanf("%d %d",&n,&rem);

        for(int i=1;i<=rem;i++)
        {
            scanf("%d",&arr[i]);
        }
        int st=1;
        int een=rem;

        make_tree(1,st,een);

        int MMXX=abs(tree[1].Max-tree[1].Min);
        een++;
        st++;
        int x;

        while(een<=n)
        {
            scanf("%d",&x);
            update(1,1,rem,((een-1)%rem+1),x);
            int ret = abs(tree[1].Max-tree[1].Min);
            MMXX = max(MMXX,ret);
            een++;
        }
        printf("Case %d: %d\n",Case,MMXX);
    }
    return 0;
}
