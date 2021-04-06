#include<iostream>
#include<bits/stdc++.h>

#define ll long long int
#define lim 50010
#define Clear(a,b) memset(a,b,sizeof(a))
#define pb push_back

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

vector<int> res[lim];

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
            res[components].pb(now);
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

int subtree[lim];
vector<int> nadj[lim];//new adjcency list after SCC(DAG)
void MakeNewDAG_Graph(int n)
{
    int u,v;
   // cout<<components<<endl;
    for(int i=0; i<components; i++)
    {
        nadj[i].clear();
        col[i]=0;
        subtree[i]=0;

        //cout<<col[i]<<endl;
    }


    for(int i=0;i<n;i++)
    {
        int Size = adj[i].size();;
        for(int j=0;j<Size;j++)
        {
            u=group_id[i];
            v=group_id[adj[i][j]];

            if(u!=v)
            {
              //  cout<<u<<" "<<v<<endl;
                nadj[u].pb(v);
            }
        }
    }
}



void dfs(int u)
{
   // cout<<u<<endl;
    col[u]=1;

    subtree[u]=res[u].size();

    int sz = nadj[u].size();

    for(int i=0;i<sz;i++)
    {
        int v = nadj[u][i];

        if(col[v]==0)
        {
            dfs(v);
        }
        subtree[u]+= subtree[v];
    }

    return ;
}


int main()
{
    int Case, test, u, v, node, edge;

    read(test);

    for(Case = 1; Case<=test; Case++)
    {
        read(node);

        for(int i=0;i<node;i++)
        {
            adj[i].clear();
            res[i].clear();

        }

        for(int i=0;i<node;i++)
        {
            read(u); read(v);

            u--; v--;
            adj[u].pb(v);
        }

        TarjanSCC(node);
        MakeNewDAG_Graph(node);

        for(int i=0;i<components;i++)
        {
           // cout<<col[i]<<endl;
            if(col[i]==0)
            {
                //cout<<i<<endl;
                dfs(i);
            }
        }

        int com=-1;
        int mx = -1;

        for(int i=0;i<components;i++)
        {
           // cout<<subtree[i]<<endl;
            if(subtree[i]>mx)
            {
                com = i;
                mx = subtree[i];
            }
        }

        sort(res[com].begin(),res[com].end());

        printf("Case %d: %d\n",Case,res[com][0]+1);

    }

    return 0;
}

