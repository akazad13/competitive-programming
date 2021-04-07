#include<stdio.h>
int main()
{
    short int v,t;
    while(scanf("%hd %hd", &v, &t)== 2)
    {

        printf("%d\n", (v*t)+(v*t));
    }

    return 0;
}
