#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)

int main()
{
    int test,n;
    char str[10];
    read(test);

    for(int Case = 1;Case<=test;Case++)
    {
        read(n);
        scanf(" %s",str);

        printf("Case %d: ",Case);

        if(strcmp(str,"Alice")==0)
        {
            if(n%3==0 || n%3==2)
                printf("Alice\n");
            else
                printf("Bob\n");
        }
        else
        {
            if(n%3==0)
                printf("Alice\n");
            else
                printf("Bob\n");
        }
    }
    return 0;

}




