#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    char str[1000000];
    long long int i;
    long long int m;
    char ch;
    while(scanf("%s %c %lld",str,&ch,&m)==3)
    {
        long long int l;
        long long int str2[100000]={0};
        l=strlen(str);




        long long int rem=0;
        for(int i=0;i<l;i++)
        {
            str2[i]=((((str[i]-'0'))+(rem*10))/m);
            rem=(rem*10+(str[i]-'0'))%m;
        }

        if(ch=='/')
        {
            for(i=0;i<l;i++)
            {
                if(str2[i]!=0)
                    break;
            }
            if(i==l)
                printf("0");
            else{
            for(long long int j=i;j<l;j++)
                printf("%lld",str2[j]);

            }
             printf("\n");
        }

        else
            cout<<rem<<endl;
    }
    return 0;
}
