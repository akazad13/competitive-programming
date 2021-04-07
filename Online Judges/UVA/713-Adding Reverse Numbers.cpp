#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    char str1[300];
    char str2[300];
    char sum[300];

    cin>>test;

    while(test--)
    {
        scanf(" %s %s",str1,str2);
        int len1=strlen(str1);
        int len2=strlen(str2);

        int l;

        if(len1>=len2)
            l=len2;
        else
            l=len1;

        int temp=0,i;

        for(i=0;i<l;i++)
        {
            temp=(str1[i]-'0')+(str2[i]-'0')+temp;
            sum[i]=temp%10+'0';
            temp=temp/10;
        }

        int k;

        if(l==len1)
        {
            for(k=i;k<len2;k++)
            {
                temp=str2[k]-'0'+temp;
                sum[k]=temp%10+'0';
                temp=temp/10;
            }
        }

        else if(l==len2)
        {
            for(k=i;k<len1;k++)
            {
                temp=str1[k]-'0'+temp;
                sum[k]=temp%10+'0';
                temp=temp/10;
            }
        }

        if(temp>0)
            sum[k++]=temp+'0';
        sum[k]='\0';

        int len=strlen(sum);

        int flag=0;

        for(int i=0;i<len;i++)
        {
            if(flag==0&&sum[i]=='0')
                continue;
            else
            {
                flag=1;
                printf("%c",sum[i]);
            }
        }

        cout<<"\n";


    }

    return 0;
}
