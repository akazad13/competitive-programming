#include<stdio.h>
int main()
{
    char text;
    int p = 0;

    while(scanf("%c",&text)!=EOF)
    {
        if(text == '"')
        {
            p++;
            if(p%2 == 1)
                printf("``");
            else
                printf("''");
        }
        else
            printf("%c",text);
    }
    return 0;
}
