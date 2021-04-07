#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char res[100000];

void addString(char *pro)
{
    int len1=strlen(res);
    int len2=strlen(pro);
    int l_low,l_high;

   // cout<<len1<<" "<<len2<<endl;

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
        temp=((res[len1-i]-'0')+(pro[len2-i])-'0')+temp;
      //  cout<<temp<<endl;
        res[(l_high+1)-i]=(temp%10)+'0';
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
            temp=pro[k]-'0'+temp;
            res[k+1]=(temp%10)+'0';
            temp=temp/10;
        }

        if(temp>0)
        {
            res[k+1]=temp+'0';
        }
        else
            res[k+1]='0';

        res[len2+1]='\0';
    }



    else if(l_low==len2)
    {
       // cout<<"in else: "<<sum<<endl;
        int k;
        for(k=len1-len2-1;k>=0;k--)
        {
            temp=res[k]-'0'+temp;
            res[k+1]=(temp%10)+'0';
            temp=temp/10;
        }

        if(temp>0)
        {
            res[k+1]=temp+'0';
        }
        else
            res[k+1]='0';
        res[len1+1]='\0';
    }
    //cout<<sum<<endl;
}


int main()
{
    char str1[500];
    char str2[500];

    while(gets(str1))
    {
        gets(str2);

        res[0]='0';
        res[1]='\0';

        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int k=0;

        for(int i=len2-1;i>=0;i--)
        {
            char pro[100000];
            int temp=0;
            int n= str2[i]-'0';
            for(int j=len1-1;j>=0;j--)
            {
                temp = (str1[j]-'0')*n+temp;
                pro[j+1]= temp%10+'0';
                temp/=10;
            }
           // cout<<pro<<endl;

            pro[0]=temp+'0';
            for(int a=0;a<k;a++)
            {
                pro[len1+1+a]='0';
            }
            pro[len1+1+k]='\0';

           // cout<<pro<<endl;
           // cout<<res<<endl;

            addString(pro);

            k++;

        }
        int len=strlen(res);

        int flag=0;

        for(int i=0;i<len;i++)
        {
            if(flag==0&&res[i]=='0')
                continue;
            else
            {
                flag=1;
                printf("%c",res[i]);
            }
        }
        cout<<"\n";
    }
    return 0;
}
