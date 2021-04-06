#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
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
    int x,y;
};

point arr[20];

inline int Set(int N, int pos)
{
    return N= N|(1<<pos);
}

inline int Reset(int N, int pos)
{
    return N= N & ~(1<<pos);
}

inline bool check(int N, int pos)
{
    return (bool) (N&(1<<pos));
}
int n;
int dp[1<<16];

int solve(int mask)
{
    if(mask==(1<<n)-1)
        return 0;
    if(dp[mask]!=-1) return dp[mask];

    int ret=INT_MAX;
    vector<int> vec;

    for(int i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            mask = Set(mask,i);
            vec.clear();
            double del;
            for(int j=0;j<n;j++)
            {

                if(check(mask,j)==0)
                {
                     del = (arr[j].y-arr[i].y)/((arr[j].x-arr[i].x)*1.0);
                    vec.push_back(j);
                    break ;
                }
            }

            if(vec.size()!=0)
            {
                for(int j=vec[0]+1;j<n;j++)
                {
                    if(check(mask,j)==0)
                    {
                        double temp = (arr[j].y-arr[i].y)/((arr[j].x-arr[i].x)*1.0);
                        if(temp==del)
                            vec.push_back(j);
                    }
                }
            }
            for(int j =0;j<vec.size();j++)
            {
                mask = Set(mask,vec[j]);
            }
            ret = min(ret,solve(mask)+1);

            mask = Reset(mask,i);

            for(int j =0;j<vec.size();j++)
            {
                mask = Reset(mask,vec[j]);
            }
        }
    }

    return dp[mask]=ret;
}


int main()
{
    int test,i,j,Case;
    read(test);
    rep(Case,1,test+1)
    {
        read(n);
        Clear(dp,-1);
        rep(i,0,n)
        {
            read(arr[i].x);
            read(arr[i].y);
        }
        int ret = solve(0);

        printf("Case %d: %d\n",Case,ret);
    }
    return 0;
}


