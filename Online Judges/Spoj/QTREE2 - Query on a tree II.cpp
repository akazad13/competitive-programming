//LCA 

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 10010
#define pb push_back
#define inf 1000000000

vector<int> g[Max];
vector<int> cost[Max];
int L[Max];
int par[Max][25];
int T[Max];
int C[Max];
long long int parC[Max][25];

struct node
{
    int lca;
    long long int tcost;
};

void dfs(int u, int from, int depth)
{
    L[u]=depth;
    T[u]=from;

    for(int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if(v!=from)
        {
            C[v]=cost[u][i];
            dfs(v,u,depth+1);
        }
    }
}

void init_lca(int n)
{
    memset(par,-1,sizeof(par));

    for(int i=0;i<n;i++)
    {
        par[i][0]=T[i];
    }

    for(int j=1;(1<<j)<n ; j++)
    {
        for(int i=0;i<n;i++)
        {
            if(par[i][j-1]!=-1)
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;(1<<j)<n;j++)
            cout<<par[i][j]<<" ";
        cout<<endl;
    }*/
}

void init_cost(int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<22;j++)
            parC[i][j]=0;
    }

    for(int i=0;i<n;i++)
    {
        parC[i][0]=C[i];
    }

    for(int j=1;(1<<j)<n ; j++)
    {
        for(int i=0;i<n;i++)
        {
            if(par[i][j-1]!=-1 && par[i][j]!=-1)
            {
                parC[i][j] += parC[i][j-1]+parC[par[i][j-1]][j-1];
               // cout<<parC[i][j]<<endl;
            }
            else
            {
                parC[i][j]=inf;
            }

        }
    }


    /*for(int i=0;i<n;i++)
    {
        for(int j=0;(1<<j)<n;j++)
            cout<<parC[i][j]<<" ";
        cout<<endl;
    }*/
}


node lca_query(int n, int p, int q)
{
    if(L[p]<L[q])
        swap(p,q);
    int log = 1;

    node a;

    a.tcost=0;

    while(1)
    {
        int nxt = log+1;

        if((1<<nxt) > L[p]) break ;
        log++;
    }

    for(int i=log;i>=0;i--)
    {
        if(L[p]-(1<<i) >=L[q])
        {
            a.tcost+=parC[p][i];
            p = par[p][i];
        }
    }

    if(p==q)
    {
        //return p;
        a.lca=p;
       // return sum;
       return a;
    }

   // cout<<sum<<endl;

    for(int i=log; i>=0 ;i--)
    {
        if(par[p][i]!=-1 && par[p][i]!=par[q][i])
        {
            a.tcost+=parC[p][i];
           // cout<<sum<<endl;
            a.tcost+=parC[q][i];
           // cout<<sum<<endl;
            p = par[p][i];
            q = par[q][i];
        }
    }

    //return T[p];
    //return sum+parC[p][0]+parC[q][0];
    a.tcost+=parC[p][0]+parC[q][0];
    a.lca=T[p];

    return a;
}

int nth_find(int n,int p, int q,int lca, int nth)
{
    int pth_level = L[p]-L[lca];
    int qth_level = L[q]-L[lca];

    //if(nth==1)
    //    return p;

    if(pth_level>=nth)
    {
        nth-=1;

        while(nth>0)
        {
            int log = log2(nth);
            //cout<<nth<<endl;
            p = par[p][log];
            nth-=(1<<log);
        }
        return p;
    }
    else if(nth==pth_level+1)
    {
        return lca;
    }
    else
    {
        qth_level -= (nth-pth_level-1);
        int log = log2(qth_level);
        for(int i=log ;i>=0;i--)
        {
            if(qth_level- (1<<i)>=0)
            {
                q = par[q][i];
                qth_level-= (1<<i);
            }
        }

        return q;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);


    int n,test;
    int u,v,c;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);

        for(int i=0;i<n+1;i++)
        {
            g[i].clear();
            cost[i].clear();
        }

        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            u--;
            v--;
            g[u].pb(v);
            g[v].pb(u);
            cost[u].pb(c);
            cost[v].pb(c);
        }

        dfs(0,-1,0);

        init_lca(n);
        init_cost(n);

        char str[10];
        int nth;


        while(scanf(" %s",str)==1)
        {
            if(strcmp(str,"DONE")==0)
                break;
            else if(strcmp(str,"DIST")==0)
            {
                scanf("%d %d",&u,&v);
                u--;
                v--;
                node ret = lca_query(n,u,v);
                printf("%lld\n",ret.tcost);
            }
            else
            {
                scanf("%d %d %d",&u,&v,&nth);
                u--;v--;
                node ret = lca_query(n,u,v);

                int res = nth_find(n,u,v,ret.lca,nth);

                printf("%d\n",res+1);
            }
        }

        printf("\n");
    }

    return 0;
}
