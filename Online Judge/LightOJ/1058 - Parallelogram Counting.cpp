#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define mp(a,b) make_pair(a,b)

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

struct point
{
    double x,y;
};

point arr[1002];
vector< pair<lld, lld > > vec;

int main()
{
    int test,i,j,Case,n;
    read(test);
    rep(Case,1,test+1)
    {
        read(n);

        vec.clear();

        rep(i,0,n)
        {
            scanf("%lf %lf",&arr[i].x, &arr[i].y);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               vec.pb(mp((arr[i].x+arr[j].x),(arr[i].y+arr[j].y)));
            }
        }

        sort(vec.begin(),vec.end());

        lld cnt=1;
        lld res=0;

        n = vec.size();

        for(int i=1;i<n;)
        {
            if(vec[i-1]==vec[i])
            {
                cnt++;
                i++;
            }
            else
            {
                res+=((cnt*(cnt-1))/2);
                cnt=1;
                i++;
            }
        }

        res+=((cnt*(cnt-1))/2);

        printf("Case %d: %lld\n",Case,res);
    }
    return 0;
}

