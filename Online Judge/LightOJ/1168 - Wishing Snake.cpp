#include<iostream>
#include<bits/stdc++.h>

#define ll long long int
#define lim 1010
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

//int subtree[lim];
vector<int> nadj[lim];//new adjcency list after SCC(DAG)
void MakeNewDAG_Graph(int n)
{
    int u,v;
   // cout<<components<<endl;

    for(int i=0; i<components; i++)
    {
        nadj[i].clear();
        col[i]=0;
        //subtree[i]=0;

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
              // cout<<"u: "<<u<<" "<<v<<endl;
                nadj[u].pb(v);
            }
        }
    }
}

bool f;

void dfs(int u)
{
   //9 cout<<u<<endl;
    col[u]=1;

    //subtree[u]=res[u].size();

    int sz = nadj[u].size();
    if(sz>1)
    {
        f=1;
        return ;
    }

    for(int i=0;i<sz;i++)
    {
        int v = nadj[u][i];

        if(col[v]==0)
        {
            dfs(v);
        }
       // subtree[u]+= subtree[v];
    }

    return ;
}

map<int, int> mp;
int node;

int Node(int n)
{
    if(mp[n]==0)
    {
        mp[n]=node;
       // cout<<"node  "<<node<<endl;
        node++;
    }

    return mp[n];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int Case, test, u, v,n,k;

    read(test);

    for(Case = 1; Case<=test; Case++)
    {
        read(n);

        for(int i=0;i<lim;i++)
        {
            adj[i].clear();
            res[i].clear();

        }

        bool flag=0;
        mp.clear();
        mp[0]=1;
        node=2;

        for(int j=0;j<n;j++)
        {
            read(k);

            for(int i=0;i<k;i++)
            {
                read(u); read(v);

                 if(u==0)
                    flag=1;

                u = Node(u) -1;
                v = Node(v) -1;

                adj[u].pb(v);
            }
        }



        if(flag==0)
        {
            printf("Case %d: NO\n",Case);
            continue ;
        }

      //  cout<<flag<<endl;

        TarjanSCC(node-1);
        MakeNewDAG_Graph(node-1);

        f=0;

        dfs(group_id[0]);

        //cout<<group_id[0]<<endl;

        flag=0;

        for(int i=0;i<components;i++)
        {
            if(col[i]==0)
            {
                flag=1;
                break ;
            }
        }


        if(flag || f)
        {
            printf("Case %d: NO\n",Case);
        }
        else
        {
            printf("Case %d: YES\n",Case);
        }

    }

    return 0;
}

