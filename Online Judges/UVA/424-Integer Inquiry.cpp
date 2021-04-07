#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char sum[10000];


void addString(char *str1)
{
    int len1=strlen(str1);
    int len2=strlen(sum);
    int l_low,l_high;

    if(len1<=len2)
    {
        l_low=len1;
        l_high=len2;

    }
    else
    {
        l_low=len2;
        l_high=len1;
    }



    int temp=0;

    for(int i=1;i<=l_low;i++)
    {
        temp=((str1[len1-i]-'0')+(sum[len2-i])-'0')+temp;
      //  cout<<temp<<endl;
        sum[(l_high+1)-i]=(temp%10)+'0';
       // cout<<sum[i]<<endl;
        temp=temp/10;

    }

   // cout<<sum[2]<<endl;

    if(l_low==len1)
    {
        //cout<<"in if: "<<sum<<endl;
        int k;
        for(k=len2-len1-1;k>=0;k--)
        {
            temp=sum[k]-'0'+temp;
            sum[k+1]=(temp%10)+'0';
            temp=temp/10;
        }

        if(temp>0)
        {
            sum[k+1]=temp+'0';
        }
        else
            sum[k+1]='0';

        sum[len2+1]='\0';
    }



    else if(l_low==len2)
    {
       // cout<<"in else: "<<sum<<endl;
        int k;
        for(k=len1-len2-1;k>=0;k--)
        {
            temp=str1[k]-'0'+temp;
            sum[k+1]=(temp%10)+'0';
            temp=temp/10;
        }

        if(temp>0)
        {
            sum[k+1]=temp+'0';
        }
        else
            sum[k+1]='0';
        sum[len1+1]='\0';
    }
    //cout<<sum<<endl;
}


int main()
{
    int test;

    char str1[500];
    //char str2[500];
    int m=1;


    //char ch=getchar();

    while(gets(str1))
    {
        if(str1[0]=='0'&&strlen(str1)==1)
            break;
        else if(m==1)
        {
            strcpy(sum,str1);
            m++;
        }

        else
            addString(str1);
       //   cout<<sum<<endl;
    }

    //cout<<sum<<endl;

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

    return 0;
}
