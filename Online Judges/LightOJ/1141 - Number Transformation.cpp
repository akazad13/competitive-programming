#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 1000
vector<int> vec;
bool prime[max+10];
int priLis[max+10];
bool vis[2*max];
int step[max+10];
int cnt=0;


void sieve()
{
    int i,j;
    for(i=4;i<=max;i+=2)
        prime[i]=1;

    long long int s=sqrt(max);
    for(i=3;i<=s;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=max;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[1]=prime[0]=1;

    for(int i=2;i<max;i++)
    {
        if(prime[i]==0)
            priLis[cnt++]=i;
    }
}

int bfs(int n,int make)
{
    memset(vis,0,sizeof(vis));
    memset(step,0,sizeof(step));
    queue<int>Q;
    Q.push(n);
    vis[n]=1;
    step[n]=0;

    while(!Q.empty())
    {
        vec.clear();
       int p = Q.front(); Q.pop();

        if(p==make)
            return step[p];
        if(p>make)
            continue ;
        if(prime[p]==0)
            continue;
        int nn = p;
        for(int i=0;i<cnt && priLis[i]*priLis[i]<=nn;i++)
        {
            if(nn%priLis[i]==0){
            while(nn%priLis[i]==0)
            {
                nn/=priLis[i];
            }
            vec.push_back(priLis[i]);
            }
        }
        if(nn>1)
            vec.push_back(nn);

        for(int i=0;i<vec.size();i++)
		{
		    int v=vec[i];
		    if((p+v)<=make && vis[p+v]!=1)
            {
                vis[p+v]=1;
                step[p+v]=step[p]+1;
                Q.push(p+v);
            }
		}
    }
    return -1;
}


int main()
{
    sieve();
    int test,a,b,n;
    scanf("%d",&test);
    for(int T=1;T<=test;T++)
    {
        scanf("%d %d",&a,&b);

        if(a==b)
        {
            printf("Case %d: %d\n",T,0);
        }
        else if(prime[a]==0)
        {
            printf("Case %d: -1\n",T);
        }
        else
            printf("Case %d: %d\n",T,bfs(a,b));
    }

    return 0;
}
