#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))

int main()
{

    int test,i,j,Case,n,p,res;
    int arr[10];
    read(test);
    rep(Case,1,test+1)
    {
        arr[0]=arr[1]=arr[2]=1;
        arr[3]=arr[4]=arr[5]=2000;
        read(n);
        res=0;

        rep(i,0,n)
        {
            rep(j,0,3)
            {
                read(p);
                if(arr[j]<p)
                    arr[j]=p;
            }
            rep(j,3,6)
            {
                read(p);
                if(arr[j]>p)
                    arr[j]=p;
            }
        }

        if(arr[0]<arr[3] && arr[1]<arr[4] && arr[2]<arr[5])
        {
            res = (arr[3]-arr[0])*(arr[4]-arr[1])*(arr[5]-arr[2]);
        }

        printf("Case %d: %d\n",Case,res);

    }

    return 0;
}

