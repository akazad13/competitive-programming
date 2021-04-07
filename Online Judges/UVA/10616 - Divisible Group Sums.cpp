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

int n;
int k;
int Div;
int query;
int arr[205];
lld dp[202][12][22];
vector<int> vec;


int sum(int a, int b)
{
    long long int ans = a + b;
    ans %= Div;
    if (ans < 0)
        ans += Div;
    return (int)ans;
}

lld solve(int ind, int take, int val)
{
    if(take==k)
    {
        //cout<<val<<endl;
        if(val%Div==0)
            return 1;
        else
            return 0;
    }

    if(ind>=n)
    {
        //cout<<val<<" "<<k<<endl;
        if(take==k && val%Div==0)
            return 1;
        else
            return 0;
    }

    lld ret1=0;
    lld ret2=0;

    if(dp[ind][take][val]!=-1)
        return dp[ind][take][val];
    ret1 = solve(ind+1,take+1,sum(val,vec[ind]));

    ret2 = solve(ind+1,take,val);

    return dp[ind][take][val]=ret1+ret2;
}


int main()
{
   // freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int i,j;
    int cnt=1;

    while(scanf("%d",&n)==1)
    {
        read(query);

        if(!n && !query)
            break ;

        rep(i,0,n)
            read(arr[i]);
        //cout<<"Ok"<<endl;
        printf("SET %d:\n",cnt++);

        rep(i,1,query+1)
        {
            read(Div); read(k);
            Clear(dp,-1);
            printf("QUERY %d: ",i);

            vec.clear();

            rep(j,0,n)
            {
                int p = arr[j]%Div;
                vec.pb(p);
            }

            rep(j,0,n)
            {
                if(vec[j]<0)
                    vec[j]+=Div;
                //vec.pb(arr[i]%Div);
            }


            lld ret = solve(0,0,0);
            printf("%lld\n",ret);
        }
    }


    return 0;
}


