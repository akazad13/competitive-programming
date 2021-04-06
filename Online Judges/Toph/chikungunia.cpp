#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
ull  prime=31;

ull HASH[1000010];
ull primeVal[1000010];
vector<ull> Map;


int main()
{

    primeVal[0]=1;
    for(int i=1;i<=1000000;i++)
    {
        primeVal[i] = (primeVal[i-1]*prime);
    }


    int n, m;

    scanf("%d %d",&n,&m);

    char str[n+1][m+1];

    for(int i= 0; i <n; i++)
    {
        scanf("%s",&str[i]);
    }



    for(int i=0;i<n;i++)
    {
        HASH[i]=0;
        for(int j=0;j<m;j++)
        {
            HASH[i] = (HASH[i]+str[i][j]*primeVal[j]);

        }
       Map.push_back(HASH[i]);
    }

    sort(Map.begin(),Map.end());


    ull ans = 0;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ull p = str[i][j];

            for(ull k = 'a'; k<='z';k++)
            {
                if(k==p) continue;

                // subtract old value
                ull t1 = (p*primeVal[j]);

                ull H = (HASH[i]-t1);

                // add new val
                H = (H+(k)*primeVal[j]);

               ull kk = lower_bound(Map.begin(),Map.end(),H+1) - lower_bound(Map.begin(),Map.end(),H);

                ans+= kk;
            }

        }
       // Map.erase(Map.lower_bound (HASH[i]));

    }

    printf("%llu\n",ans/2);
    return 0;
}
