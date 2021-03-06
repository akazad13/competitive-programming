#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 100010
#define Clear(a,b) memset(a,b,sizeof(a))
#define PP pair<int,int>
#define ma(a,b) make_pair(a,b)

vector<int> G[Max]; //Directed graph
int color[Max];
int d[Max];
vector< PP > f;
//int parent[Max];
int Time;
int cnt;

void DFS_visit(int u)
{
    //PP = m;
    color[u]=1;
    Time=Time+1;
    d[u]=Time;

    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if(color[v]==0)
        {
            //parent[v]=u;
            DFS_visit(v);
        }
    }
    color[u]=2;
    Time = Time +1 ;
    f.push_back(ma(Time,u));
    return ;
}


void DFS(int vertex)
{
        Clear(color,0);
       // Clear(parent,-1);
        Time=0;

        for(int i=0;i<vertex;i++)
        {
            int u = f[i].second;
            if(color[u]==0)
            {
                cnt++;
                DFS_visit(u);
            }
        }
        return ;
}

bool cmp(PP a, PP b)
{
    return a.first>b.first;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,vertex,edge,u,v;
    scanf("%d",&test);

    for(int Case = 1;Case<=test;Case++)
    {
        scanf("%d %d",&vertex,&edge);
        for(int i=0;i<=vertex;i++)
            G[i].clear();
        f.clear();

        for(int i=0;i<edge;i++)
        {
            scanf("%d %d",&u,&v);
            G[u].push_back(v);


        }
        cnt=0;

        Clear(color,0);
      //  Clear(parent,-1);
        Time=0;

        for(int i=1;i<=vertex;i++)
        {
            if(color[i]==0)
            {
                DFS_visit(i);
            }
        }

        //DFS(vertex);

        sort(f.begin(),f.end(),cmp);

        cnt=0;

        DFS(vertex);

        printf("%d\n",cnt);

       /* for(int i=0;i<vertex;i++)
        {
            printf("%d  %d| ",f[i].first,f[i].second);
        }*/


    }
    return 0;
}
