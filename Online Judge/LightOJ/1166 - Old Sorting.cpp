#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define read(a) scanf("%d",&a)

int main()
{
    int test,i,j,Case;
    int n,arr[110],cnt;
    read(test);
    rep(Case,1,test+1)
    {
        read(n);
        cnt=0;
        rep(i,0,n)
        {
            read(arr[i]);
        }
        int ind;

        rep(i,1,n)
        {
            ind=0;
            rep(j,0,n)
            {
                if(arr[j]==i)
                    ind=j;
            }
            if(ind!=i-1)
            {
                cnt++;
                swap(arr[ind],arr[i-1]);
            }
        }
        printf("Case %d: %d\n",Case,cnt);

    }

    return 0;
}

