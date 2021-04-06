#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char text[1000010];
char pattern[1000010];
int pre[1000010];

void cal(int m)
{
    int i=0, j=-1;

    pre[i]=-1;

    while(i<m)
    {
        while(j>=0 && pattern[i]!=pattern[j])
        {
            j = pre[j];
        }

        i++;
        j++;

        pre[i] = j;
    }
}

int kmp_search()
{
    int n = strlen(text);
    int m = strlen(pattern);

    cal(m);

    int i=0,j=0;
    int cnt=0;

    while(i<n)
    {
        while(j>=0 && text[i]!=pattern[j])
        {
            j = pre[j];
        }

        i++;
        j++;

        if(j==m)
        {
            cnt++;
            j = pre[j];
        }
    }

    return cnt;
}

int main()
{
    int test;

    scanf("%d",&test);
    char ch = getchar();

    for(int Case=1;Case<=test;Case++)
    {
        gets(text);
        gets(pattern);

        printf("Case %d: %d\n",Case,kmp_search());
    }

    return 0;
}

