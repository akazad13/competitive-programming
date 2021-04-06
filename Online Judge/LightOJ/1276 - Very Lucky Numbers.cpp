#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>

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
/************************************/

VL vec;
VL vec2;

set<lld> S;

#define Max 1000000000000

void backtrack(int ind, lld sum)
{
    //cout<<ind<<endl;
    if(sum>Max)
        return ;
    if(sum<=Max && sum>1)
    {
        S.insert(sum);
    }

    if(ind>=vec2.size())
    {
        if(sum<=Max && sum>1)
        {
            S.insert(sum);
        }

        return ;
    }

    if(sum<=(Max/vec2[ind]))
        backtrack(ind,sum*vec2[ind]);
    if(sum<=(Max/vec2[ind]))
        backtrack(ind+1,sum);
    if(sum<=(Max/vec2[ind]))
        backtrack(ind+1,sum*vec2[ind]);

    return ;

}

int main()
{
    vec.pb(4);
    vec.pb(7);

    lld arr[2]={4,7};

    int st=0;
    int j=1;
    while(1)
    {
        for(int i=st;i<(1<<j);i++)
        {
            lld p = vec[i];
            for(int kk = 0;kk<2;kk++)
            {
                vec.pb(p*10+arr[kk]);
            }
        }
        st = 1<<j;
        j++;

        if(vec[st-1]>Max)
            break ;
    }

    int len = vec.size();

    for(int i=0;i<len;i++)
    {
        if(vec[i]<=Max)
            vec2.pb(vec[i]);
    }

    vec.clear();
    backtrack(0,1);

    set<lld> :: iterator it;

    for(it=S.begin();it!=S.end();it++)
    {
        vec.pb(*it);
    }

    int test,i,Case,n,m;
    lld a,b;
    read(test);
    rep(Case,1,test+1)
    {
        read(a); read(b);

        lld ans = lower_bound(vec.begin(),vec.end(),b+1) - lower_bound(vec.begin(),vec.end(),a);
        printf("Case %d: %lld\n",Case,ans);
    }
    return 0;
}

