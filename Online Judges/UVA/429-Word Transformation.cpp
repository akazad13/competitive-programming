#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define max 410
int level[max];

void bfs(vector<int>edge[],int src,int desti)
{
	queue<int>Q;
	Q.push(src);
	int visited[max]={0};
	memset(level,0,sizeof(level));
	//int parent[max];
	visited[src]=1;
    level[src]=0;
	while(!Q.empty()&&visited[desti]==0)
	{
		int u=Q.front();
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i];
			if(!visited[v])
			{
				level[v]=level[u]+1;
				//parent[v]=u;
				visited[v]=1;
				Q.push(v);
			}
		}
		Q.pop();
	}
}



int main()
{
   // freopen("429.txt","r",stdin);

    int test;
    char word[15];
    string dic[210];

    cin>>test;
    char ch = getchar();
     ch=getchar();
     int n=0;

    while(test--)
    {
        map<string,int>myMap;
        vector<int>edge[400];

        int i=0;
        while(gets(word))
        {
            if(strcmp(word,"*")==0)
                break;

            if(myMap[word]==0)
            {
                myMap[word]=i;
            }
            dic[i++]=word;
        }

        for(int j=0;j<i;j++)
        {
            int len1 = dic[j].size();
            for(int k=0;k<i;k++)
            {

                if(dic[j]!=dic[k])
                {
                    int len2 =dic[k].size();
                    if(len1==len2)
                    {
                        int diff=0;
                        for(int m=0;m<len1;m++)
                        {
                            if(dic[j][m]!=dic[k][m])
                                diff++;
                        }

                        if(diff==1)
                        {
                            edge[myMap[dic[j]]].push_back(myMap[dic[k]]);
                        }
                    }

                }
            }
        }

        char str[30],st[15],en[15];

       // cout<<word<<endl;

        if(n>0)
            cout<<"\n";

        while(gets(str))
        {
            // cout<<str<<endl;
            int len = strlen(str);
            if(len==0)
                break;

            //scanf(" %s",en);

            int i,j;
            for(i=0;i<len;i++)
            {
                if(str[i]==' ')
                    break;
                st[i]=str[i];
            }
            st[i++]='\0';

            for(j=i;j<len;j++)
            {
                en[j-i] = str[j];
            }
            en[j-i]='\0';

            bfs(edge,myMap[st],myMap[en]);

            printf("%s %s %d\n",st,en,level[myMap[en]]);
        }

        n++;
        // cout<<n<<endl;

    }

    return 0;
}
