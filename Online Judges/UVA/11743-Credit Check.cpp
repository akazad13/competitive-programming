#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int digitSum(int n)
{
    return ((n/10)+(n%10));
}

int main()
{
    int test;
    cin>>test;
    char ch=getchar();

    while(test--)
    {
        char str[20];
        gets(str);
        int len=strlen(str);
        int l=0;

        for(int i=0;i<len;i++)
        {
            if(str[i]>='0'&&str[i]<='9')
                str[l++]=str[i];
        }

        str[l]='\0';

        int sum_not=0;
        int sum=0;

        for(int k=0;k<l;k++)
        {
            if(k%2==1)
            {
                sum_not+=(str[k]-'0');
            }
            else
            {
                sum+= digitSum(2*(int)(str[k]-'0'));
            }
        }

        sum+=sum_not;
        if(sum%10==0)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }
    return 0;
}
