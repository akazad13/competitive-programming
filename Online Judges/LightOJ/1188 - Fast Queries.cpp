#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))

int arr[100010];
int Map[100010];

struct node
{
    int L,R,ind;
};

node query[50005];
int res[50005];
int block;
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
    Map[arr[pos]]++;
    if(Map[arr[pos]]==1)
       ans++;

}

void Remove(int pos)
{
    Map[arr[pos]]--;
    if(Map[arr[pos]]==0)
       ans--;
}

int main()
{
    int test,i,j,Case,n,m,p,q;
    read(test);
    rep(Case,1,test+1)
    {
        Clear(Map,0);
        read(n); read(m);

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
        printf("Case %d:\n",Case);

        block = (int) sqrt(n);

        sort(query,query+m,compare);

        int curL=0;
        int curR=0;
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

    return 0;
}
