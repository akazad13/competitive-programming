#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max  10002
#define Clear(a,b) memset(a,b,sizeof(a))
#define PP pair<int,int>
#define mp(a,b) make_pair(a,b)

vector<int> G[Max]; //Directed graph
int color[Max];
int Time;
vector< pair<int,int> > vec;


void DFS_visit(int u)
{
    color[u]=1;

    Time++;

    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if(color[v]==0)
        {
            DFS_visit(v);
        }
    }

    Time++;
    color[u]=2;

    vec.push_back( mp(Time,u));
}

bool cmp(PP a, PP b)
{
    return a.first>b.first;
}


int main()
{
    int test,vertex,edge,u,v;
    scanf("%d",&test);

    for(int Case = 1;Case<=test;Case++)
    {

        scanf("%d %d",&vertex,&edge);

        for(int i=1;i<=vertex;i++)
            G[i].clear();

        for(int i=0;i<edge;i++)
        {
            scanf("%d %d",&u,&v);
            G[u].push_back(v);

        }

        Clear(color,0);
        vec.clear();
        Time=0;

        for(int i=1;i<=vertex;i++)
        {
            if(color[i]==0)
            {
                DFS_visit(i);
            }
        }
        sort(vec.begin(),vec.end(),cmp);

        printf("Case %d: ",Case);

        Clear(color,0);
        Time=0;

        int cnt=0;

        for(int i=0;i<vertex;i++)
        {
            u = vec[i].second;
            if(color[u]==0)
            {
                cnt++;
                DFS_visit(u);
            }
        }

        printf("%d\n",cnt);
    }
    return 0;
}


