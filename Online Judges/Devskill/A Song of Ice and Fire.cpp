//http://www.devskill.com/CodingProblems/ViewProblem/79

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int

#define read(a) scanf("%d",&a)
#define Lread(a) scanf("%lld",&a)
#define Uread(a) scanf("%llu",&a)
#define Dread(a) scanf("%lf",&a)
#define write(a) printf("%d\n",a)
#define Case(a) printf("Case %d: ",a)

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define PR pair<int,int>
#define MP(a,b) make_pair(a,b)

#define Clear(a,b) memset(a,b,sizeof(a))
#define Max 100010


VI G[Max],rev[Max];
int color[Max];
bool visited[Max];
stack<int> stk;
VI component[Max];

void rev_graph(int vertex)
{
    int i,j;
    rep(i,0,vertex+1)
        rev[i].clear();
    rep(i,0,vertex+1)
    {
        rep(j,0,G[i].size())
        {
            int v = G[i][j];
            rev[v].pb(i);
        }

    }
    return ;
}

void DFS_visit(int u)
{
    color[u]=1;
    int i;
    rep(i,0,G[u].size())
    {
        int v = G[u][i];
        if(color[v]==0)
        {
            DFS_visit(v);
        }
    }
    stk.push(u);
    return ;
}

void DFS_visit2(int src, int mark)
{
    component[mark].pb(src);

    visited[src]=1;

    int i,v;
    rep(i,0,rev[src].size())
    {
        v = rev[src][i];
        if(visited[v]==0)
        {
            DFS_visit2(v,mark);
        }
    }
    return ;
}


void FindSCC(int vertex)
{
    //stk.clear();
    Clear(visited,0);
    Clear(color,0);
    int i;

    rep(i,0,vertex+1)
        component[i].clear();



    rep(i,1,vertex+1)
    {
        if(color[i]==0)
        {
            DFS_visit(i);
        }
    }

    rev_graph(vertex);

    int mark=0;
    int u,j;
    while(!stk.empty())
    {
        u = stk.top(); stk.pop();
        if(visited[u]==0)
        {
            mark++;
            DFS_visit2(u,mark);
        }
    }

    vector<int> Size;
    rep(i,1,mark+1)
    {
        Size.push_back(component[i].size());

    }

    sort(Size.begin(),Size.end());

    int sum = 0;

    rep(i,0,mark-1)
        sum+=Size[i];

    if(sum<Size[mark-1])
        printf("Fight the white walkers.\n");
    else
        printf("Doomed.\n");

    return ;
}



int main()
{
    //freopen("in.txt","r",stdin);
    int test;
    int Case,i,j,vertex,u,v,edge;
    read(test);

    char str1[20],str2[20];



    rep(Case,1,test+1)
    {
        char ch = getchar();
        //Map.clear();9
        //cnt=1;
        //read(vertex); read(edge);
        string st;

        getline(cin,st);

        //cout<<st<<endl;
        vertex = 0;
        edge = 0;

        int n=0;

        int ind;

        for(ind=0;ind<st.size();ind++)
        {
            if(st[ind]!=' ')
            {
                n = 10*n+st[ind]-'0';
            }
            else
            {
                break;
            }
        }

        vertex = n;

        n=0;

        for(ind=ind+1;ind<st.size();ind++)
        {
            if(st[ind]!=' ')
            {
               // cout<<n<<endl;
                n = 10*n+st[ind]-'0';
            }
        }



        edge = n;

        map<string, int> Map;
        int cnt=1;

        if(edge==0)
            edge=vertex;
        // cout<<vertex<<" "<<edge<<endl;

        rep(i,0,vertex+1)
            G[i].clear();
        rep(i,0,edge)
        {
            scanf(" %s %s",str1,str2);

           // cout<<str1<<" "<<str2<<endl;

            if(Map[str1]==0)
            {
                Map[str1]=cnt++;
            }

            if(Map[str2]==0)
                Map[str2]=cnt++;

            u = Map[str1];
            v = Map[str2];

           // cout<<u<<" "<<v<<endl;

            G[u].pb(v);


        }

       // printf("Case %d: ",Case);
        FindSCC(vertex);
    }

    return 0;
}
