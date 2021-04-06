#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int Next[50005 * 33][2];
ll End[50005 * 33];
int sz;
bool created[50005 * 33]={0};


// insert p[0], p[1] .. to the trie
//p[i] = from 0 to ith XOR
// to make double xor

void insert_trie(int mask)
{
	int u = 0;
	for(int i = 31; i >= 0; i--)
	{
		int c = (mask >> i) & 1;
		if(!created[Next[u][c]])
		{
			Next[u][c] = sz++;
			created[Next[u][c]] = 1;
		}
		u = Next[u][c];
	}
	End[u]++;
}

int Mini(int mask)
{
	int u = 0,  ans=0;
	for(int i = 31; i >= 0; i--)
	{
		int c = (mask >> i) & 1;
		if(!created[Next[u][c]])
		{
            ans = ans << 1;
            ans++;
            u = Next[u][ c^1 ];
		}
		else
        {
            ans = ans << 1;
            u = Next[u][c];
        }

	}

	return ans;
}

int Maxi(int mask)
{
	int u = 0,  ans=0;
	for(int i = 31; i >= 0; i--)
	{
		int c = ((mask >> i) & 1)^1;
		if(!created[Next[u][c]])
		{
            ans = ans << 1;

            u = Next[u][ c^1 ];
		}
		else
        {
            ans = ans << 1;
            ans++;
            u = Next[u][c];
        }

	}

	return ans;
}

int main()
{
 //  freopen("in.txt","r",stdin);

    int test, Case, n,m;
    int Min, Max,cur;

    scanf("%d",&test);

    for(Case = 1; Case<=test; Case++)
    {
        memset(Next,0,sizeof(Next));
        memset(created,0,sizeof(created));
        memset(End,0,sizeof(End));
        sz=1;

        scanf("%d",&n);

        cur=0;

        insert_trie(0);

        for(int i= 0;i<n; i++)
        {
            scanf("%d",&m);
            if(i==0)
            {
                Min = m;
                Max = m;
            }

            cur = cur^m;

            Min = min(Min, Mini(cur));
            Max = max(Max, Maxi(cur));

            insert_trie(cur);
        }



        printf("Case %d: ",Case);

        printf("%d %d\n",Max, Min);


    }

    return 0;
}
