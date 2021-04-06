#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 100010
#define ll long long int
#define mod 1000000007

ll tree[3*mx];
ll arr[mx+10];
ll temp[mx+10];

map<ll, ll > mp;

void build(int node, int start, int eend)
{
    if(start==eend)
    {
        tree[node]=0;
        return ;
    }
    int mid = (start+eend)>>1;

    int l = node<<1;
    int r = l+1;

    build(l,start,mid);
    build(r,mid+1,eend);

    tree[node]=tree[l]+tree[r];

}

int query(int node, int start, int eend, int st, int ed)
{
    if(eend<st || start>ed)
        return 0;
    if(start>=st && eend<=ed)
    {
        return tree[node];
    }
    int mid = (start+eend)>>1;

    int l = node<<1;
    int r = l+1;

    return (query(l,start,mid,st,ed)+query(r,mid+1,eend,st,ed))%mod;
}

void update(int node,int start,int eend, int index,int x) //TO update
{
    if(eend<index || start>index)
        return ;
    if(start>=index && eend<=index)
    {
        tree[node]=x;
        return ;
    }

    int mid = (start+eend)>>1;

    int l = node<<1;
    int r = l+1;

    update(l,start,mid,index,x);
    update(r,mid+1,eend,index,x);
    tree[node]=(tree[l]+tree[r])%mod;

    return ;

}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll test,n,qur,st,ed;
    scanf("%lld",&test);

    for(ll Case=1;Case<=test;Case++)
    {
        scanf("%lld",&n);

        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            temp[i]=arr[i];
        }

        sort(temp+1,temp+n+1);

        mp.clear();

        int cnt=1;
        for(ll i=1;i<=n;i++)
        {
           // cout<<temp[i]<<endl;
            if(!mp[temp[i]])
                mp[temp[i]]= cnt++;
        }

        build(1,1,n);

        ll ret;

        for(int i=1;i<=n;i++)
        {

           // cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
            ret = query(1,1,n,1,mp[arr[i]]);


            ret++;
           // cout<<ret<<endl;

            update(1,1,n,mp[arr[i]],(ret%mod));
        }

        printf("Case %lld: %lld\n",Case,tree[1]);
    }


    return 0;

}

