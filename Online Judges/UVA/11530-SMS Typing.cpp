#include<stdio.h>
#include<string.h>
int main()
{
    char m[100];
    int T;
    int count,i,j,l;
    while(scanf("%d",&T)==1)
    {
        getchar();
        for(i=1;i<=T;i++)
        {
            gets(m);
            j=0;
            count = 0;
            l=strlen(m);
            for(j=0;j<l;j++)
            {
                if(m[j]=='a' || m[j]=='d' || m[j]=='g' || m[j]=='j' || m[j]=='m' || m[j]=='p' || m[j]=='t' || m[j]=='w' || m[j]==' ')
                    count++;
                else if(m[j]=='b' || m[j]=='e' || m[j]=='h' || m[j]=='k' || m[j]=='n' || m[j]=='q' || m[j]=='u' || m[j]=='x')
                    count = count + 2;
                else if(m[j]=='s' || m[j]=='z')
                    count = count + 4;
                else
                    count = count + 3;
            }
            printf("Case #%d: %d\n",i,count);
        }
    }
    return 0;
}

