#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[100000];

    while(gets(str))
    {
        if(str[0]=='0')
            break;
        int num=str[0]-'0';
        int len=strlen(str);

        if(len>1&&len%2==0)
            num=num*10+str[1]-'0';
        len=(len-1)/2;

        num=sqrt(num);

        printf("%d",num);

        for(int i=1;i<=len;i++)
            printf("0");
        printf("\n");
    }

    return 0;
}
