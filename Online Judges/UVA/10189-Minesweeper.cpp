#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[120][120];
    int n,m;
    int k=1;
    while(cin>>n>>m,n|m)
    {
        char ch = getchar();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ch  = getchar();
                str[i][j]=ch;
            }
            ch=getchar();
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int count=0;
                if(str[i][j]=='.')
                   {
                        if(str[i-1][j-1]=='*'&& (i-1)>=0&&(i-1)<=(n-1)&& (j-1)>=0&&(j-1)<=(m-1))
                            count++;
                        if(str[i-1][j]=='*' && (i-1)>=0&&(i-1)<=(n-1)&& (j)>=0&&(j)<=(m-1) )
                            count++;
                        if(str[i-1][j+1]=='*'  && (i-1)>=0&&(i-1)<=(n-1)&& (j+1)>=0&&(j+1)<=(m-1))
                            count++;
                        if(str[i][j-1]=='*' && (i)>=0&&(i)<=(n-1)&& (j-1)>=0&&(j-1)<=(m-1))
                            count++;
                        if(str[i][j+1]=='*'  && (i)>=0&&(i)<=(n-1)&& (j+1)>=0&&(j+1)<=(m-1))
                            count++;
                        if(str[i+1][j-1]=='*'  && (i+1)>=0&&(i+1)<=(n-1)&& (j-1)>=0&&(j-1)<=(m-1))
                            count++;
                        if(str[i+1][j]=='*'  && (i+1)>=0&&(i+1)<=(n-1)&& (j)>=0&&(j)<=(m-1))
                            count++;
                        if(str[i+1][j+1]=='*'  && (i+1)>=0&&(i+1)<=(n-1)&& (j+1)>=0&&(j+1)<=(m-1))
                            count++;

                        str[i][j]=count+'0';
                   }
            }
        }

        if(k>1)
            cout<<"\n";

        printf("Field #%d:\n",k);

         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                printf("%c",str[i][j]);
            }
            cout<<"\n";
        }

        k++;

    }

    return 0;
}
