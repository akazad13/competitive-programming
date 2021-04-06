#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 200010
#define ll long long int
#define x first
#define y second
#define pii pair<ll,ll>

int pp[Max];
vector<pii> arr, arr1;
ll tree[3*Max];

void update(int node, int start, int eend, int idx)
{
    if(idx<start || idx > eend)
        return ;
    if(idx==start && idx==eend)
    {
        tree[node]=1;
        return ;
    }
    int mid = (start+eend)>>1;

    int l = node<<1;
    int r = l+1;

    update(l,start,mid,idx);
    update(r,mid+1,eend,idx);

    tree[node]=tree[l]+tree[r];

    return ;

}

ll query(int node, int start, int eend, int st, int ed)
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

    return query(l,start,mid,st,ed)+query(r,mid+1,eend,st,ed);

}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test;
    ll n,m,a,b;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {

        arr.clear();
        arr1.clear();
        memset(tree,0,sizeof(tree));


        scanf("%lld %lld",&n,&m);

        int len = n+m;

        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld",&a,&b);
            arr1.push_back(make_pair(a,b));
        }

        for(int i=0;i<m;i++)
        {
            scanf("%lld %lld",&a,&b);
            arr.push_back(make_pair(a,b));
        }

        sort(arr.begin(),arr.end());
        sort(arr1.begin(),arr1.end());

        ll sum=0;
        int j=0;

        for(int i=0;i<m;i++)
        {
            ll u = arr[i].y;
            ll v = arr[i].x;

            while(j<n && arr1[j].x<v)
            {
                update(1,1,len,arr1[j].y);
                j++;
            }
            sum+= query(1,1,len,u,len);
           // cout<<sum<<endl;
        }

        memset(tree,0,sizeof(tree));

        j=n-1;

        for(int i=m-1;i>=0;i--)
        {
            ll u = arr[i].y;
            ll v = arr[i].x;

            while(j>=0 && arr1[j].x>v)
            {
                update(1,1,len,arr1[j].y);
                j--;
            }
            sum+= query(1,1,len,0,u);
           // cout<<sum<<endl;
        }


        printf("Case %d: %lld\n",Case,sum);

    }


    return 0;

}
