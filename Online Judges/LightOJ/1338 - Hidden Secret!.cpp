#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;

    char ch=getchar();

    for(int i=1;i<=test;i++)
    {
        char str1[200];
        char str2[200];

        gets(str1);
        gets(str2);

        int len1=strlen(str1);
        int len2=strlen(str2);

        int k=0,l=0;

        for(int j=0;j<len1;j++)
        {
            if(isalpha(str1[j]))
            {
                if(str1[j]>='A'&&str1[j]<='Z')
                    str1[k++]=str1[j]+32;
                else
                    str1[k++]=str1[j];
            }

        }
        str1[k]='\0';
        for(int j=0;j<len2;j++)
        {
            if(isalpha(str2[j]))
            {
                if(str2[j]>='A'&&str2[j]<='Z')
                    str2[l++]=str2[j]+32;
                else
                    str2[l++]=str2[j];
            }

        }

        str2[l]='\0';

        if(k!=l)
        {
            cout<<"Case "<<i<<": No\n";
            continue;
        }

        sort(str1,str1+k);
        sort(str2,str2+l);

        if(strcmp(str1,str2)==0)
        {
            cout<<"Case "<<i<<": Yes\n";
        }
        else
        {
            cout<<"Case "<<i<<": No\n";
        }
    }

    return 0;
}
