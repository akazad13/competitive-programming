#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    bool endmark;
    bool trace;
    node *next[10];

    node()
    {
        for(int i=0;i<10;i++)
            next[i]=NULL;
        endmark=false;
        trace=false;
    }

    ~node()
    {
        for(int i=0;i<10;i++)
        {
            if(next[i]!=NULL)
                delete(next[i]);
        }
    }
};

bool yes;

void insert_str(string str, node *cur)
{
    if(!yes)
       return ;

    int len = str.size();

    for(int i=0;i<len;i++)
    {
        cur->trace=true;
        int now = str[i]-'0';

        if(cur->next[now]==NULL)
            cur->next[now] = new node();
        cur = cur->next[now];

        if(cur->endmark)
        {
            yes = false;
            return ;
        }
    }

    if(cur->trace)
        yes = false;
    cur->endmark = yes;
    return ;

}

int main()
{
    int test,n;

    char str[11];
    scanf("%d",&test);

    for(int Case=1;Case<=test;Case++)
    {
        scanf("%d",&n);
        node *root=new node();
        char ch = getchar();

        yes = true;

        for(int i=0;i<n;i++)
        {
            gets(str);
            insert_str(str,root);
        }

        delete root;

        printf("Case %d: ",Case);

        if(yes)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

