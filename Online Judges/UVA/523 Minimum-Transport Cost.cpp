#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 501
#define lld long long int
lld G[Max][Max];
int Next[Max][Max];
lld tax[Max];
#define INF 1e8+7
vector<int> path;


void Floyed_Warshall(int vertex)
{
    for(int i=1;i<=vertex;i++)
    {
        for(int j=1;j<=vertex;j++)
        {
            Next[i][j]=j;
        }
    }

    for(int k=1;k<=vertex;k++)
    {
        for(int i=1;i<=vertex;i++)
        {
            for(int j=1;j<=vertex;j++)
            {
                if(G[i][j]> G[i][k]+G[k][j]+tax[k])
                {
                    G[i][j]=G[i][k]+G[k][j]+tax[k];
                    //cout<<G[i][j]<<endl;
                    Next[i][j]=Next[i][k];
                }
            }
        }
    }

}

void Find_path(int src, int des)
{
    path.clear();
    path.push_back(src);
    while(src!=des)
    {
        src  = Next[src][des];
       // cout<<src<<endl;
        path.push_back(src);
    }

    printf("Path: ");

    for(int i=0;i<path.size();i++)
    {
        if(i>0)
            printf("-->");
        printf("%d",path[i]);
    }
    printf("\n");

    return ;
}


int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test;
    lld w;
    char ch,str[100];
    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        int cnt=1;
        while(1)
        {
            scanf("%lld",&w);
            if(w==-1)
                G[1][cnt]=INF;
            else
                G[1][cnt]=w;
            scanf("%c",&ch);
            if(ch=='\n')
                break;
            cnt++;
        }

        for(int i=2;i<=cnt;i++)
        {
            for(int j=1;j<=cnt;j++)
            {
                scanf("%lld",&w);
                if(w==-1)
                    G[i][j]=INF;
                else
                    G[i][j]=w;

            }
        }
        for(int i=1;i<=cnt;i++)
            scanf("%lld",&tax[i]);
        ch = getchar();


        Floyed_Warshall(cnt);

        if(Case>1)
            printf("\n");

        //cout<<"OK"<<endl;

        int st,des;

        bool flag=0;

        while(gets(str))
        {
            //cout<<"OK2"<<endl;
            if(strlen(str)==0)
                break;
            int i,st=0,des=0;
            for(i=0;i<strlen(str);i++)
            {
                if(str[i]==' ')
                    break;
                st = st*10+str[i]-'0';
            }
            for(i=i+1;i<strlen(str);i++)
            {
                if(str[i]==' ')
                    break;
                des = des*10+str[i]-'0';
            }

            if(flag)
                printf("\n");

            //cout<<st<<" "<<des<<endl;
            printf("From %d to %d :\n",st,des);
            Find_path(st,des);
            printf("Total cost : %lld\n",G[st][des]);
            flag=1;
        }


    }

    return 0;
}
