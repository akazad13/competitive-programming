#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    char a[220];
    char ch;

    int test;
    scanf("%d ",&test);

    for (int k=1;k<=test;k++)
    {
        gets(a);

        printf("Case %d: ",k);

        for(int i=0;a[i]!='\0';)
        {
            int num=0;
            if(isalpha(a[i]))
            {
                ch=a[i];
                i++;
                continue;
            }
            for(;a[i]!='\0';i++)
            {
                if(isdigit(a[i]))
                {
                    num=num*10+a[i]-48;
                }
                else
                    break;
            }
            for(int j=0;j<num;j++)
            {
                printf("%c",ch);
            }

        }
        printf("\n");
    }

    return 0;
}
