#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define read(a) scanf("%d",&a)
#define lld long long int
#define pi pair< int , int >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(i=a;i<b;i++)

#define Max 100010

int arr[2*Max+100];

pi tree[6*Max];
pi ans;

void tree_build(int node, int st, int eend)
{
    if(st==eend)
    {
         pi p;
         p = mp(arr[st],0);
         tree[node]=p;
         return ;
    }

    //cout<<st<<" "<<eend<<endl;

    int mid = (st+eend)>>1;

    tree_build(2*node,st,mid);
    tree_build(2*node+1,mid+1,eend);

    if(tree[2*node].first>tree[2*node+1].first)
    {
        tree[node].first = tree[2*node].first;
        tree[node].second = max(tree[2*node].second,tree[2*node+1].first);
    }

    else if(tree[2*node].first<tree[2*node+1].first)
    {
        tree[node].first = tree[2*node+1].first;
        tree[node].second = max(tree[2*node].first,tree[2*node+1].second);
    }

    else
    {
        tree[node].first  = tree[2*node].first;
        tree[node].second = tree[2*node+1].first;
    }

    return ;
}

void tree_query(int node, int st, int eend, int s, int e)
{
    if(eend<s || st>e)
    {
     //   ans.first=max(ans.first,0);
     //   ans.second=max(ans.second,0);

        return ;
    }

   // cout<<st<<" "<<eend<<endl;

    if(st>=s && eend<=e)
    {
        if(ans.first>tree[node].first)
        {
            ans.second = max(ans.second,tree[node].first);
        }

        else if(ans.first<tree[node].first)
        {
            ans.second = max(ans.first,tree[node].second);
            ans.first = tree[node].first;

        }

        else
        {
            ans.second  = tree[node].first;
        }

        return ;
    }

    int mid = (st+eend)>>1;


    tree_query(2*node,st,mid,s,e);

    tree_query(2*node+1,mid+1,eend,s,e);

}

void tree_update(int node, int st, int eend, int ind, int x)
{
    if(eend<ind || st>ind)
    {
        return ;
    }

    if(st>=ind && eend<=ind)
    {
        tree[node].first = x;
        tree[node].second = 0;
        return ;
    }

    int mid = (st+eend)>>1;

    tree_update(2*node,st,mid,ind,x);
    tree_update(2*node+1,mid+1,eend,ind,x);

    if(tree[2*node].first>tree[2*node+1].first)
    {
        tree[node].first = tree[2*node].first;
        tree[node].second = max(tree[2*node].second,tree[2*node+1].first);
    }

    else if(tree[2*node].first<tree[2*node+1].first)
    {
        tree[node].first = tree[2*node+1].first;
        tree[node].second = max(tree[2*node].first,tree[2*node+1].second);
    }

    else
    {
        tree[node].first  = tree[2*node].first;
        tree[node].second = tree[2*node+1].first;
    }

    return ;
}

int main()
{
    //freopen("in.txt","r",stdin);
  // tree.clear();
   // tree.reserve(6*Max);

    //freopen("inp.txt","r",stdin);
    //freopen("out2.txt","w",stdout);

    int n,query,i,j;
    char ch;
    int a,b,x;
    read(n);

    rep(i,1,n+1)
        read(arr[i]);
    tree_build(1,1,n);

    read(query);
    //int cnt=1;
    while(query--)
    {
        char c = getchar();
        scanf("%c %d %d",&ch,&a,&b);

        if(ch=='Q')
        {
            ans.first = 0;
            ans.second = 0;
            tree_query(1,1,n,a,b);
           // printf("Case %d: ",cnt++);

            printf("%d\n",ans.first+ans.second);
        }
        else if(ch=='U')
        {
            tree_update(1,1,n,a,b);
        }

    }

    return 0;
}
