#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max  10002
#define Clear(a,b) memset(a,b,sizeof(a))
#define PP pair<int,int>
#define ma(a,b) make_pair(a,b)

vector<int> G[Max]; //Directed graph
int color[Max];
map<string ,int > Map;
int cnt;
bool cycle;

int mapping(string str)
{
    if(Map[str]==0)
    {
        Map[str]=cnt;
        cnt++;
    }

    return Map[str];
}

void DFS_visit(int u)
{
    color[u]=1;

    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if(color[v]==0)
        {
            DFS_visit(v);
        }
        else if(color[v]==1)
        {
            cycle = true;
            return ;
        }
    }
    color[u]=2;
}


void DFS()
{
    Clear(color,0);

    for(int i=1;i<cnt;i++)
    {
        if(color[i]==0)
        {
            DFS_visit(i);
        }
    }
}

int main()
{
    int test,vertex,edge,u,v;
    char frm[100], to[100];
    scanf("%d",&test);

    for(int Case = 1;Case<=test;Case++)
    {

        Map.clear();
        scanf("%d",&edge);

        for(int i=1;i<=cnt;i++)
            G[i].clear();

        cnt=1;

        for(int i=0;i<edge;i++)
        {
            scanf(" %s %s",frm,to);
            u = mapping(frm);
            v = mapping(to);

            G[u].push_back(v);

        }

        printf("Case %d: ",Case);
        cycle = false ;

        DFS();

        if(cycle)
            printf("No\n");
        else
            printf("Yes\n");

    }
    return 0;
}

