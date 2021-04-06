#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   int test;
   cin>>test;

   for(int i=1;i<=test;i++)
   {
       char ch=getchar();
        char str[250];
        long long int div;
        cin>>str;
        cin>>div;

        int len=strlen(str);
        long long int rem=0;

        for(int i=0;i<len;i++)
        {
            if(str[i]=='-')
                continue;
            rem=(rem*10+(str[i]-'0'))%div;
        }
        if(rem%div==0)
            cout<<"Case "<<i<<": divisible\n";
        else
            cout<<"Case "<<i<<": not divisible\n";
   }
    return 0;
}


