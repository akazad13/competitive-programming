#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool G[105][105];
int indeg[105], Topsort[105];

void CreatGraph(int node, int edge, map<string,int>vertexMap)
{
    string str, u,v;

    memset(G,0,sizeof(G));
    int len,i,j;
   //cout<<edge<<endl;
    for(int k=0;k<edge;k++)
    {
         getline(cin,str);

        len = str.length();
      //  cout<<str<<endl;

        j=0;

        for(i=0;i<len;i++)
        {
            if(str[i]==' ')
                break;
           u.push_back(str[i]);
            //cout<<str[i]<<endl;
        }

       //cout<<j<<endl;
       // cout<<u<<endl;
        j=0;

        for(i=i+1;i<len;i++)
        {
            v.push_back(str[i]);
        }
     //   cout<<vertexMap[u]<< " "<<vertexMap[v]<<endl;

       // v[j]='\0';


        G[vertexMap[u]][vertexMap[v]]=true;
        u.clear();
        v.clear();
    }

   // cout<<"___________________________________"<<endl;
}

int find_indeg(int m,int n)
{
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(G[i][m])
            res++;
    }

    return res;
}

void DisplayTopsort(int node,map<int,string>revMap)
{
    for(int i=0;i<node;i++)
    {
        cout<<" "<<revMap[Topsort[i]];
    }
    printf(".\n\n");
}

int main()
{
    //freopen("11060.txt","r",stdin);
    int node, edge,k; //node from 1 to n
    string str;
    int cnt=1;
    char ch;

    while(cin>>node)
    {
        cin.ignore();
        //node = ch-'0';
       // cout<<"node : "<<node<<endl;
        map< string , int > vertexMap;
        map<int,string> revMap;

        k=1;

        for(int i=0;i<node;i++)
        {
            getline(cin,str);
            if(vertexMap[str]==0)
            {
                vertexMap[str]=k;
                revMap[k]=str;
                k++;
            }
        }


        priority_queue<int,vector<int>,greater<int>> vertex;
        memset(indeg,0,sizeof(indeg));
        memset(Topsort,-1,sizeof(Topsort));

        scanf("%d",&edge);
        cin.ignore();

        CreatGraph(node,edge,vertexMap);

        for(int i=1;i<=node;i++)
        {
            indeg[i]= find_indeg(i,node);
            if(indeg[i]==0)
            {
                vertex.push(i);
               // cout<<vertex.top()<<endl;
            }
        }

        int j=0;

        while(!vertex.empty())
        {
            int top = vertex.top(); vertex.pop();

            Topsort[j++]=top;

            for(int i=1;i<=node ;i++)
            {
                if(G[top][i])
                {
                    G[top][i]=false;
                    indeg[i]--;
                    if(indeg[i]==0)
                    {
                        vertex.push(i);
                    }
                }
            }

        }

        printf("Case #%d: Dilbert should drink beverages in this order:",cnt++);

        DisplayTopsort(node,revMap);

    }

    return 0;
}


