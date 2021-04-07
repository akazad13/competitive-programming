#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{
    char str1[100000];
    char str2[100000];

    int test,i,count,f,len,j,m,p;

    scanf("%d",&test);
    char ch;
    ch=getchar();

    for(m=1;m<=test;m++)
    {
        count=0;
        gets(str1);
        f=1;
        len=strlen(str1);
        j=0;

        for(i=0;i<len;i++)
        {
            if(str1[i]>='a'&&str1[i]<='z')
                {
                    str2[j++]=str1[i];
                    count++;
                }
        }

        str2[j]='\0';
        len=j;

        for(i=0;i<=len/2;i++)
        {
            if(str2[i]!=str2[len-i-1])
            {
                f=0;
                break;
            }
        }

        p=sqrt(count);

        printf("Case #%d:\n",m);

        if(p*p==count&& f==1)
        {
            printf("%d\n",p);
        }
        else
            printf("No magic :(\n");
    }

    return 0;

}


