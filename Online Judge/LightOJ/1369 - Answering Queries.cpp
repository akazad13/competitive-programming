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

lld arr[100010];
lld mul[100010];

int main()
{
    int test,i,j,Case,n,m,ch,ind,val;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(m);
        rep(i,0,n)
        {
            read(arr[i]);
            mul[i]=0;
        }


        rep(i,0,n/2)
        {
            mul[i]=n-1-(2*i);
            mul[n-i-1]=-1*mul[i];
        }

        lld sum=0;
        rep(i,0,n)
        {
            sum+=arr[i]*mul[i];
        }

        printf("Case %d:\n",Case);

        while(m--)
        {
            read(ch);
            if(ch==1)
            {
                printf("%lld\n",sum);
            }
            else
            {
                read(ind); read(val);

                sum-=arr[ind]*mul[ind];
                arr[ind]=val;
                sum+=arr[ind]*mul[ind];
            }
        }
    }

    return 0;
}

