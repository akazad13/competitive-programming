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

int n,k;
int arr[1002];

bool func(int val)
{
    int cnt=0;

    int p =val;
    bool flag=1;

    for(int i=0;i<n;)
    {
        if(flag && p<arr[i])
        {
            return 0;
        }
        if(p>=arr[i])
        {
            p-=arr[i];

            if(flag)
            {
                cnt++;
                flag=0;
            }
            i++;
        }
        else
        {
            p = val ;
            flag=1;
        }
    }

    if(cnt<=k)
        return 1;
    else
        return 0;
}

int bin_search()
{
    int low = 1;
    int high = n*10000;

    int mid;

    while(low<=high)
    {
        mid = (low+high)>>1;

        bool res = func(mid);
        if(res==1)
            high = mid-1;
        else
            low = mid+1;
    }

    return low;
}
int main()
{
    int test,i,j,Case;
    read(test);
    rep(Case,1,test+1)
    {
        read(n); read(k);
        n++; k++;

        rep(i,0,n)
        {
            read(arr[i]);
        }

        int ret = bin_search();
        printf("Case %d: %d\n",Case,ret);

        int cnt=0;
        int sum = 0;
        bool flag=1;
        int q=n;
        i = 0;
        sum = 0;
        while(k)
        {
           if(sum+arr[i]<=ret)
           {
               sum+=arr[i];
               i++;
               n--;
           }
           else
           {
               printf("%d\n",sum);
               sum=0;
               k--;
           }

           if(n<k)
           {
               if(sum)
               {
                   printf("%d\n",sum);
                    break ;
               }
           }

        }

        for(int m = i ; m<q;m++)
            printf("%d\n",arr[m]);

    }

    return 0;
}

