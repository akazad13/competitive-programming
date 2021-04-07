#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define PA pair<int,int>
#define MP(a,b) make_pair(a,b)
#define Max 110
#define read(a) scanf("%d",&a)
#define Clear(a,b) memset(a,b,sizeof(a))

int d[Max];
int step_cost[Max];
int cnt;
map<string,int> Map;

struct node
{
    int u,v,w;
    node(int a, int b, int c)
    {
        u=a;v=b;w=c;
    }
};

vector< node > G;

int mapping(string str)
{
    if(Map[str]==0)
    {
        Map[str]=cnt;
        cnt++;
    }
    return Map[str];
}


void belmon_ford(int src,int N,int des,int edge)
{
    int u,v,w;
    Clear(d,63);
    d[src]=0;
    bool Neg_cycle = false;
    bool update;

    for(int step=1;step<=N;step++)
    {
        for(int i=0;i<edge;i++)
        {
            u = G[i].u; v = G[i].v; w = G[i].w;
            if(d[v]>d[u]+w)
            {

                d[v]=d[u]+w;

            }
        }

        step_cost[step-1] = d[des];
    }


}

bool cmp(node a, node b)
{
    if(a.v>b.v)
        return true;
    else if(a.v==b.v)
    {
        return a.u<b.u;
    }
    return false;
}


int main()
{
    //freopen("1.txt","r",stdin);
    char str[30],str2[30],ch;
    int test,p;
    int u,v,w,vertex,edge,src,des,q,stop;
    read(test);

    for(int Case =1 ;Case<=test; Case++)
    {
        Map.clear();
        G.clear();
        cnt=1;
        read(vertex);
        ch = getchar();

        for(int i=0;i<vertex;i++)
        {
            scanf("%s",str);
            p = mapping(str);
           // cout<<p<<endl;
        }
         read(edge);
         ch = getchar();

        for(int i=0;i<edge;i++)
        {
            scanf("%s %s %d",str,str2,&w);
            u = mapping(str);
            v = mapping(str2);
            G.push_back(node(u,v,w));
        }

        sort(G.begin(),G.end(),cmp);
        Clear(step_cost,63);

        belmon_ford(1,vertex,vertex,edge);

        if(Case>1)
            printf("\n");

        printf("Scenario #%d\n",Case);

        read(q);


        for(int i=0;i<q;i++)
        {
            read(stop);
            if(stop>=vertex)
            {
                if(step_cost[vertex-1]!=d[0])
                    printf("Total cost of flight(s) is $%d\n",step_cost[vertex-1]);
                else
                    printf("No satisfactory flights\n");
            }

            else if(step_cost[stop]==d[0])
                printf("No satisfactory flights\n");
            else
                printf("Total cost of flight(s) is $%d\n",step_cost[stop]);
        }


    }




    return 0;
}

