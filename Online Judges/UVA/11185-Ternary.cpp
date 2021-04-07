#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    long int num;
    string ternary;
    int i,j;

    cin>>num;
    while(num>=0)
    {
        if(num==0)
            printf("0");
        for(i=0;num>0;i++)
        {
            ternary[i]=num%3+48;
            num=num/3;
        }
       // ternary[i]='\0';
        for(j=i-1;j>=0;j--)
        {
            printf("%c",ternary[j]);
        }
        printf("\n");
        cin>>num;
    }
    return 0;
}
