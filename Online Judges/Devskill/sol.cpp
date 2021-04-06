#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define lld long long


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


    int test,n;
    int arr[10010];
    int sol[10010];
    read(test);

    for(int Case=1;Case<=test;Case++)
    {
        //printf("Case %d: ",Case);
        read(n);

       for(int i=0;i<n;i++)
            read(arr[i]);
       for(int i=0;i<n;i++)
            read(sol[i]);

        int cnt=0;
        int ind=0;
        bool flag=0;

       for(int i=0;i<n;i++)
       {

            if(sol[ind]==arr[i])
            {
                cnt++;
                ind++;
            }

       }

        printf("Case %d: %d\n",Case,n-cnt);
    }

    return 0;
}




