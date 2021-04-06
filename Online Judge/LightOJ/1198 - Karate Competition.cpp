#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define fileRead(a) freopen("a","r",stdin)

#define read(a) scanf("%d",&a)
#define Lread(a) scanf("%lld",&a)
#define Uread(a) scanf("%llu",&a)
#define Dread(a) scanf("%lf",&a)
#define write(a) printf("%d\n",a)
#define Case(a) printf("Case %d: ",a)

#define Clear(a,b) memset(a,b,sizeof(a))


bool cmp(int a, int b)
{
    return a>b;
}

int main()
{

    int test,i,j,Case,n;
    bool vis1[60],vis2[60];
    int my[60],opo[60];

    read(test);
    rep(Case,1,test+1)
    {
        Clear(vis1,0);
        Clear(vis2,0);
        read(n);
        rep(i,0,n)
            read(my[i]);
        rep(i,0,n)
            read(opo[i]);
        sort(my,my+n);
        sort(opo,opo+n,cmp);

        int res=0;

        rep(i,0,n)
        {
            rep(j,0,n)
            {
                if(my[i]>opo[j] && vis2[j]==0)
                {
                    vis2[j]=1;
                    vis1[i]=1;
                    res+=2;
                    break ;
                }
            }

        }

        rep(i,0,n)
        {
            if(vis1[i]==0)
            {
                rep(j,0,n)
                {
                    if(vis2[j]==0 && my[i]==opo[j])
                    {
                        res++;
                        vis1[i]=1;
                        vis2[j]=1;
                        break ;
                    }
                }
            }
        }

        printf("Case %d: %d\n",Case,res);
    }

    return 0;
}


