#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define ll long long int

#define Clear(a,b) memset(a,b,sizeof(a))
//istringstream is()

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

/******************/

ll arr[100010];
ll fre[100010];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    int test,Case,n,m;
    ll ans;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(m);
        Clear(fre,0);

        for(int i=0;i<n;i++)
        {
            read(arr[i]);

            if(i)
                arr[i] = (arr[i]+arr[i-1])%m;
            else
                arr[i]%=m;

            fre[arr[i]]++;
        }

        ans = fre[0]; // all single element that div by m

       // cout<<ans<<endl;

        //start from p ,, end with p

        for(int i=0;i<n;i++)
        {
            fre[arr[i]]--;
            ans+= fre[arr[i]];
        }

        printf("Case %d: %lld\n",Case,ans);
    }

    return 0;
}

