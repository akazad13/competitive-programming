#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#define inf 100000000
#define mp make_pair
///V*E  Complexity
///Base doesn't matter

const int MAXN = 20010;///total nodes
const int MAXM = 60010;///total edges
struct node{
	int u,v;
	int flow,cap,cost,next;
}edge[MAXM];
int tot;
queue<int> Q;
int dis[MAXN];
int pre[MAXN];
int head[MAXN];
int cnt[MAXN];
bool vis[MAXN];

void add(int u,int v,int cap,int cost)
{
   // printf("%2d %2d   %10d %5d\n",u,v,cap,cost);
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].cap = cap;
	edge[tot].cost = cost;
	edge[tot].flow = 0;
	edge[tot].next = head[u];
	head[u]=tot++;

	edge[tot].u = v;
	edge[tot].v = u;
	edge[tot].cap = 0;
	edge[tot].cost = -cost;
	edge[tot].flow = 0;
	edge[tot].next = head[v];
	head[v] = tot++;
}
pair<int,int> SPFA(int source,int sink,int N)
{
    int totFlow=0,totCost=0,i;
    while(!Q.empty())
	Q.pop();
	//cout<<"tot "<<tot<<endl;
    while(1)
    {
    	memset(vis,0,sizeof vis);
    	for(i=0;i<=N;i++)
    	dis[i] = inf;

    	dis[source] = 0;
    	Q.push(source);
    	pre[source] = -1;
    	while(!Q.empty())
    	{
    		int x = Q.front();
    		//cout<<"x "<<x<<endl;
    		Q.pop();
    		vis[x] = 0;
    		for(int h=head[x];h!=-1;h=edge[h].next)
    		{
    			int v = edge[h].v;
    		//	cout<<"v : "<<v<<endl;
    			//cout<<dis[x]+edge[h].cost<<" v "<<v<<" "<<dis[v]<<" "<<h<<endl;
    			if(edge[h].cap>edge[h].flow and dis[x] + edge[h].cost<dis[v])
    			{
    			//    cout<<v<<endl;


    				dis[v] = dis[x] + edge[h].cost;
    				pre[v] = h;
                 //   cout<<dis[x]+edge[h].cost<<" "<<dis[v]<<" "<<v<<endl;
    				if(!vis[v])
    				{
    			//	   cout<<v<<endl;
    					Q.push(v);
    					vis[v] = 1;
					}
				}
			}
		}
		//cout<<"ok"<<" "<<dis[sink]<<" "<<sink<<" "<<N<<endl;
		if(dis[sink]==inf)
		break;

		int aa = inf;
		for(int h=pre[sink];h!=-1;h=pre[edge[h].u])
		{
			aa = min(aa,edge[h].cap-edge[h].flow);
		}
		for(int h=pre[sink];h!=-1;h=pre[edge[h].u])
		{
			edge[h].flow+=aa;
			edge[h^1].flow -=aa;
		}
		//cout<<aa<<" "<<dis[sink]<<endl;
		totFlow +=aa;
		totCost += (aa)*dis[sink];
	}
    return mp(totFlow,totCost);
}
pair<int,int>res;

int arr[101][101];
int n,m;

map< pair<int,int> ,int> Map;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    int tcase,t,n,source,sink,i,u,v,q,num;
    scanf("%d",&tcase);
    for(t=1;t<=tcase;t++)
    {
        Map.clear();
        int cnt=0;

        scanf("%d %d",&n,&m);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&arr[i][j]);
                Map[mp(i,j)]=cnt++;
            }
        }

        tot  = 0;
        memset(head,-1,sizeof head);
        source = 2*cnt;
    	sink = 2*cnt+1;

    	//cout<<" u  v       flow    cost"<<endl;
    	//cout<<"--------------------------"<<endl;
    	//cout<<endl;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                u = Map[mp(i,j)];
                if(j+1<m)
                {
                    v = Map[mp(i,j+1)];
                    add(u+cnt,v,inf,0);

                }

                if(i+1<n)
                {
                    v = Map[mp(i+1,j)];

                    add(u+cnt,v,inf,0);
                }

                if(u==0 || u==cnt-1)
                {
                    add(u,u+cnt,2,-1*arr[i][j]);
                }
                else
                {
                    add(u,u+cnt,1,-1*arr[i][j]);
                }




            }
        }


        add(source,Map[mp(0,0)],2,0);
        add(Map[mp(n-1,m-1)]+cnt,sink,2,0);

    	res = SPFA(source,sink,sink);
    	res.second=-1*res.second;
    	//cout<<res.first<<" "<<res.second<<endl;
    	printf("Case %d: %d\n",t,res.second-arr[0][0]-arr[n-1][m-1]);
		tot = 0;
	}


    return 0;
}
