#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
char str[10010];
int len;

int Next[100010][52];
ll End[100010];
int sz;
bool created[100010]={0};

ll res;

int idx(char c)
{
	if(c >= 'a' && c <= 'z')
		return c - 'a'+26;
	else
		return c - 'A';
}

void insert_trie()
{
	int u = 0;
	for(int i = 0; i < len; i++)
	{
		int c = idx(str[i]);
		if(!created[Next[u][c]])
		{
			Next[u][c] = sz++;
			created[Next[u][c]] = 1;
		}
		u = Next[u][c];
	}
	End[u]++;
}
void search_trie(int l)
{
	int u = 0;
	for(int i = 0; i < l; i++)
	{
		int c = idx(str[i]);


		if(!created[Next[u][c]])
        {
            res = 0;
            return ;
        }

        u = Next[u][c];
	}

	res*=End[u];

	return ;
}

int main()
{
 //  freopen("in.txt","r",stdin);

    int kk=0;
    char str1[10010];
    int test, Case, n,m;

    char ch;

    scanf("%d",&test);

    for(Case = 1; Case<=test; Case++)
    {
        memset(Next,0,sizeof(Next));
        memset(created,0,sizeof(created));
        memset(End,0,sizeof(End));
        sz=1;

        scanf("%d",&n);
        ch = getchar();

        for(int i= 0;i<n; i++)
        {
           scanf("%s",&str);

           kk=0;

           len = strlen(str);

           for(int j=0;j<len;j++)
           {
               if(str[j]==' ')
                 break;
               kk++;
           }

           len = kk;


           if(len>3)
            sort(str+1, str+len-1);

           insert_trie();
        }

        scanf("%d",&m);

        ch = getchar();

        printf("Case %d:\n",Case);

        for(int i=0; i< m ; i++)
        {
            int p=0;
            res=1;
            gets(str1);
            len = strlen(str1);

            str1[len]=' ';
            for(int j=0;j<=len;j++)
            {
                if(res==0) continue ;

                if(str1[j]==' ' && p!=0)
                {
                    str[p]='\0';

                   if(p>3)
                     sort(str+1,str+p-1);
                    search_trie(p);
                    p=0;
                }
                else if(str1[j]!=' ')
                    str[p++] = str1[j];
            }


            printf("%lld\n",res);
        }


    }

    return 0;
}
