#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define read(a) scanf("%d",&a)
#define write(a) printf("%d\n",a)
#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 10010
vector<int> G[Max];
int color[Max];

void DFS_visit(int u)
{
   // cout<<u<<endl;
   color[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if(color[v]==0)
        {
           // color[v]=1;
          //  cout<<v<<endl;
            DFS_visit(v);
        }
    }
    color[u]=2;
    return ;
}

void DFS(int start)
{
    DFS_visit(start);
    return ;
}

int main()
{
   // fread(in);
    //fwrite(out);
    //freopen("in.txt","r",stdin);

    int n;
    int u,v,q,e,st,test;
   // vector<int> vec;
    int cnt;
    read(test);

    while(test--)
    {
        scanf("%d %d %d",&n,&e,&q);
        for(int i=0;i<=n;i++)
            G[i].clear();
        cnt=0;
        Clear(color,0);

        while(e--)
        {
            read(u);read(v);

            G[u].push_back(v);

        }

        for(int i=0;i<q;i++)
        {
            read(st);
            DFS(st);


        }
        for(int j=1;j<=n;j++)
        {
                //cout<<color[j]<<endl;
            if(color[j]!=0)
            {
                cnt++;
            }
        }
        write(cnt);
    }

    return 0;

}

