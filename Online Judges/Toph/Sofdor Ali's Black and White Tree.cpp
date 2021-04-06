//Bidirectional
//https://toph.ws/p/sofdor-ali-s-black-and-white-tree

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 100010
#define Clear(a,b) memset(a,b,sizeof(a))

vector<int> G[Max]; //Directed graph
int color[Max];
int arr[Max];
int zero[Max];
int one[Max];

void DFS_visit(int u)
{
    //PP = m;
    color[u]=1;

     if(G[u].size()==0)
    {
        if(arr[u]==0)
        {
            zero[u]=1;
        }
        else
            one[u]=1;
        return ;
    }

    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if(color[v]==0)
        {
            //parent[v]=u;
            DFS_visit(v);
            zero[u]+=zero[v];
            one[u]+=one[v];
        }
    }

    if(arr[u]==0)
        zero[u]++;
    else
        one[u]++;




    return ;
}


void DFS(int vertex)
{
    Clear(color,0);
    Clear(zero,0);
    Clear(one,0);
    for(int i=0;i<vertex;i++)
    {
        if(color[i]==0)
        {
            DFS_visit(i);
        }
    }

}


int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,vertex,edge,u,v;
    scanf("%d",&vertex);

   for(int i=0;i<vertex;i++)
   {
       scanf("%d",&arr[i]);
   }
    for(int i=0;i<vertex;i++)
    {

    }
   // for(int i=0;i<=vertex;i++)
      //  G[i].clear();

        for(int i=0;i<vertex-1;i++)
        {
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);


        }


        DFS(vertex);
    int diff;
    int a,b,c;
    int MAX=-60;
   // cout<<"______________"<<endl;
    for(int i=0;i<vertex;i++)
    {
        //cout<<i<<" "<<zero[i]<<" "<<one[i]<<endl;
        diff = zero[i]-one[i];

        if(MAX<diff && diff>=0)
        {
            MAX=diff;
            a=zero[i];
            b=one[i];
        }
    }

    //cout<<a<<" "<<b<<endl;
    int on=0;
    int ze=0;

    for(int i=0;i<vertex;i++)
    {
        if(arr[i])
            on++;
        else
            ze++;
    }

    if(MAX!=-60)
        printf("%d\n",on-b+a);
    else
        printf("%d\n",on-1);

    return 0;
}
