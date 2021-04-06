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

/***************************/

ll freq[26];
ll fact[21];
ll n, len;
char str[25];

ll ways()
{
    ll dom=1;
    ll up=0;
    for(int i=0;i<26;i++)
    {
        if(freq[i])
        {
            up+=freq[i];
            dom*=fact[freq[i]];
        }
    }

    return fact[up]/dom;
}

void solve()
{
    if(ways()<n)
    {
        printf("Impossible\n");
        return ;
    }

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(freq[j])
            {
                freq[j]--; // take it and calculate others permutation

                ll p=ways();

                if(p>=n)
                {
                    printf("%c",j+'a');
                    break;
                }
                else
                {
                    n-=p;
                    freq[j]++; //do not take the char, instead permute that
                }

            }
        }
    }

    printf("\n");
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //ios_base::sync_with_stdio(false); cin.tie(0);

    fact[0]=1;

    for(ll i=1;i<=20;i++)
    {
        fact[i] = i*fact[i-1];
    }

    int test,Case;
    scanf("%d",&test);
    rep(Case,1,test+1)
    {
        scanf(" %s %lld",str,&n);

        len =strlen(str);
        Clear(freq,0);

        for(int i=0;i<len;i++)
        {
            freq[str[i]-'a']++;
        }

        printf("Case %d: ",Case);

        solve();
    }

    return 0;
}

