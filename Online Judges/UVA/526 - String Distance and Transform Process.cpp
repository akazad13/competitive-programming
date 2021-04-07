#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int dp[85][85];

string str1, str2;

int solve(int len1, int len2)
{

    dp[0][0]=0;
    for(int i=1;i<=len1;i++)
        dp[i][0]=i;

    for(int i=1;i<=len2;i++)
        dp[0][i]=i;

    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
    }

   /* for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return dp[len1][len2];

}

void print_sol(int len1, int len2)
{
    int i,j;

    i = len1; j=len2;
    int cnt=1;

    while(i || j)
    {
        if(str1[i-1]==str2[j-1])
        {
            i--;
            j--;
            continue ;
        }
        printf("%d ",cnt++);

        if(i>0 && dp[i][j]==dp[i-1][j]+1)
        {
            printf("Delete %d\n",i);
            str1.erase(i-1,1);
            i--;
        }
        else if(j>0 && dp[i][j]==dp[i][j-1]+1)
        {
            printf("Insert %d,%c\n",i+1,str2[j-1]);
            str1.insert(i,1,str2[j-1]);
            j--;
        }

        else if(i>0 && j>0)
        {
            printf("Replace %d,%c\n",i,str2[j-1]);
            str1[i-1]=str2[j-1];
            i--;j--;
        }

    }

   // cout<<str1<<" "<<str2<<endl;

    return ;

}



int main()
{
    //freopen("out.txt","w",stdout);
    bool flag=0;

    char st[100];

    while(gets(st))
    {
        str1 = st;
        getline(cin,str2);
        int len1 = str1.size();
        int len2 = str2.size();
        int ret = solve(len1, len2);

        if(flag)
            printf("\n");
        flag=1;

        printf("%d\n",ret);

        print_sol(len1,len2);

    }


    return 0;
}

