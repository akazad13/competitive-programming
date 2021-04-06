#include<iostream>
#include<bits/stdc++.h>

#define ll long long int
#define lim 1010
#define Clear(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define inf 100000000
#define mp make_pair

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


//0 based
vector<int> adj[lim]; //2*lim for true and false argument(only adj should be cleared)
int col[lim],low[lim],desc[lim],timer;
int group_id[lim],components;//components=number of components, group_id = which node belongs to which node
stack<int>S;

void scc(int u)
{
    int i,v,now;
    col[u]=1;
    low[u]=desc[u]=timer++;
    S.push(u);

    int len = adj[u].size();

    for(int i=0;i<len;i++)
    {
        v=adj[u][i];
        if(col[v]==1)
            low[u]=min(low[u],desc[v]);
        else if(col[v]==0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }

    //SCC checking...
    if(low[u]==desc[u]) //find head and hence component
    {
        do
        {
            now=S.top();S.pop();
            group_id[now]=components;  // give component number
            col[now]=2; //Completed...
        }while(now!=u);

        components++; // this number component done... next number
    }
}

int TarjanSCC(int n) //n=nodes (some change may be required here)
{
    int i;
    timer=components=0;
    Clear(col,0);

    while(!S.empty())
        S.pop();

    for(int i=0;i<n;i++)
    {
        if(col[i]==0)
            scc(i);
    }
}


const int maxnodes = lim*2+10;

int nodes = maxnodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];

struct Edge {
  int to, rev;
  int f, cap;
};

vector<Edge> g[maxnodes];

void addEdge(int s, int t, int cap){
  Edge a = {t, g[t].size(), 0, cap};
  Edge b = {s, g[s].size(), 0, 0}; // rev
  g[s].push_back(a);
  g[t].push_back(b);
}

bool dinic_bfs() {
  fill(dist, dist + nodes, -1);
  dist[src] = 0;
  int qt = 0;
  q[qt++] = src;
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int j = 0; j < (int) g[u].size(); j++) {
      Edge &e = g[u][j];
      int v = e.to;
      if (dist[v] < 0 && e.f < e.cap) {
        dist[v] = dist[u] + 1;
        q[qt++] = v;
      }
    }
  }
  return dist[dest] >= 0;
}

int dinic_dfs(int u, int f) {
  if (u == dest)
    return f;
  for (int &i = work[u]; i < (int) g[u].size(); i++) {
    Edge &e = g[u][i];
    if (e.cap <= e.f) continue;
    int v = e.to;
    if (dist[v] == dist[u] + 1) {
      int df = dinic_dfs(v, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int maxFlow(int _src, int _dest) {
  src = _src;
  dest = _dest;
  int result = 0;
  while (dinic_bfs()) {
    fill(work, work + nodes, 0);
    while (int delta = dinic_dfs(src, INT_MAX))
      result += delta;
  }
  return result;
}
void MakeNewDAG_Graph(int n)
{
    int u,v;

    for(int i=0;i<=2*components+1;i++)
        g[i].clear();

    int source = 2*components;
    int sink = source+1;


    for(int i=0;i<n;i++)
    {
        int Size = adj[i].size();;
        for(int j=0;j<Size;j++)
        {
            u=group_id[i];
            v=group_id[adj[i][j]];

            if(u!=v)
            {
                addEdge(u,components+v,inf);

                //cout<<u<<" "<<components+v<<endl;


            }
        }
    }

    for(int i=0;i<components;i++)
    {
        addEdge(source,i,1);
        addEdge(components+i,sink,1);
        addEdge(i+components,i,inf); // left side use more than once
    }

   // cout<<"ok"<<endl;

    int ret = maxFlow(source,sink);

    //cout<<"ok"<<endl;

    int ans = components - ret;

    printf(" %d\n",ans);
}



int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int Case, test, u, v, node, edge;

    read(test);

    for(Case = 1; Case<=test; Case++)
    {
        read(node); read(edge);

        for(int i=0;i<node;i++)
        {
            adj[i].clear();

        }

        for(int i=0;i<edge;i++)
        {
            read(u); read(v);
            u--; v--;
            adj[u].pb(v);
        }

        TarjanSCC(node);

      //  cout<<components<<endl;

        printf("Case %d:",Case);

        MakeNewDAG_Graph(node);


    }

    return 0;
}
