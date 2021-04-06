#include<iostream>
#include<bits/stdc++.h>

using namespace std;

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


    int test,n,m;
    int cost[2001];
    int freq[1002];
    //scanf("%d",&test);
    read(test);

    for(int Case=1;Case<=test;Case++)
    {
        memset(freq,0,sizeof(freq));
        read(m); read(n);
        vector<int>  sol;

        for(int i=0;i<n;i++)
        {
            read(cost[i]);
            freq[cost[i]]++;
        }

        printf("Case %d:",Case);
        bool flag=0;

        for(int i=0;i<n;i++)
        {
            freq[cost[i]]--;
            for(int j=i+1;j<n;j++)
            {
                freq[cost[j]]--;

                int rest= m-cost[i]-cost[j];

                if(rest>0 && freq[rest])
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if(rest==cost[k])
                        {
                            printf(" %d %d %d\n",i+1,j+1,k+1);
                            flag=1;
                            break;
                        }
                    }
                }

                if(flag) break;
                freq[cost[j]]++;
            }

            if(flag) break;
            freq[cost[i]]++;
        }





        if(!flag)
            printf(" You are out of your luck!\n");
    }

    return 0;
}


