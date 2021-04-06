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

lld arr[20];
VL a,b;

int main()
{

    int test,i,j,Case,m,n;
    lld k;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(k);
        a.clear();
        b.clear();


        rep(i,0,n)
            read(arr[i]);

        m = n/2;
        n = n-m;

        int lim1=1;
        int lim2=1;

        rep(i,0,n)
            lim1 = lim1*3;

        rep(i,0,m)
            lim2 = lim2*3;

        for(int i=0;i<lim1;i++)
        {
            int p=i;

            lld sum=0;
            j=0;

            while(p)
            {
                sum+=(arr[j])*(p%3);
                p/=3;
                j++;

            }
            a.pb(sum);
        }

        lim1 = a.size();

        for(int i=0;i<lim2;i++)
        {
            int p=i;

            lld sum=0;
            j=0;

            while(p)
            {
                sum+=(arr[n+j])*(p%3);
                p/=3;
                j++;

            }
            b.pb(sum);
        }

        lim2 = b.size();

        sort(b.begin(),b.end());

        bool flag=1;

        printf("Case %d: ",Case);

        for(int i=0;i<lim1;i++)
        {
            lld  p = k-a[i];

            if(binary_search(b.begin(),b.end(),p))
            {
                printf("Yes\n");
                flag=0;
                break;
            }
        }

        if(flag)
            printf("No\n");
    }
    return 0;
}

