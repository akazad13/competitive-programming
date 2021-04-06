/*1407 - Explosion

type 1 :  X v  Y    !X -> Y , !Y->X
type 2 :  X v !Y    !X ->!Y , Y -> X
type 3 : !X v !Y    X ->!Y , Y -> !X

type 4 :  X v Y  !X -> Y , !Y->X
        !X v !Y   X ->!Y , Y -> !X

member:
type 1: X v X     !X->X
type 2: !X v !X    X->!X

*/
#include<iostream>
#include<bits/stdc++.h>

#define ll long long int
#define lim  1010
#define Clear(a,b) memset(a,b,sizeof(a))


using namespace std;
//0 based
vector<int> adj[2*lim]; //2*lim for true and false argument(only adj should be cleared)
int col[2*lim],low[2*lim],desc[2*lim],timer;
int group_id[2*lim],components;//components=number of components, group_id = which node belongs to which node
stack<int>S;

int mem[5][4],k;

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

vector<int> res;

//double nodes needed normally
bool TwoSAT(int n) //n=nodes (some change may be required here)
{
    TarjanSCC(n);

    res.clear();

    int i;
    for(i=0;i<n;i+=2)
    {
        //cout<<group_id[i]<<" "<<group_id[i+1]<<endl;
        if(group_id[i]==group_id[i+1])
        {
            return 0;
        }
        if(group_id[i]<group_id[i+1]) //Checking who is lower in Topological sort
        {
            res.push_back(i/2 + 1);
        }
    }
    return 1;
}

void add(int ina,int inb)
{
    adj[ina].push_back(inb);
}


void initialize(int n)
{
    for(int i=0;i<n;i++)
        adj[i].clear();
}

int complement(int n)
{
    if(n%2) return n-1;
    return n+1;
}

bool solve(int ind, int n)
{
    if(ind==k) return TwoSAT(n);

    if(mem[ind][0]==1)
    {
        int p,q;
        for(int i=1;i<4;i++)
        {
            p = 2*mem[ind][i]+1 -2;

            add(p,complement(p));

            if(TwoSAT(n))
            {
                return solve(ind+1,n);
            }

            adj[p].pop_back();
        }
    }
    else
    {
        int p,q;
        for(int i=1;i<4;i++)
        {
            p = 2*mem[ind][i] -2;

            add(p,complement(p));

            if(TwoSAT(n))
            {
                return solve(ind+1,n);
            }

            adj[p].pop_back();
        }
    }

    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test, n, m,val1,val2,type;
    char ch1,ch2;
    int p,q;

    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        scanf("%d %d %d",&n,&m,&k);

        initialize(2*n);

        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&type,&val1,&val2);

            if(type==1)
            {
                p=2*val1 -2;
                q=2*val2 -2;
            }
            else if(type==2)
            {
                p=2*val1 -2;
                q=2*val2+1 -2;
            }
            else if (type==3)
            {
                p=2*val1+1 -2;
                q=2*val2+1 -2;
            }
            else
            {
                p=2*val1 -2;
                q=2*val2 -2;

                add(complement(p),q);
                add(complement(q),p);

                p=2*val1+1 -2;
                q=2*val2+1 -2;

            }

            add(complement(p),q);
            add(complement(q),p);

        }

        for(int i=0;i<k;i++)
        {
            for(int j=0;j<4;j++)
            {
              scanf("%d",&mem[i][j]);
            }
        }

        printf("Case %d: ",Case);
        bool ret = solve(0,2*n);

        if(ret)
        {
            int ss = res.size();

            printf("Possible %d",ss);

            for(int i=0;i<ss;i++)
            {
                printf(" %d",res[i]);
            }

            printf(".\n");
        }
        else
        {
            printf("Impossible.\n",Case);
        }
    }

    return 0;
}

