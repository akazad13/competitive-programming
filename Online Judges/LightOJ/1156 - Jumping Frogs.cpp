#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long int
#define inf 2
const int maxnodes = 210;
int nodes, src, dest;
int dist[maxnodes+5], q[maxnodes+5], work[maxnodes+5];

struct Edge {
  int to, rev;
  int f, cap;
};

struct node{
    double x,y;
    int now,cap;
};

ll sm[maxnodes+10];
ll big[maxnodes+10];

vector<Edge> g[maxnodes+5];

// Adds bidirectional edge

void init(int n)
{
    for(int i=1;i<=n;i++)
        g[i].clear();
}
void addEdge(int s, int t, int cap){
  Edge a = {t, g[t].size(), 0, cap}; //for s to t
  Edge b = {s, g[s].size(), 0, 0};  // for t to s
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
  nodes = 210;
  int result = 0;
  while (dinic_bfs()) {
    fill(work, work + nodes, 0);
    while (int delta = dinic_dfs(src, INT_MAX))
    {
        result += delta;
    }
  }
  return result;
}

int main() {

    //freopen("input.txt","r",stdin);
   //freopen("out1.txt","w",stdout);
    int test,n,Case,source,tot;
    ll dis,d;

    char id,buf;

    scanf("%d",&test);

    for(Case = 1; Case<=test;Case++)
    {
        scanf("%d %lld",&n,&dis);

        int small=1;
        int bbig =1;

        for(int i=0;i<n;i++)
        {
            buf = getchar();
            id  = getchar();
            buf = getchar();
            scanf("%lld",&d);
            if(id=='B')
            {
                big[bbig++] = d;
            }
            else
                sm[small++]= d;

        }
        small--;
        bbig--;

      //  cout<<small<<" "<<bbig<<endl;

        ll low = 0;
        ll high = dis+10;

        ll mid;
        ll ans;

        int _src = 2*n+1;
        int _des = 2*n+2;

        int tot = bbig+small;

        while(low<high)
        {
            mid  = (low+high)>>1;

            init(_des+5);

           // cout<<"in Big"<<endl;

            for(int i=1;i<=bbig;i++)
            {
                addEdge(i,tot+i,inf);

             //   cout<<i<<" "<<tot+i<<" "<<inf<<endl;
                if(big[i]<=mid)
                {
                    addEdge(_src,i,inf);
                   // cout<<_src<<" "<<i<<" "<<inf<<endl;
                }

                if(dis-big[i]<=mid)
                {
                    addEdge(tot+i,_des,inf);
                   // cout<<tot+i<<" "<<_des<<" "<<inf<<endl;
                }

                for(int j=i+1;j<=bbig;j++)
                {
                    if(big[j]-big[i]<=mid)
                    {
                        addEdge(tot+i,j,inf);
                        addEdge(tot+j,i,inf);

                       // cout<<tot+i<<" "<<j<<" "<<inf<<endl;
                        //cout<<tot+j<<" "<<i<<" "<<inf<<endl;
                    }

                }
            }

           // cout<<"in small"<<endl;

            for(int i=1;i<=small;i++)
            {
                 addEdge(bbig+i,tot+bbig+i,1);
                // cout<<bbig+i<<" "<<tot+bbig+i<<" "<<1<<endl;

                if(sm[i]<=mid)
                {
                    addEdge(_src,bbig+i,inf);
                   // cout<<_src<<" "<<bbig+i<<" "<<inf<<endl;
                }
                if(dis-sm[i]<=mid)
                {
                    addEdge(tot+bbig+i,_des,inf);
                   // cout<<tot+bbig+i<<" "<<_des<<" "<<inf<<endl;
                }

                for(int j=i+1;j<=small;j++)
                {
                    if(sm[j]-sm[i]<=mid)
                    {
                        addEdge(tot+bbig+i,bbig+j,inf);
                        addEdge(tot+bbig+j,bbig+i,inf);
                       // cout<<tot+bbig+i<<" "<<bbig+j<<" "<<inf<<endl;
                       // cout<<tot+bbig+j<<" "<<bbig+i<<" "<<inf<<endl;

                    }

                }
            }

            //cout<<"in mix"<<endl;

            for(int i=1;i<=bbig;i++)
            {
                for(int j=1;j<=small;j++)
                {
                    if(abs(big[i]-sm[j])<=mid)
                    {
                        addEdge(tot+i,bbig+j,inf);
                        addEdge(tot+bbig+j,i,inf);

                       // cout<<tot+i<<" "<<bbig+j<<" "<<inf<<endl;
                        //cout<<tot+bbig+j<<" "<<i<<" "<<inf<<endl;
                    }
                }
            }

            if(mid>=dis)
                addEdge(_src,_des,inf);

            int ret = maxFlow(_src,_des);

          //  cout<<ret<<" "<<mid<<endl;

            //cout<<"---------------------------------------"<<endl;

            if(ret>=2)
            {
                ans = mid;
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }

        printf("Case %d: %lld\n",Case,ans);

    }
    return 0;
}


