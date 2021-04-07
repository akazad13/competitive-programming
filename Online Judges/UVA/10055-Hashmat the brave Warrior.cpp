#include<stdio.h>
int main()
{
    long int a, b, c;
    while(scanf("%ld %ld",&a,&b) == 2)
    {
        c = a-b;
        if(c>0)
            printf("%ld\n",c);
        else
            printf("%ld\n", -(c));
    }
    return 0;
}

