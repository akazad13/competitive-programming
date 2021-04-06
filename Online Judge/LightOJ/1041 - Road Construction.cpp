#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 10010

struct edge
{
    int u,v;
    long long int w;
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};
int par[Max];
vector<edge>e;
int find(int r)
{
   return (par[r]==r) ? r:  find(par[r]);
}

int number_of_Set;
long long int total_cost;

void mst(int n)
{
    sort(e.begin(),e.end());
    number_of_Set=n;
    for(int i=1;i<=n;i++)par[i]=i;

    int count=0;
    total_cost=0;
    for(int i=0;i<(int)e.size();i++)
    {
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            --number_of_Set;
            count++;
            total_cost+=e[i].w;
            if(count==n-1) break;
        }
    }
}

int main()
{
    int ed,w,test;
    string u, v,str;
    map<string,int> VartexMap;
    int no;
    cin>>test;
    for(int Case = 1; Case<=test ; Case++)
    {
        scanf("%d",&ed);
        cin.ignore();
        e.clear();
        VartexMap.clear();

         no=1;
         int len;

        for(int k=0;k<ed;k++)
        {
            getline(cin,str);

            len = str.length();

            int i,j=0;

            for(i=0;i<len;i++)
            {
                if(str[i]==' ')
                    break;
               u.push_back(str[i]);
            }

            j=0;

            for(i=i+1;i<len;i++)
            {
                if(str[i]==' ')
                    break;
                v.push_back(str[i]);
            }

            w=0;

            for(i=i+1;i<len;i++)
            {
                w = 10*w+str[i]-'0';
            }

            if(VartexMap[u]==0)
            {
                VartexMap[u]=no++;
            }
            if(VartexMap[v]==0)
            {
                VartexMap[v]=no++;
            }

            edge data;

            data.u=VartexMap[u];
            data.v=VartexMap[v];
            data.w=w;
            e.push_back(data);

            v.clear();
            u.clear();

        }

        printf("Case %d: ",Case);
        mst(no-1);
        if(number_of_Set>1)
            printf("Impossible\n");
        else
            printf("%lld\n",total_cost);

    }
    return 0;
}
