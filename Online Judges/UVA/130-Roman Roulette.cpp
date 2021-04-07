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


int main()
{
    //freopen("input.txt","r",stdin);

    int test,i,j,Case;
    int arr[101];
    int n, k;
    while(read(n))
    {
        read(k);

        if(n==0 && k==0)
            break ;

        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
                arr[i]=i;

            int p =n;
            bool vis[101]={0};
            bool flag=0;

            int cnt=0;
            int ind;
            i=j;
            while(1)
            {
                if(p==1)
                    break ;
                if(vis[i]==0)
                    cnt++;
                if(cnt==k)
                {
                    if(flag==0)
                    {
                        vis[i]=1;
                        p--;
                        flag=1;
                        ind=i;
                        i = (i+1)%n;
                    }
                    else
                    {
                        //cout<<arr[i]<<" "<<i<<endl;
                        arr[ind] = arr[i];
                        vis[ind] = 0;
                        vis[i]=1;
                        flag=0;

                        i = (ind+1)%n;
                    }
                    cnt=0;
                }
                else
                {
                    i = (i+1)%n;
                }

            }

            for(int i=0;i<n;i++)
            {
                if(arr[i]==0 && vis[i]==0)
                {
                    printf("%d\n",j+1);
                    break ;
                }
            }

        }

    }

    return 0;
}



