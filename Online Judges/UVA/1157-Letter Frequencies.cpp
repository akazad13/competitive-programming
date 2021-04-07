#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

int main()
{
    char str[206];
    int test;


    cin>>test;
    char ch=getchar();
    while(test--)
    {
        gets (str);

        int FC[27]={0};
        int max=0;

        int length = strlen(str);

        for(int i=0;i<length;i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
                str[i]=str[i]+32;
        }

        for(int i=0;i<length;i++)
        {
            if(isalpha(str[i]))
            {
                FC[str[i]-'a']++;
            }

        }
       /* for(int i=0;i<26;i++)
        {
            cout<<FC[i]<<endl;
        }*/


        for(int i=0;i<26;i++)
        {
            if(FC[i]>max)
                max=FC[i];
        }

        //cout<<"max: "<<max<<endl;

        for(int i=0;i<26;i++)
        {
            if(max==FC[i])
            {
                printf("%c",i+'a');
            }
        }
        cout<<"\n";
    }
    return 0;
}
