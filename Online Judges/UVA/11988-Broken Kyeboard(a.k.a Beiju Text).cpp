#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    char str[100010];
    while(gets(str))
    {
        list<char> mylist;

        list<char> :: iterator it;

        int len=strlen(str);
        it=mylist.begin();
        for(int i=0;i<len;i++)
        {

            if(str[i]=='[')
            {
                it=mylist.begin();
                continue;
            }

            else if(str[i]==']')
            {
                it=mylist.end();
                continue;
            }

            mylist.insert(it,str[i]);
           // it++;
        }

        for(it=mylist.begin();it!=mylist.end();it++)
        {
            cout<<*it;
        }
        cout<<"\n";

        mylist.clear();
    }

    return 0;
}
