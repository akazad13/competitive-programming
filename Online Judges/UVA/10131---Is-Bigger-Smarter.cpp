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
#define mp make_pair

#define Clear(a,b) memset(a,b,sizeof(a))

#define  inf -12200

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

struct node
{
    int ind;
    int first, second;

    node(int a, int b, int c)
    {
        ind=a; first=b; second = c;
    }
};

vector< node > vec;
int len;
int dir[1005];
int dp[1005];


int LIS(int u)
{
    if(dp[u]!=-1) return dp[u];
    int Max = 0;

    for(int v= u+1;v<len;v++)
    {
        if(vec[u].first<vec[v].first && vec[u].second>vec[v].second)
        {
            int ret = LIS(v);
           // cout<<v<<" "<<ret<<endl;
            if(ret>Max)
            {
                Max = ret;
                dir[u]=v;
                //cout<<u<<" "<<v<<endl;
            }
          /*  else if(ret==Max)
            {
                if(vec[dir[u]].ind>vec[v].ind)
                {
                    cout<<u<<" "<<v<<endl;
                    dir[u]=v;
                }
            }*/
        }
    }

    dp[u] = Max+1;

    return dp[u];
}

bool cmp(node a, node b)
{
    if(a.first==b.first)
    {
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main()
{
    //freopen("inp.txt","r",stdin);
   // freopen("out.txt","w",stdout);


    int n,m,i;
    int cnt=0;
    while(read(n))
    {
        cnt++;
        read(m);
         vec.pb(node(cnt,n,m));
    }

    //cout<<vec[0].first<<" "<<vec[1].first<<endl;

    Clear(dir,-1);
    Clear(dp,-1);

    sort(vec.begin(),vec.end(),cmp);

    len= vec.size();

   /* for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i].ind<<" "<<vec[i].first<<" "<<vec[i].second<<endl;
    }*/



    int Max=-23;
    int start = -23;
    for(int i=0;i<len;i++)
    {
        int ret = LIS(i);

        if(ret>Max)
        {
            Max=ret;
            start=i;
        }
    }


    printf("%d\n",Max);

    //vector<int> ans;
   // ans.pb(vec[start].ind);

    printf("%d\n",vec[start].ind);

	while(dir[start]!=-1)
	{
		//printf("%d\n",start+1);
		start=dir[start];//cout<<vec[start].ind<<endl;
		printf("%d\n",vec[start].ind);

       // ans.pb(vec[start].ind);

	}

	/*sort(ans.begin(),ans.end());

	cout<<"ok"<<endl;

	rep(i,0,Max)
        printf("%d\n",ans[i]);*/


    return 0;
}
