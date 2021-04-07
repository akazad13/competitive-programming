#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;

    char str[1000];
    char c;

    cin>>test;

    c==getchar();

    while(test--)
    {
        gets(str);
        int l=strlen(str);
        if((l==1&&str[0]=='1')||(l==1&&str[0]=='4')||(l==2&&str[0]=='7'&&str[1]=='8'))
            cout<<"+"<<endl;
        else if(str[l-1]=='5'&&str[l-2]=='3')
            cout<<"-"<<endl;
        else if(str[0]=='9'&&str[l-1]=='4')
            cout<<"*"<<endl;
        else if(str[0]=='1'&&str[1]=='9'&&str[2]=='0')
            cout<<"?"<<endl;

    }

    return 0;
}
