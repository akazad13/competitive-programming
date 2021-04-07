#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define read(a) scanf("%d",&a)
#define write(a) printf("%d",a)
#define Clear(a,b) memset(a,b,sizeof(a))

#define Max 110
vector<int> G[Max];
int color[Max];

void DFS_visit(int u)
{
   // cout<<u<<endl;
    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if(color[v]==0)
        {
            color[v]=1;
          //  cout<<v<<endl;
            DFS_visit(v);
        }
    }
    //color[u]=2;
    return ;
}

void DFS(int start)
{
    Clear(color,0);
    DFS_visit(start);
    return ;
}

int main()
{
   // fread(in);
    //fwrite(out);
   // freopen("in.txt","r",stdin);

    int n;
    int u,v,q,st;
    vector<int> vec;
    int cnt;

    while(read(n)==1)
    {
        if(n==0)
            break;
        for(int i=0;i<=n;i++)
            G[i].clear();

        while(read(u))
        {
            if(u==0)
                break;
            while(read(v))
            {
                if(v==0)
                    break;
                G[u].push_back(v);
            }
        }

        read(q);
        for(int i=0;i<q;i++)
        {
            cnt=0;
            vec.clear();
            read(st);
            DFS(st);
            for(int j=1;j<=n;j++)
            {
                //cout<<color[j]<<endl;
                if(color[j]==0)
                {
                    cnt++;
                    vec.push_back(j);
                }
            }

            write(cnt);
            //cout<<"ok?"<<endl;
            int S = vec.size();
            for(int i=0;i<S;i++)
            {
                printf(" %d",vec[i]);
            }
            printf("\n");
        }
    }

    return 0;

}
