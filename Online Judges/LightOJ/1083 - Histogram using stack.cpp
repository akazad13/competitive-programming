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

#define Max 30010
ll arr[Max];

stack<ll> stk;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    int test,i,j,Case,n,m;
    read(test);
    rep(Case,1,test+1)
    {
        read(n);

        rep(i,0,n)
        {
            read(arr[i]);
        }

        ll maxArea=0, curInd=0;

        int i=0;

        for(;i<n;i++)
        {
            if(stk.empty())
            {
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && arr[stk.top()]>arr[i] )
                {
                    curInd = stk.top();
                    stk.pop();

                    if(stk.empty())
                    {
                        maxArea = max( maxArea, (i)*arr[curInd]);
                    }
                    else
                        maxArea = max( maxArea, (i-stk.top()-1)*arr[curInd]);
                   // cout<<maxArea<<" "<<i<<" "<<curInd<<endl;
                }

                stk.push(i);
            }

        }

        if(!stk.empty())
        {
            while(!stk.empty())
            {
                    curInd = stk.top();
                    stk.pop();

                    if(stk.empty())
                    {
                        maxArea = max( maxArea, (i)*arr[curInd]);
                    }
                    else
                        maxArea = max( maxArea, (i-stk.top()-1)*arr[curInd]);
                  //  cout<<maxArea<<" "<<i<<" "<<curInd<<endl;
            }
        }

        printf("Case %d: %lld\n",Case,maxArea);


    }

    return 0;
}
