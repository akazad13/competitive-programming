#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
char str[50010][55];
int arr[50010];

int Map[26]={0};

struct node
{
    bool endmark;
    node *next[4];
    ll cnt;

    node()
    {
        for(int i=0;i<4;i++)
            next[i]=NULL;
        endmark=false;
        cnt=0;
    }

    ~node()
    {
        for(int i=0;i<4;i++)
        {
            if(next[i]!=NULL)
                delete(next[i]);
        }
    }
};

void insert_trie(int i, node *curr)
{
    for(int j=0;j<arr[i];j++)
    {
        int id=Map[str[i][j]-'A'];

        if(curr->next[id]==NULL)
            curr->next[id]=new node();

        curr=curr->next[id];
        curr->cnt++;

    }

    curr->endmark=true;
}

ll cnt=0;

void search_trie(node *curr, int i)
{
    for(int k = 0 ; k<4 ;k++)
    {
        if(curr->next[k]!=NULL)
        {

            cnt = max(cnt,(curr->next[k]->cnt * i));

            //cout<<cnt<<" "<<i<<endl;

            search_trie(curr->next[k], i+1);
        }
    }

    return ;
}


int main()
{
   // freopen("out.txt","w",stdout);

   int test, Case, n,m;

   Map[0]=0;
   Map['C'-'A']=1;
   Map['G'-'A']=2;
   Map['T'-'A']=3;

   scanf("%d",&test);

   for(Case = 1; Case<=test; Case++)
   {
       cnt=0;
        scanf("%d",&n);
        char ch = getchar();

        for(int i= 0;i<n; i++)
        {
           scanf("%s",&str[i]);

           arr[i] = strlen(str[i]);
        }

        node *root=new node();

        for(int i=0;i<n;i++)
        {
            insert_trie(i, root);
        }

        search_trie(root,1);

        delete root;

        printf("Case %d: %lld\n",Case ,cnt);
    }

    return 0;
}


