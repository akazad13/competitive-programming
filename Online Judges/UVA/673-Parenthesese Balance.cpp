#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;


int main()
{
    char str[130];
    char stck[130];
    int p,i,j,caseno;
    cin>>caseno;
    int n=getchar();
    for(j=1;j<=caseno;j++)
    {
        gets(str);
        p=0;
        int top=0;
        int l=strlen(str);
        if(strcmp(str,"\n")==0)
        {
            p=0;
        }
        if(l==1||l%2!=0)
        {
            p=1;
        }


            for(i=0;i<l;i++)
            {
                if(str[i]=='('||str[i]=='[')
                    {
                         top++;
                         stck[top]=str[i];
                    }
                else if(str[i]==')'&& top!=0 && stck[top]=='(')
                {
                    top--;
                }

                else if(str[i]==']'&& top!=0&&stck[top]=='[')
                {
                    top--;
                }
                else
                {
                      p=1;
                      break;
                }
            }

        if(p==0&&top==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;


}


