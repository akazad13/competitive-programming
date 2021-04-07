#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define pi pair<int,int>
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


vector<int> vec[102];
int vis[102];
int n,m;

int cnt;

void dfs(int u)
{
    vis[u]=1;
   // cout<<vec[u].size<<endl;
    for(int i=0;i<vec[u].size();i++)
    {
        int v = vec[u][i];



        if(vis[v]==0)
        {
            dfs(v);
        }
    }

}


int main()
{
    //freopen("inp.txt","r",stdin);

    int test,i,j,Case,p;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        rep(i,0,101)
            vec[i].clear();
        rep(i,1,n+1)
        {
            read(m);
            rep(j,0,m)
            {
                read(p);
                vec[i].push_back(p);
            }
        }

        int maxDep = -23;
        int ind=-12;

        rep(i,1,n+1)
        {
            Clear(vis,0);
            cnt=0;
            //cout<<i<<endl;
            dfs(i);

            for(int j=1;j<=n;j++)
            {
                cnt+=vis[j];
            }

            if(cnt>maxDep)
            {
                ind=i;
                maxDep=cnt;
            }
        }

      //  cout<<maxDep<<endl;

        printf("%d\n",ind);
    }

    return 0;
}

