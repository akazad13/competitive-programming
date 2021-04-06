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
    int Max_match=-1;

    while(i<n)
    {
        while(j>=0 && text[i]!=pattern[j])
        {
            j = pre[j];
        }

        i++;
        j++;

        if(i-j>Max_match)
        {
            Max_match = i-j;
        }
    }
    return Max_match;
}

int main()
{
    int test;

    scanf("%d",&test);
    char ch = getchar();

    for(int Case=1;Case<=test;Case++)
    {
        gets(text);

        int n = strlen(text);
        int j=0;

        for(int i=n-1;i>=0;i--)
        {
            pattern[j++] = text[i];
        }

        printf("Case %d: %d\n",Case,n+kmp_search());
    }

    return 0;
}

